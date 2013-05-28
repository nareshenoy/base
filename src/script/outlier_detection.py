#!/usr/local/bin/python
"""
This script detects outlier entries in an input data file.
Details of the algorithm used to follow. 

Usage outlier_detection.py --filename <filename> --key <comma separated list of fields which constitute the key>
                           --values <comma separated list of fields to run outlier detection on>

"""
# optparse is now deprecated. Development with argparse will continue.
import argparse
from copy import deepcopy
import numpy as np

from tools.files import smart_open

def getopts():
    parser = argparse.ArgumentParser()
    parser.add_argument('--filename',
                        help='name of the file to be processed')
    parser.add_argument('--key',
                        help='comma separated list of key fields')
    parser.add_argument('--values',
                        help='Value fields to evaluate')
    args = parser.parse_args()
    # Must do some basic argument validation here.
    # For example, a field cannot be a part of key and
    # values arguments
    return args

def get_data(filename, key_list, separator):
    with smart_open(filename) as fh:
        # Get the key line
        col_list = fh.readline().split(separator)
        # print col_list
        # This is a dictionary with the data key as its keys
        data_dict = {}
        for line in fh.readlines():
            data_points = line.split(separator)
            #print data_points
            key_values  = ()
            temp_data_dict = {}
            for (key, value) in zip(col_list, data_points):
                #print 'Processing', key, value
                if key in key_list:
                    key_values += (value, )
                else:
                    # This is a data field
                    #print 'Setting ', key, value
                    temp_data_dict[key] = value
            data_dict[key_values] = deepcopy(temp_data_dict)

    return data_dict
def get_outliers_by_median(data, n_sigmas, value_field):
    """
    The mean and standard deviation are not robust estimators
    for identifying outliers. This is because a few errant
    data points may skew these estimators by a large margin.

    Hence, we use the median and the median absolute deviation (MAD)
    as estimators in this method.

    MAD = median(|Xi - median(Xi)|)
    i.e. MAD is the median of the absolute values for deviations
    from the distributions median

    """
    print '===', value_field, '==='
    all_values = map(lambda x: float(data[x][value_field]), data)

    median = np.median(all_values)
    mad    = np.median(map(lambda x: abs(x - median), all_values))

    for k in data:
        val = data[k][value_field]
        zscore = (float(val) - median) / mad
        if abs(zscore) > n_sigmas:
            print 'Key: ', k, 'is more than', n_sigmas,\
                  ' MAD away from median. Value is:', val, 'while MAD is', mad
    
def get_outliers_by_sigmas(data, n_sigmas, value_field):
    """
    This is a univariate method for outlier detection which
    relies on an assumption of an underlying known distribution
    of data.

    This method simply identifies data points which are a 
    specified number of standard deviations away from the mean of
    the distribution.

    """
    print '===', value_field, '==='
    all_values = map(lambda x: float(data[x][value_field]), data)

    # mean of all values
    mu = np.mean(all_values)
    # sigma
    stddev = np.std(all_values)
    for k in data:
        # Get the value
        val    = data[k][value_field]
        zscore = (float(val) - mu) / stddev
        if abs(zscore) > n_sigmas:
            print 'Key: ', k, 'is more than', n_sigmas,\
                  'sigmas away from mean. Value is:', val, 'while sigma is', stddev
def main():
    args             = getopts()
    filename         = args.filename
    SEPARATOR        = ','
    key_list         = args.key.split(SEPARATOR)
    value_field_list = args.values.split(SEPARATOR)

    data = get_data(filename, key_list, SEPARATOR)

    # Outliers based on number of sigmas away from mean
    value_list = args.values.split(SEPARATOR)
    for value_field in value_field_list:
        get_outliers_by_sigmas(data=data, n_sigmas=10, value_field=value_field) 
    # Outliers based on median
    for value_field in value_field_list:
        get_outliers_by_median(data=data, n_sigmas=10, value_field=value_field)

if __name__ == '__main__':
    main()

