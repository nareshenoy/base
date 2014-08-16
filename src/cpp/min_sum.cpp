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

using namespace std;

#define PRINT(a) cout << #a << " = " << a << endl;

void find_top_two(vector<int>& arr, vector<vector<int>::iterator>& it_arr) {
    
    // Erase everything
    it_arr.clear();
    it_arr.push_back(arr.begin());
    it_arr.push_back(arr.begin());

    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it ++) {
        if(*it_arr[0] < *it) {
            it_arr[1] = it_arr[0];
            it_arr[0] = it;
        }
        else {
            if(it_arr[0] == it_arr[1] or *it_arr[1] < *it) {
                it_arr[1] = it;
            }
        }
    }
}
void swap(vector<int>& arr, int idx1, int idx2) {
    int tmp;
    tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}
int min_sum(vector<int>& arr) {
    int ms = 0;
    vector<vector<int>::iterator> top_2;
    while(arr.size() > 1) {
        find_top_two(arr, top_2);
        int diff = *top_2[0] - *top_2[1];
        swap(arr, arr.size() - 1, top_2[0] - arr.begin());
        arr.pop_back();
        swap(arr, arr.size() - 1, top_2[1] - arr.begin());
        arr.pop_back();
        arr.push_back(diff); 
    }
    return arr[0];
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

