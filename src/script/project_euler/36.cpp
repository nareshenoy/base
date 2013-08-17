#include <iostream>
#include <cmath>
int power(int a, int b) {
	int res = 1;
	for(int i = 0;i < b;i ++) res *= a;
	return res;
}
int isPalindrome2(int n) {
	int binary[24];
	int i, temp;
	for(i = 0;i < 24; i++) binary[i] = 0;
	temp = n;
	i = 23;
	while(temp != 0) {
		binary[i] = temp % 2;
		i --;
		temp /= 2;
	}
	int num = 23 - i;
	/* Now check if binary[] is palindromic */
	for(i = 0; i < num / 2; i ++) {
		if(binary[23 - num + 1 + i] == binary[23 - i]) continue;
		else return 0;
	}
	return 1;

}
int isPalindrome10(int n) {
	int i;
	int num_digits;
	for(i = 1; i < 7;i ++) {
		if(((n / power(10, i))) == 0) {
			num_digits = i;
			break;
		}
	}
	//cout << n << " " << num_digits << endl;
	for(i = 0; i <= (num_digits / 2); i ++) {
		if((((n / power(10, i))) % 10) == (((n / power(10, num_digits - 1 - i))) % 10)) continue;
		else return 0;
	}
	return 1;
}
int main() {
	int i, j;
	int sum = 0;
	/* No leading zeroes => only odd numbers can be palindromes */
	for(i = 1;i < 1000000;i += 2) {
		if(isPalindrome10(i)) {
			cout << "Base 10" << endl;
			if(isPalindrome2(i)) {
				cout << i << endl;
				sum += i;
			}
		}
	}
	cout << sum;
	return 0;
}