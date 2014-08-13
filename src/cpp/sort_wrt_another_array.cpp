/*

http://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/

*/
#include <iostream>
#include <vector>
using namespace std;

void sort_wrt_array(vector<int>& a1, vector<int>& a2) {
    return;
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

    sort_wrt_array(a1, a2);

    return 0;
}
