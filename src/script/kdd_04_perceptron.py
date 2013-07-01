#!/usr/local/bin/python
"""
This script runs on the datasets for KDD Cup '04. No arguments to be passed.

"""
###########################################
# optparse is now deprecated. Development with argparse will continue.
import argparse
from copy    import deepcopy
from datetime import datetime
import logging
from logging import info
import numpy as np

from data_manipulation.kdd_04 import (get_data,
                                      get_cols_with_outliers,
                                      get_col_outlier_value)
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
                if data_pt not in outlier_value:
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
                if test_val not in get_col_outlier_value(col_num):
                    dist += (mean_val - test_val) ** 2
                # If the data point is an outlier, do not consider it 
                # for distance calculation
            else:
                dist += (mean_val - test_val) ** 2

        if dist < min_dist:
            min_dist  = dist
            min_class = class_id

    return min_class

def get_processed_obs(obs, mean_arr):
    """
    Replaces missing values with the mean value

    """
    cols_with_outliers = get_cols_with_outliers()
    col_num = 0
    obs_arr = []
    #print 'Got array', obs
    for (obs_val, mean_val) in zip(obs, mean_arr):
        new_obs = obs_val
        #print obs_val, mean_val, col_num
        if col_num in cols_with_outliers:
            outlier_value = get_col_outlier_value(col_num)
            #print col_num, new_obs, outlier_value
            if new_obs in outlier_value:
                #print 'Found a match'
                new_obs = mean_val
        col_num = col_num + 1
        obs_arr.append(new_obs)
    #print 'Returning', obs_arr
    return obs_arr

def main():

    getopts()
    # Read the physics dataset
    phy_data = get_data('/Users/nareshs/Documents/projects/base/datasets/phy_train.dat.zip', 'phy_train.dat')
    # Remove all columns with only zero as the value!
    idxs = []
    for class_id in phy_data:
        sum_arr = np.sum(phy_data[class_id], axis=0)
        all_phy_data = np.array(phy_data[class_id])
        for idx, val in enumerate(sum_arr):
            if abs(val) == 0.0:
                idxs.append(idx)
        mean_arr = get_mean_arr(np.array(phy_data[class_id]))
        idx = 0 
        for col in all_phy_data.T:
            if len(np.unique(col)) == 1 or (len(np.unique(col)) == 2 and get_col_outlier_value(idx) in col):
                idxs.append(idx)
            idx = idx + 1 
        idxs = list(set(idxs))
        all_phy_data = np.delete(all_phy_data, idxs, 1)
        phy_data[class_id] = all_phy_data
    

    class_2_mean_arr = {}
    for class_id in phy_data:
        info('Processing data for class: ' + str(class_id))
        np_nd_arr  = phy_data[class_id]
        mean_arr   = get_mean_arr(np_nd_arr)
        class_2_mean_arr[class_id] = mean_arr
    
    # Third method: Perceptron learning algorithm
    # http://en.wikipedia.org/wiki/Perceptron#Learning_algorithm
    # http://page.mi.fu-berlin.de/rojas/neural/chapter/K4.pdf
    # More detailed: http://hagan.okstate.edu/4_Perceptron.pdf
    
    # Initialize the weights array
    w0 = [0.0] * (phy_data['1'][0].shape[0] + 1)
    w = [w0]
    info('Initialized weights array of length ' + str(phy_data['1'][0].shape[0]))

    # Initialize threshold
    gamma = 0.01
    
    # Initialize learning rate
    alpha = 0.1

    all_data = []
    for class_id in phy_data:
        for row in phy_data[class_id]:
            row = [1.0] + list(row)
            all_data.append((class_id, np.array(row)))

    iter_num = 1
    print 'Entering the while loop'
    latest_sum_of_errors = float('inf')
    while True:
        print datetime.now(), ': Iterating over all data. No.:', iter_num
        for row_num, row in enumerate(all_data):
            expected_val = float(row[0])
            
            f_val = sum(w[-1] * row[1])
            f_val = 1 if f_val > 0 else 0
            #print datetime.now(), ': Getting new weights'
            w_new = []
            for idx, x in enumerate(w[-1]):
                w_new.append(x + alpha * (expected_val - f_val) * row[1][idx])
            #print datetime.now(), ': Got new weights'
            w.append(w_new)

        print datetime.now(), 'Done getting weights. Now checking the error'

        # Check the error!
        total_num_obs = len(all_data)
        sum_of_errors = 0.0
        for test_row in all_data:
            expected_val = float(test_row[0])
            f_val        = sum(test_row[1] * w_new)
            f_val        = 1 if f_val > 0 else 0
            sum_of_errors += abs(expected_val - f_val)
        print datetime.now(), ': Got sum of errors: ', sum_of_errors, ' for ', total_num_obs, ' data points'
        avg_error = sum_of_errors / total_num_obs
        
        if avg_error < gamma:
          break
        print 'After processing ', row_num, ' got avg_error', avg_error            
        # Increase the iteration count
        iter_num = iter_num + 1

    cnt = 50001
    for x in phy_test_data:
        for arr in phy_test_data[x]:
            l = len(arr)
            arr = np.delete(np.array(arr).reshape(1, l), idxs, 1)
            val = np.sum(w[-1] * arr)
            print cnt, val
            cnt = cnt + 1

                    

if __name__ == '__main__':
    main()

