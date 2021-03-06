#include <iostream>
#include <fstream>

using namespace std;
int valuearr[15][29];
int a[15][29];

int maximum(int a, int b) {
	if( a > b) return a;
	else return b;
}
int value(int x, int y) {
	if(x < 0 || y < 0) return 0;
	if(x > 14 || y > 28) return 0;
	if(valuearr[x][y] != -1) return valuearr[x][y];
	int result;
	result = maximum(a[x][y] + value(x - 1, y + 1), a[x][y] + value(x - 1, y - 1));
	valuearr[x][y] = result;
	return result;
}

int main () {
	ifstream inp;
	int t;
	inp.open("18.txt");
	int i, j;
	int max = 0;
	for(i = 0;i < 15;i ++) 
		for(j = 0;j < 29;j ++) {
			a[i][j] = -1;
			valuearr[i][j] = -1;
		}
	//inp >> a[0][8];
	for(i = 0;i < 15;i ++) {
		for(j = 14 - i;j <= 14 + i;j += 2) {
			inp >> a[i][j];
			cout << a[i][j] << " ";
			//a[i][j] /= 100;
		}
		cout << endl;
	}
	for(j = 0; j < 29; j ++) {
		t = value(14, j);
		if(t > max) max = t;
	}
	cout << max << endl;
	return 0;
}
