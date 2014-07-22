"""
This script implements quick sort.

Input: Space separated list of integers

Output: Sorted array

"""
from random import randrange

def partition(inp_list, l_idx, r_idx):

    # We choose the r_idx as the pivot element
    # for now
    final_piv_idx = l_idx
    for i in xrange(l_idx, r_idx):
        if inp_list[i] < inp_list[r_idx]:
            inp_list[i], inp_list[final_piv_idx] = inp_list[final_piv_idx], inp_list[i]
            final_piv_idx = final_piv_idx + 1
    inp_list[final_piv_idx], inp_list[r_idx] = inp_list[r_idx], inp_list[final_piv_idx]

    return final_piv_idx
           
def quick_sort(inp_list, l_idx, r_idx):
    """
    Quick sort implementation

    """
    n = len(inp_list)
    if (r_idx - l_idx + 1) in (0, 1): return

    idx_of_pivot = partition(inp_list, l_idx, r_idx)

    quick_sort(inp_list, l_idx, idx_of_pivot - 1)
    quick_sort(inp_list, idx_of_pivot + 1, r_idx)

    return

if __name__ == '__main__':
    inp_list = [int(x) for x in raw_input().split(' ')]
    quick_sort(inp_list, 0, len(inp_list) - 1)
    print inp_list


