#include <iostream>
#include <fstream>

int main() {
	int max = 0, prod;
	int a[20][20];
	ifstream inp;
	inp.open("11.txt");
	/*populate array*/
	for(int i = 0; i < 20;i ++) {
		for (int j = 0; j < 20; j ++) {
			inp >> a[i][j];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	/*search horizontally*/
	for(int i = 0; i < 20;i ++) {
		for (int j = 0; j < 17; j ++) {
			prod = a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3];
			if(prod > max) max = prod;
		}
	}
	/*search vertically*/
	for(int j = 0; j < 20;j ++) {
		for (int i = 0; i < 17; i ++) {
			prod = a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j];
			if(prod > max) max = prod;
		}
	}
	/*search diagonally left to right*/
	for(int i = 0; i < 17;i ++) {
		for (int j = 0; j < 17; j ++) {
			prod = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3];
			if(prod > max) max = prod;
		}
	}
	/*search diagonally right to left*/
	for(int i = 0; i < 17;i ++) {
		for (int j = 19; j >= 3; j --) {
			prod = a[i][j] * a[i + 1][j - 1] * a[i + 2][j - 2] * a[i + 3][j - 3];
			if(prod > max) max = prod;
		}
	}
	cout << max << endl;
	return 0;
}
