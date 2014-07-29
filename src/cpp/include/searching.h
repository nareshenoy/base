#include <vector>
using namespace std;

int binary_search(vector<int>& inp_arr, int target, int l_idx, int r_idx) {
    /*

      Search for target in inp_arr between l_idx and r_idx
      (both inclusive). If found, return the index else return -1

      NOTE: inp_arr has to be sorted!

    */

    if(l_idx > r_idx) {
        return - 1;
    }
    // If the search range is of length 1, and the target is 
    // not present in that range, return -1
    if(l_idx == r_idx && inp_arr[l_idx] != target) {
        return -1;
    }

    // Assuming that the array is sorted, we calculate
    // the value of the middle element. If target
    // is less than the middle element, it follows
    // that the target, if it exists, will be found
    // only to the left of the middle element. 
    // Similar logic will be applied if target is greater
    // than the middle element.
    int mid_idx = (l_idx + r_idx) / 2;

    if (inp_arr[mid_idx] == target) {
        return mid_idx;
    }
    else if(inp_arr[mid_idx] < target) {
        return binary_search(inp_arr, target, mid_idx + 1, r_idx);
    }
    else {
        return binary_search(inp_arr, target, l_idx, mid_idx - 1);
    }
}
