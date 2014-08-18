/*

What is the optimal algorithm to find the minimum element given a rotated sorted array of integers?

*/

#include <iostream>
#include <vector>
using namespace std;

#define PRINT(x) cout << #x << " = " << x << endl;

int find_min(vector<int>& arr, int l, int r) {

    int n = r - l + 1;
    PRINT(l);
    PRINT(r);
    if(l - r == 0) {
        return arr[l];
    }
    // Array 1 : l : (l + r) / 2
    // Array 2 : (l + r) / 2 + 1  : r

    if(arr[l] <= arr[ l + n / 2 - 1] and arr[l + n / 2 - 1] >= arr[r]) {
        return find_min(arr, l + n / 2, r);
    }
    return find_min(arr, l, l + n / 2 - 1);
}

int main() {
    int n, tmp;
    cout << "Please enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n;i ++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    int min_ele = find_min(arr, 0, arr.size() - 1);
    cout << "The minimum element is " << min_ele << endl;

    return 0;
}
