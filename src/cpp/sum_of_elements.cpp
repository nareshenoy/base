/*

You are given an array, and a number x. Determines whether or not
there exist two elements in in the input array whose sum is exactly x, efficiently."

*/

#include <iostream>
#include <vector>

using namespace std;

bool naive_check(vector<int>& arr, int sum) {

    // This is a very naive O(n2) solution.
    // Need to make this better
    for(int i = 0;i < arr.size(); i++) {
        for(int j = 0;j < arr.size(); j++) {
            if (i == j) {
                continue;
            }
            if(arr[i] + arr[j] == sum) return true;
        }
    }
    return false;
}

int main() {
    int n, tmp;
    int sum;
    vector<int> arr;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    cout << "Enter the sum of elements to check: ";
    cin >> sum;

    bool is_sum = naive_check(arr, sum);
    if(is_sum) {
        cout << "There exists a pair of elements whose sum is " << sum << endl;
    }
    else {
        cout << "There does not exist a pair of elements whose sum is " << sum << endl;
    }
    return 0;
}
