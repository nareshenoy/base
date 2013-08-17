#include <stdio.h>

int main() {
	int n = 100;
	int diff = (n * (n + 1) / 2) * (n * (n + 1) / 2) - (n * (n + 1) * (2 * n + 1) / 6);

	printf("%d\n", diff);
	return 0;

}
