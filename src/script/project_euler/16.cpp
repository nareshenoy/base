#include <iostream>

using namespace std;

int main() {
	int a[302];
	int carry = 0, temp, i, j;
	for(i = 0;i < 302;i ++) a[i] = 0;
	a[301] = 2;
	for(i = 1;i <= 999; i ++) {
		carry = 0;
		for(j = 301;j >= 0; j --) {
			temp = a[j] * 2 + carry;
			a[j] = temp % 10;
			carry = temp / 10;
		}
	}
	int sum = 0;
	for(i = 0; i <= 301; i ++) {
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
