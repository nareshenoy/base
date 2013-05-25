#!/usr/local/bin/python
"""
This script detects outlier entries in an input data file.
Details of the algorithm used to follow. 

Usage outlier_detection.py --filename <filename> --key <comma separated list of fields which constitute the key>

"""
# optparse is now deprecated. Development with argparse will continue.
import argparse
from copy import deepcopy

from tools.files import smart_open

def getopts():
    parser = argparse.ArgumentParser()
    parser.add_argument('--filename',
                        help='name of the file to be processed')
    parser.add_argument('--key',
                        help='comma separated list of key fields')

    args = parser.parse_args()
    return args

def get_data(filename, separator):
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

def main():
    args      = getopts()
    filename  = args.filename
    SEPARATOR = ','
    key_list  = args.key.split(SEPARATOR)
 
    data = get_data(filename, SEPARATOR)

    # Outliers based on number of sigmas away from mean
    # Outliers based on density based scan

if __name__ == '__main__':
    main()

