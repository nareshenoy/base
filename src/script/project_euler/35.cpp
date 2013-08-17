#include <iostream>
#include <cmath>
int power(int a, int b) {
	int res = 1;
	for(int i = 0;i < b;i ++) res *= a;
	return res;
}

int isPrime(int n) {
	for(int i = 2; i * i <=n;i ++) {
		if(n % i == 0) return 0;
	}
	//cout << "Returning 1 for " << n << endl;
	return 1;
}
int numDigits(int n) {
	for(int i = 1;i < 7;i ++) {
		if((n / power(10, i)) == 0) return i;
	}
}
int main() {
	int i, j, k, count = 0, temp, digit;
	for(i = 3;i < 1000000;i += 2) {
		//if(i % 10000 == 0) cout << i << endl;
		//cout << i << endl;
		k = numDigits(i);
		temp = i;
		//cout << k  << " " << i << endl;
		for(j = 0;j < k;j ++) {
			if(isPrime(temp)) {
				/* Permute */
				digit = temp / power(10, k - 1);
				if(digit == 0) break;
				else {
					temp -= digit * power(10, k - 1);
					temp *= 10;
					temp += digit;
				}
			}
			else break;
		}
		if(j == k) {
			//cout << i << " ";
			count ++;
		}
	}
	count ++; // we have not counted 2
	cout << count << endl;
	return 0;
}
