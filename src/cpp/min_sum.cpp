/*
Given an array of n positive numbers (n ~ 100000), what is the
algorithmic approach to find the minimum possible sum (>=0)
by using all the numbers in an array?

Example 1:
1 2 2 3 4
Answer : 0 (-1+2-2-3+4)

Example 2:
2 3 4 7 13
Answer: 1 (+2-3-4-7+13)

*/
#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

#define PRINT(a) cout << #a << " = " << a << endl;

int min_sum(vector<int>& arr) {
    // This problem can be modeled as a variation of 
    // the partition problem. We break up arr into
    // two subsets, the difference of whose sums
    // is minimum.

    // Handle special cases
    if(arr.size() == 0) {
        return 0;
    }
    if(arr.size() == 1) {
        return arr[0];
    }

    // First, sort arr [O(nlogn)]
    merge_sort(arr);

    // Now, create two vectors for the two subsets
    vector<int> subset_1, subset_2;
    // Push one element on each subset from the end of 
    // arr (i.e. the two largest elements)
    subset_1.push_back(arr.back());
    arr.pop_back();
    subset_2.push_back(arr.back());
    arr.pop_back();

    // Initialize the sum of elements in each subset
    int subset_1_sum = subset_1.back(), subset_2_sum = subset_2.back();

    int tmp;
    // While there are still elements in arr 
    while(arr.size() > 0) {
        tmp = arr.back();
        arr.pop_back();

        // Check which subset this element should be added to
        // The logic used is: abs(diff(subset_1_sum, subset_2_sum))
        // should be minimum after addition of tmp

        if(abs(subset_1_sum + tmp - subset_2_sum) > abs(subset_1_sum - tmp - subset_2_sum)) {
            // Push on subset 2
            subset_2.push_back(tmp);
            subset_2_sum += tmp;
        }
        else {
            subset_1.push_back(tmp);
            subset_1_sum += tmp;
        }
    }

    return abs(subset_1_sum - subset_2_sum);
}

void take_input(vector<int>& arr) {
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    int tmp;

    for(int i = 0;i < n;i ++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
}
int main() {
    vector<int> arr;
    take_input(arr);
    int ms = min_sum(arr);
    PRINT(ms);
    return 0;
}

