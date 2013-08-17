#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
	signed long long int n = 600851475143;
	int max_factor = 1;
	signed long long int t;
	int i;
//	for(; i <= max_factor;) {

		while(n % 2 == 0) {
			n = n / 2;
			max_factor = 2;
		}
		while(n % 3 == 0) {
			n = n / 3;
			max_factor = 3;
		}
		t = n/2;
		//printf("Signed long long min: %lld max: %lld\n",
        //LLONG_MIN, LLONG_MAX);
//		printf("Size of llu = %d\n", sizeof(unsigned long long int));
		//printf("%lld %lld\n", n, t);

		for(i = 5;i <= t;) {
			if(n == 1) break; 
			while(n % i == 0) {
				n /= i;
				max_factor = i;
				printf("%d is a factor\n", i);
			}
			if(i % 6 == 1) i += 4;
			else if(i % 6 == 5) i += 2;
		}
//	}
	printf("%d\n", max_factor);
	return 0;
}