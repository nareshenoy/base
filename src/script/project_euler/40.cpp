#include <iostream>
using namespace std;

int power(int a, int b) {
	int res = 1;
	for(int i = 0;i < b;i ++) res *= a;
	return res;
}
int numDigits(int n) {
	int i;
	for (i = 1;i < 7;i ++) {
		if(n / power(10, i) == 0) return i;
	}
}
int NthDigit(int n) {
	int num_digits = 0, i, result;
	int k, temp;
	if(n <= 0) {
		cout << "Negative n... Exiting" << endl;
		exit(0);
	}
	else {
		i = 1;
		while(1) {
			temp = num_digits;
			k = numDigits(i);
			num_digits += k;
			if(temp < n && num_digits >=n) {
				if(num_digits == n) {
					result = i % 10;
					cout << n << " " << result << endl;
					return (result);
				}
				else {
					/* Get the (n - temp)th digit of i 
					   i.e. (k - (n - temp) + 1 )th digit 
					   from the end
					*/
					result = (i / power(10, k - (n - temp))) % 10; 
					cout << n << " " << result << endl;
					return (result);
				}
			}
			else {
				i ++;
			}
		}
	}
	
}

int main() {
	int n = NthDigit(1) * NthDigit(10) * NthDigit(100) * NthDigit(1000) * NthDigit(10000) * NthDigit(100000) * NthDigit(1000000);
	cout << n << endl;
	return 0;
}