"""
Problem statement:

Sort a list of n nodes where each nodes points to the node which 
comes next. This script takes x lines of input (where x = n - 1).
Each line consists of two integers separated by a space.
"1 2" means 2 comes after 1.

"""
import logging

def sort_adj_dict(adj_dict):
    """
    I don't think merge sort is the right way to go here. The input
    does not mention a set order, i.e. 2 may come before 1. If we get two
    pairs (1, 2) and (3, 4), we cannot say if 1 comes before or after 3.

    Algorithm is:
    -------------
    Find the node which is not in the keys, i.e find the last node. Then we
    work backwards from there.

    Space complexity : O(n)
    Time complexity  : O(n)
  
    """ 
    # Due to the implementation of sets in python,
    # membership tests for sets are O(1)
    keys = set(adj_dict.keys())
    vals = set(adj_dict.values())

    last_element = None
    for val in vals:
        if val not in keys:
            last_element = val
            break
    
    if not last_element:
        logging.fatal('There is some problem with the input,\
                       could not decide the last element')
        exit(1)

    # Construct a reverse map from adj_dict
    rev_dict = {}
    for key, val in adj_dict.items():
        rev_dict[val] = key

    sorted_list = [last_element]

    while True:
        try:
            prev_ele = rev_dict[sorted_list[-1]]
        except KeyError:
            break
        sorted_list.append(prev_ele)

    sorted_list.reverse()

    return sorted_list

def get_input():

    adj_dict = {}
    while True:
        inp = raw_input()
        if inp == '-1': break
        fr, to = [int(x) for x in inp.split(' ')]
        if fr in adj_dict:
            logging.fatal(str(fr) + ' is already in the input.')
            exit(1)
        adj_dict[fr] = to

    return adj_dict

def main():
    adj_dict = get_input()
    # Our job is to print the keys in sorted order
    sorted_keys = sort_adj_dict(adj_dict)
    print sorted_keys

if __name__ == '__main__':
    main()

