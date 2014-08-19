/*
Given two text strings A of length n and B of length m,
you want to transform A into B with a minimum number of
operations of the following types: delete a character from A,
insert a character into A, or change some character in A into
a new character. The minimal number of such operations required
to transform A into B is called the edit distance between A and B.

*/

#include <iostream>
#include <string>

using namespace std;

#define INSERT_COST 1
#define DELETE_COST 1
#define SUBSTITUTION_COST 1

int lev(string a, string b, int i, int j) {
    if(min(i, j) == 0) {
        return max(i, j);
    }
    int del_cost = lev(a, b, i - 1, j) + DELETE_COST;
    int ins_cost = lev(a, b, i, j - 1) + INSERT_COST;
    int sub_cost = lev(a, b, i - 1, j - 1) + (a[i - 1] == b [j - 1] ? 0 : SUBSTITUTION_COST);
   
    return min(del_cost, min(ins_cost, sub_cost));
}
int main() {
    cout << "Please enter the two strings:" << endl;
    string a, b;
    cin >> a;
    cin >> b;

    int dist = lev(a, b, a.size(), b.size());
    cout << "Cost of converting " << a << " into " << b << " is " << dist << endl;

    return 0;
}
