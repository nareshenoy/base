#include <iostream>
#include <vector>

using namespace std;

void printarray (vector<int>& arr){
    
    for(vector<int>::const_iterator i = arr.begin(); i !=arr.end(); ++i) {
        cout << *i << " ";
    }

    cout << endl;
}

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

