"""
This script implements merge sort.

Input format is space-separated list of integers.

Output is the list in sorted order

"""

def merge(lhs, rhs):
    """
    Merges two sorted arrays into a single sorted array

    """
    l_idx, r_idx = 0, 0
    sorted_arr   = []
    while True:
        # If the pointers have moved past the end, 
        # extend the sorted_arr by the remaining 
        # portion of the other array and exit
        if l_idx == len(lhs):
            sorted_arr.extend(rhs[r_idx:])
            break
        elif r_idx == len(rhs):
            sorted_arr.extend(lhs[l_idx:])
            break

        if lhs[l_idx] < rhs[r_idx]:
            sorted_arr.append(lhs[l_idx])
            l_idx = l_idx + 1
        else:
            sorted_arr.append(rhs[r_idx])
            r_idx = r_idx + 1

    return sorted_arr

def merge_sort(inp_list):
    """
    Implementation of the merge sort algorithm

    """
    n = len(inp_list)
    if n == 1: return inp_list
    # Split the list into two lists
    lhs, rhs = inp_list[:n / 2], inp_list[n / 2:]
    return merge(merge_sort(lhs), merge_sort(rhs))

if __name__ == '__main__':
    inp_list = [int(x) for x in raw_input().split(' ')]
    print merge_sort(inp_list)

