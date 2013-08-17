#include <stdio.h>

int main() {
	int n = 2520 * 11 * 13 * 17 * 19;
	if(n % 16 != 0) n *= 2;
	printf("%d\n", n);
	return 0;
}
