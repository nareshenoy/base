#include <iostream>
using namespace std;

int main() {
	int primes[160000];
	int i = 1, n = 3;
	int j;
	long long int sum = 2;
	primes[1] = 2;

	while(n < 2000000) {
		/*Check number for division by all numbers from primes[1] to primes i*/
		for(j = 1;j <= i;j ++) {
			if((n % primes[j]) == 0) break;
		}
		if(j == (i + 1)) {
			i ++;
			primes[i] = n;
			sum += n;
			if(i % 1000 == 0) cout << i << " " << n << endl;
		}
		n += 2;
	}
	cout << sum << endl;;

	return 0;
}
