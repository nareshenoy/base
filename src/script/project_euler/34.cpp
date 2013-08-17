#include <iostream>
#include <cmath>
int fact(int n) {
	int i, retval = 1;
	for(i = 1;i <= n;i ++) retval *= i;
	return retval;
}
int main() {

	int i, sum, sum_num = 0, temp, digit;
	for(i = 10; i <= 254160;i ++) {
		//cout << "hehe" << endl;
		sum = 0;
		temp = i;
		while(temp != 0) {
			digit = temp % 10;
			sum += fact(digit);
			temp /= 10;
		}

		//if(i == 145) cout << sum << endl;
		if(sum == i) {
			sum_num += i;
			cout << i << endl;
		}
	}
	cout << sum_num << endl;
	return 0;
}
