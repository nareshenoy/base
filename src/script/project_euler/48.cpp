#include <iostream>

int main() {
	int i, j, k, temp, carry;
	int result[304];
	int term[301];
	for(i = 0;i < 304;i ++) result[i] = 0;
	for(i = 0;i < 301;i ++) term[i] = 0;
	term[300] = 1;
	for(i = 1; i < 1000;i ++) {
		for(k = 0;k < i;k ++) {
			carry = 0;
			for(j = 300;j >=0;j --) {
				temp = term[j] * i + carry;
				term[j] = temp % 10;
				carry = temp / 10;
			}
		}
		/* term contains the term to be added and result contains the intermediate result */
		/* add term to result */
		carry = 0;
		for(j = 303;j >= 3; j --) {
			temp = result[j] + term[j - 3] + carry;
			result[j] = temp % 10;
			carry = temp / 10;
		}
		for(j = 2;j >= 0;j --) {
			temp = result[j] + carry;
			result[j] = temp % 10;
			carry = temp / 10;
		}
		for(j = 0;j < 301;j ++) term[j] = 0;
		term[300] = 1;
	}
	for(i = 294;i <= 303; i ++) cout << result[i];
	cout << endl;
	return 0;
}