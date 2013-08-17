#include <stdio.h>

int main() {
	int primes[10002];
	int i = 1, n = 3;
	int j;
	primes[1] = 2;
	while(i != 10002) {
		/*Check number for division by all numbers from primes[1] to primes i*/
		for(j = 1;j <= i;j ++) {
			if((n % primes[j]) == 0) break;
		}
		if(j == (i + 1)) {
			i ++;
			primes[i] = n;
			if(i == 10001) break;
			if(i % 100 == 0) printf("%d\n", i);
		}
		n += 2;
	}
	printf("%d %d\n", n, primes[10001]);

	return 0;
}