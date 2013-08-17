#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	int a[100][50];
	int sum[52];
	int i, j, carry;
	char b[2];
	ifstream inp;
	inp.open("13.txt");
	b[1] = '\0';
	for(i = 0;i < 100;i ++) {
		for(j = 0;j < 50;j ++) {
			inp >> b[0];
			a[i][j] = atoi(b);
			cout << a[i][j];
		}
		cout << endl;
	}
	carry = 0;
	for(i = 51;i >=2;i --) {
		sum[i] = carry;
		for(j = 0;j < 100;j ++) {
			sum[i] += a[j][i - 2];
		}
		carry = sum[i] / 10;
		sum[i] = sum[i] % 10;
	}
	sum[1] = carry % 10;
	sum[0] = carry / 10;
	cout << sum[0] << sum[1] << sum[2] << sum[3] << sum[4] << sum[5] << sum[6] << sum[7] << sum[8] << sum[9] << sum[10] << sum[11];
	return 0;
}
