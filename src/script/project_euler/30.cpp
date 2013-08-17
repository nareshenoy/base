#include <iostream>
#include <fstream>
#include <cmath>

int main() {
	int i, j, temp;
	int a, b, c, d, e, f;
	int sum = 0;
	for(i = 10;i < 354295;i ++) {
		temp = i;
		f = temp % 10;
		temp /= 10;
		e = temp % 10;
		temp /= 10;
		d = temp % 10;
		temp /= 10;
		c = temp % 10;
		temp /= 10;
		b = temp % 10;
		temp /= 10;
		a = temp % 10;
		temp /= 10;
		if(i == (pow(a, 5) + pow(b, 5) + pow(c, 5) + pow(d, 5) + pow(e, 5) + pow(f, 5))) {
			cout << i << endl;
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}
