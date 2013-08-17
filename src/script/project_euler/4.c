#include <stdio.h>
#include <stdlib.h>

int isPalindrome(t) {
	char a[10];
	int len, i;

	itoa(t, a, 10);
	len = strlen(a);
	for(i = 0;i <= len/2; i ++) {
		if(a[i] == a[len - 1 - i]) continue;
		else return 0;
	}
	return 1;
}
int main() {
	int i, j;
	int t;
	int max = 0;
	for(i = 101;i < 999;i ++) {
		if(i % 10 == 0) continue;
		for(j = 101;j < 999;j ++) {
			if(j % 10 == 0) continue;
			/*a = i / 100;
			b = (i / 10) % 10;
			c = i % 10;
			d = j / 100;
			e = (j / 10) % 10;
			f = j % 10;*/
			t = i * j;
			if(isPalindrome(t) && ((t) > max)) max = t;
		}
	}
	printf("%d\n", max);
	return 0;
}