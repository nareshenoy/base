#include <iostream>

using namespace std;

int main() {
	int a[200];
	int carry = 0, temp, i, j;
	for(i = 0;i < 200;i ++) a[i] = 0;
	a[199] = 1;
	for(i = 2;i <= 100; i ++) {
		carry = 0;
		for(j = 199;j >= 0; j --) {
			temp = a[j] * i + carry;
			a[j] = temp % 10;
			carry = temp / 10;
		}
	}
	int sum = 0;
	for(i = 199; i >= 0; i --) {
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
