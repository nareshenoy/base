#include <iostream>
#include <vector>

using namespace std;

vector<int>& merge_sort(vector<int>& arr) {

    int n = arr.size();
    if(n == 1) {
        return arr;
    }
    int LHS_LEN = n / 2;
    // Declare two integer vectors, lhs and rhs
    vector<int> lhs, rhs;
    for(int i = 0; i < LHS_LEN; i++) {
        lhs.push_back(arr[i]);
    }
    for(int i = LHS_LEN; i < n; i++) {
        rhs.push_back(arr[i]);
    }

    lhs = merge_sort(lhs);
    rhs = merge_sort(rhs);

    vector<int>::const_iterator lhs_itr = lhs.begin();
    vector<int>::const_iterator rhs_itr = rhs.begin();

    for(vector<int>::iterator i = arr.begin(); i != arr.end(); ++i) {
        if(lhs_itr == lhs.end() && rhs_itr != rhs.end()) {
            *i = *rhs_itr;
            *rhs_itr++;
        }
        else if(lhs_itr != lhs.end() && rhs_itr == rhs.end()) {
            *i = *lhs_itr;
            *lhs_itr++;
        }
        else {
            if(*lhs_itr < *rhs_itr) {
                *i = *lhs_itr;
                lhs_itr++;
            }
            else {
                *i = *rhs_itr;
                rhs_itr++;
            }
        }
    }
    return arr;
}

