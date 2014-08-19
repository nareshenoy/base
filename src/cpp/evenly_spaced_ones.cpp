/*
Given a arbitrary binary string of length n, find three evenly
spaced ones within the string if they exist.

Write an algorithm which solves this in O(n * log(n)) time. 

*/

#include <iostream>
#include <string>
#include "searching.h"

using namespace std;

#define PRINT(x) cout << #x << " = " << x << endl;

void print_array(vector<int>& arr) {
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void find_ones(string str) {
    // A vector which stores the indices of all the ones
    vector<int> ones;
    for(string::iterator it = str.begin(); it != str.end(); it++) {
        if(*it == '1') {
            ones.push_back(it - str.begin());
        }
    }
    if(ones.size() < 3) {
        cout << "There are no evenly spaced ones in the sequence" << endl;
        return;
    }
    vector<int> one_square;
    one_square.resize(2 * ones.back(), 0);
    // Now the problem is identifying an arithmetic progression 
    // consisting of three elements in 'ones'
    // The below multiplication should ideally be done with FFT
    // so that it can be done in O(nlogn) time.
    for(vector<int>::iterator it1 = ones.begin(); it1 != ones.end(); it1++) {
        for(vector<int>::iterator it2 = ones.begin(); it2 != ones.end(); it2++) {
            one_square[*it1 + *it2] += 1;
        }
    }
    //print_array(one_square); 
    int index_of_midpt = -1;
    for(vector<int>::iterator it = one_square.begin(); it != one_square.end(); it++) {
        if(*it >= 3 and (it - one_square.begin()) % 2 == 0) {
            index_of_midpt = it - one_square.begin();
        }
    }
    //cout << index_of_midpt << endl;

    if(index_of_midpt == -1) {
        cout << "There are no evenly spaced ones in the sequence" << endl;
        return;
    }

    for(vector<int>::iterator it = ones.begin(); it != one_square.end(); it++) {
        // Search for index_of_midpt - *it in ones
        int pt = binary_search(ones, index_of_midpt - *it, 0, ones.size());
        if(pt != -1) {
            cout << "The ones at indices (" << *it << ", " << index_of_midpt / 2 << ", " << index_of_midpt - *it << ")" << " are evenly spaced" << endl;
            break;
        }
    }
    return;
}
int main() {
    string inp;
    cout << "Please enter the binary string: ";
    cin >> inp;

    find_ones(inp);

    return 0;
}
