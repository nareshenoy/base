#include <stdio.h>

int main() {
	int a, b, c;
	for(c = 1; c <= 998; c++) {
		for(b = 1; b < c; b ++) {
			for (a = 1; a < b; a ++) {
				if((a + b + c == 1000) && ((a * a + b * b) == c * c))
					printf("%d\n", a * b * c);
			}
		}
	}
	return 0;
}