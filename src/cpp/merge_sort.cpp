#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

void printarray (vector<int>& arr){
    
    for(vector<int>::const_iterator i = arr.begin(); i !=arr.end(); ++i) {
        cout << *i << " ";
    }

    cout << endl;
}

int main() {
    // n is the number of elements that are going to be input
    int n;
    cout << "Please enter the number of elements in the array: ";
    cin >> n;
    vector<int> input_arr;

    cout << "Please enter " << n << " integers" << endl;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        input_arr.push_back(tmp);
    }
    cout << "Input array: " << endl;
    printarray(input_arr);

    input_arr = merge_sort(input_arr);
    cout << "Sorted array: " << endl;
    printarray(input_arr);
    return 0;
}

