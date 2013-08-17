#include <stdio.h>

int main() {
	int i, j = 0;
	for(i = 0;i < 1000;i ++) {
		if(i % 3 == 0) {
			j += i;
		}
		if(i % 5 == 0)  {
			j+= i;
		}
		if(i % 15 == 0) {
			j -= i;
		}	
	}
	printf("%d\n", j);
	return 0;
}