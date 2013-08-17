#include <iostream>
using namespace std;
int digits[10];
int confirmDigits(int n) {
	int k;
	while(n != 0) {
		k = n % 10;
		if(digits[k] == 1) {
			n /= 10;
		}
		else {
			return 0;
		}
	}
	return 1;
}
void getDigits(int n) {
	int k;
	while(n != 0) {
		k = n % 10;
		digits[k] = 1;
		n /= 10;
	}
	return;
}
int main() {
	int i, j;
	for(i = 1;;i ++) {
		for(j = 0;j < 10;j ++) digits[j] = 0;
		getDigits(i);
		if(confirmDigits(2 * i) && confirmDigits(3 * i) && confirmDigits(4 * i) && confirmDigits(5 * i) && confirmDigits(6 * i)) {
			//for(k = 0;k < 10; k++) cout << digits[k] << " ";
			//cout << endl;
			cout << i << endl;
			break;
		}
	}
	return 0;
}
