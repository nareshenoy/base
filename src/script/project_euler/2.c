#include <stdio.h>

int fibval[20000];

int fibonacci(n) {
	if(n == 0) {
		fibval[0] = 1;
		return 1;
	}
	else if(n == 1) {
		fibval[1] = 1;
		return 1;
	}
	else {
		fibval[n] = fibval[n - 1] + fibval[n - 2];
		return fibval[n];
	}
}

int main() {
	int i = 1, j;
	int sum = 0;

	fibonacci(0);
	//fibonacci(1);

	while(1) {
		j = fibonacci(i);
		if(j > 4000000) break;
		if(j % 2 == 0) sum += j;
		i ++;
	}
	//sum -= j;
	printf("%d %d\n", sum, i);
	return 0;
}