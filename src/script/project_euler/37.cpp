#include <iostream>

using namespace std;
int power(int a, int b) {
	int res = 1;
	for(int i = 0;i < b;i ++) res *= a;
	return res;
}

/*int revI(int n) {
	int i = 1, j;
	int revnum;
	while(1) {
		if(n / power(10, i) == 0) break;
		i ++;
	}

	revnum = 0;
	j = i - 1;
	cout << n << " " << j << endl;
	while(n != 0) {
		revnum += (int)((n % 10) * power(10, j));
		n /= 10;
		j --;
	}
	return revnum;
}
*/
int isPrime(int n) {
	int i;
	if(n == 1) return 0;
	for(i = 2;i * i <= n;i ++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() {
	int i, count = 0, j;
	int sum = 0, k, temp, tempk;
	for(i = 11;count != 11; i += 2) {
		temp = i;
		while(temp != 0) {
			if(isPrime(temp)) {
				temp /= 10;
			}
			else break;
		}
		if(temp == 0) {	
			j = 1;
			while(1) {
				if(i / power(10, j) == 0) break;
				j ++;
			}
			temp = i;
			while(j != 0) {
				if(isPrime(temp % power(10, j - 1))) {
					j --;
				}
				else break;
			}
			if(j == 0) {
				sum += i;
				count ++;
			}
		}

	}
	cout << sum << endl;
	return 0;
}
