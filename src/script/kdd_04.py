#!/usr/local/bin/python
"""
This script runs on the datasets for KDD Cup '04. No arguments to be passed.

"""
###########################################
# optparse is now deprecated. Development with argparse will continue.
import argparse
from copy    import deepcopy
import logging
from logging import info
import numpy as np

from tools.files      import smart_open
from tools.decorators import memoize
###########################################

def getopts():
    parser = argparse.ArgumentParser()
    parser.add_argument('--log_level',
                        help='logging level')

    args = parser.parse_args()

    if args.log_level is not None:
        numeric_level = getattr(logging, args.log_level.upper(), None)
        if not isinstance(numeric_level, int):
            raise ValueError('Invalid log level: %s' % args.log_level)
        logging.basicConfig(level=numeric_level)

def get_data(zip_filename, file_name):
    fh = smart_open(zip_filename)
    data = fh.read(file_name)
    all_data = {}
    for line in data.split('\n'):
        data_in_line = line.split('\t')
        # Remove trailing whitespace
        data_in_line = data_in_line[:-1]
        if not data_in_line:
            continue
        obs_number, class_id, attrs = int(data_in_line[0]), data_in_line[1], data_in_line[2:]
        if class_id in all_data:
            all_data[class_id].append(map(lambda x: float(x), attrs))
        else:
            all_data[class_id] = [map(lambda x: float(x), attrs)]

    return all_data

COL_NUM_2_OUTLIER_VALUE = { 
                                (19, 20, 
                                 21, 43, 
                                 44, 45) : 999.0,
                                (28, 54) : 9999.0
                          } 

@memoize
def get_col_outlier_value(col_num):

    outlier_value = None
    for k in COL_NUM_2_OUTLIER_VALUE:
        if col_num in k:
            outlier_value = COL_NUM_2_OUTLIER_VALUE[k]
            break
    return outlier_value

@memoize
def get_cols_with_outliers():

    cols_with_outliers = []
    for key in COL_NUM_2_OUTLIER_VALUE:
        cols_with_outliers.extend(list(key))

    return cols_with_outliers

def get_mean_arr(np_nd_arr):
    """
    Filter out some numbers as mentioned at 
    http://osmot.cs.cornell.edu/kddcup/datasets.html

    """
    mean_arr = []
    info('Calculating the mean array')
    cols_with_outliers = get_cols_with_outliers()

    for col_num in range(np_nd_arr.shape[1]):
        col_data = np_nd_arr[:,col_num]
        if col_num in cols_with_outliers:
            outlier_value = get_col_outlier_value(col_num)
            if outlier_value is None:
                # Something went wrong
                error('Could not find outlier value for column no. : ' + str(col_num))
                mean_arr.append(0.0)
                continue
            # Handle missing/unavailable data
            num_data_pts = 0.0
            sum_data_pts = 0.0
            for data_pt in col_data:
                if data_pt != outlier_value:
                    sum_data_pts += data_pt
                    num_data_pts += 1.0
            mean_arr.append(sum_data_pts / num_data_pts)
            info('Considered ' + str(num_data_pts) + ' out of ' + str(np_nd_arr.shape[0]) + ' data points for ' + str(col_num))
        else:
            mean_arr.append(col_data.mean())
    return mean_arr

def get_class(class_2_mean_arr, test_arr):

    cols_with_outliers = get_cols_with_outliers()
    min_dist           = float("inf") 
    for class_id in class_2_mean_arr:
        dist = 0.0
        col_num = 0
        for mean_val, test_val in zip(class_2_mean_arr[class_id], test_arr):
            if col_num in cols_with_outliers:
                if test_val != get_col_outlier_value(col_num):
                    dist += (mean_val - test_val) ** 2
                # If the data point is an outlier, do not consider it 
                # for distance calculation
            else:
                dist += (mean_val - test_val) ** 2

        if dist < min_dist:
            min_dist  = dist
            min_class = class_id

    return min_class
    
def main():

    getopts()
    # Read the physics dataset
    phy_data = get_data('/Users/nareshs/Documents/projects/base/datasets/phy_train.dat.zip', 'phy_train.dat')
    class_2_mean_arr = {}
    for class_id in phy_data:
        info('Processing data for class: ' + str(class_id))
        np_nd_arr  = np.array(phy_data[class_id])
        mean_arr   = get_mean_arr(np_nd_arr)
        class_2_mean_arr[class_id] = mean_arr

    # First method: Classify on the basis of distance from the mean.
    # This is a very primitive classifier
    phy_test_data = get_data('/Users/nareshs/Documents/projects/base/datasets/phy_test.dat.zip', 'phy_test.dat')
    cnt = 50001
    for x in phy_test_data:
        for arr in phy_test_data[x]:
            print cnt, get_class(class_2_mean_arr, arr)
            cnt = cnt + 1

    # Second method: Linear regression
    # Simply put, we will be calculating [b1, b2, b3 .. bn] such that
    # for the ith observation:
    # yi = b1 * x1i + b2 * x2i ... + bn * xni
    # where n is the number of distinct attributes
    # More details at: http://en.wikipedia.org/wiki/Regression_analysis
    # Derivation at: http://en.wikipedia.org/wiki/Linear_least_squares_(mathematics)

if __name__ == '__main__':
    main()

