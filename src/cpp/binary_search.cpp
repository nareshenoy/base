/*
    Implements binary search
*/

#include <iostream>
#include <vector>
#include "searching.h"

using namespace std;

int main()
{
    // Number of elements in the array
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    vector<int> inp_arr;
    int tmp;

    for(int i = 0; i < n;i++) {
        cin >> tmp;
        inp_arr.push_back(tmp);
    }

    int target;
    cout << "Enter the integer you want to look for: ";
    cin >> target;

    // Do a binary search for "target" in "input_arr"
    // between indices 0 and n - 1 (both inclusive)
    int idx = binary_search(inp_arr, target, 0, n - 1);

    if(idx == -1) {
        cout << target << " not found in input array" << endl;
    }
    else {
        cout << target << " found at index " << idx << endl;
    }
}

