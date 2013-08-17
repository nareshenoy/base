#include <iostream>

using namespace std;

int main() {
	int i, j;
	int a[1001][1001];
	int right = 1, down = 2, left = 3, up = 4;
	int dir = right;
	a[500][500] = 1;
	int x = 500, y = 500;
	int num = 1;
	for(i = 1; i <= 1000;i ++) {
		if(dir == right) {
			for(j = 1; j <= i; j++) {
				a[x][y + j] = num + 1;
				num ++;
			}
			y = y + i;
			/* Now we go down */
			for(j = 1; j <= i; j++) {
				a[x + j][y] = num + 1;
				num ++;
			}
			x = x + i;
			dir = left;
		}
		else {
			for(j = 1; j <= i; j++) {
				a[x][y - j] = num + 1;
				num ++;
			}
			y = y - i;
			/* Now we go up */
			for(j = 1; j <= i; j++) {
				a[x - j][y] = num + 1;
				num ++;
			}
			x = x - i;
			dir = right;
		}
		cout << i  << " " << x << " " << y << endl;
	}
	cout << "Here" << endl;
	/* Enter the last numbers in the top row */
	for(j = 1; j < 1001; j ++) {
		a[0][j] = num + 1;
		num ++;
	}
	int sum = 0;
	for(i = 0;i < 1001; i ++) {
			sum = sum + a[i][i] + a[i][1000 - i];
	}
	sum -= a[500][500];
	cout << sum << endl;
	return 0;
}