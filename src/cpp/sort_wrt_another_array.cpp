/*

http://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include "sorting.h"

using namespace std;

vector<int>& sort_wrt_array(vector<int>& a1, vector<int>& a2) {
    unordered_map <int, int> num_to_occurrence;
    vector<int> elems_not_in_a2;
    for(int i = 0;i < a1.size(); i++) {
        if(num_to_occurrence.find(a1[i]) == num_to_occurrence.end()) {
            num_to_occurrence[a1[i]] = 1;
        }
        else {
            num_to_occurrence[a1[i]]++;
        }
    }
    int ind = 0;
    for(int i = 0;i < a2.size();i++) {
        if(num_to_occurrence.find(a2[i]) != num_to_occurrence.end()) {
            for(int j = 0;j < num_to_occurrence[a2[i]];j++) {
                a1[ind] = a2[i];
                ind = ind + 1;
            }
            num_to_occurrence.erase(a2[i]);
        }
    }
    // Now all elements left in num_to_occurrence are not present in a2
    // we must sort them 
    for(unordered_map<int, int>::iterator itr = num_to_occurrence.begin(); itr != num_to_occurrence.end(); itr++ ) {
        for(int i = 0;i < itr->second;i++) {
            elems_not_in_a2.push_back(itr->first);
        }
    }
    elems_not_in_a2 = merge_sort(elems_not_in_a2);

    for(int i = 0;i < elems_not_in_a2.size(); i++) {
        a1[ind] = elems_not_in_a2[i];
        ind = ind + 1;
    }
    return a1;
}

int main() {

    int n, k;
    vector<int> a1;
    vector<int> a2;
    int tmp;

    cout << "Enter the number of elements in the first array: ";
    cin >> n;
    for(int i = 0;i < n;i ++) {
        cin >> tmp;
        a1.push_back(tmp);
    }
    cout << "Enter the number of elements in the second array: ";
    cin >> k;
    for(int i = 0;i < k;i ++) {
        cin >> tmp;
        a2.push_back(tmp);
    }

    vector<int> sorted_arr = sort_wrt_array(a1, a2);
    for(int i = 0;i < sorted_arr.size(); i++) {
        cout << sorted_arr[i] << " ";
    }
    cout << endl;
    return 0;
}
