/*
http://www.cseblog.com/2013/08/number-of-paths-in-rectangular-grid.html

Part 1 does not need code. There are a total of (m + n) steps we need
to take. At any point in the path, we just need to decide whether to
go up or right. Choose any m of these to go up and the in the rest 
we go right. So the total number of monotonic paths would be (m + n)C(n)
 
Part 2 is interesting. The code here prints out all paths which are "below"
the line y = x.

*/

#include <iostream>
#include <vector>
using namespace std;

#define UP    'U'
#define RIGHT 'R'

void print_path(vector<char>& path) {
    for(vector<char>::iterator it = path.begin(); it != path.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void print_paths(int m, int n, int i, int j, vector<char>& path, int& num_paths) {
    
    if(i == m and j == n) {
        num_paths++;
        print_path(path);
        return;
    }
    if(i > m or j > n) {
        return;
    }
    // UP path
    if(j + 1 <= i) {
        path.push_back(UP);
        print_paths(m, n, i, j + 1, path, num_paths);
        path.pop_back();
    }
    // RIGHT PATH
    if(i + 1 >= j) {
        path.push_back(RIGHT);
        print_paths(m, n, i + 1, j, path, num_paths);
        path.pop_back();
    }
}

int main() {
    int m, n;
    cout << "Enter the value of m: ";
    cin >> m;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<char> path;
    int num_paths = 0;
    print_paths(m, n, 0, 0, path, num_paths);
    cout << "Total number of paths: " << num_paths << endl;

    return 0;
}
