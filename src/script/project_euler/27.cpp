#include <iostream>

using namespace std;

int isPrime(int k) {

	if(k < 0) k *= -1;

	for(int i = 2; i <= (k / 2); i ++) {
		if(k % i == 0) return 0;
	}
	return 1;
}
int main() {
	int a, b, n, ab;
	int i, j;
	int max = 0, count;
	for(a = -999; (a > -1000 && a < 1000); a ++) {
		for(b = -999; (b > -1000 && b < 1000); b ++) {
			/* Continue only if b is prime */
			if(!isPrime(b)) continue;
			count = 0;
			for(n = 0;;n ++) {
				if(isPrime(n * n + a * n + b)) count ++;
				else {
					if(count > max) {
						max = count;
						ab = a * b;
					}
					break;
				}
			}
		}
		if(a % 100 == 0) cout << a << endl;
	}
	cout << ab << endl;

	return 0;
}
