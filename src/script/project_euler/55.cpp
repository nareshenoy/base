#include <iostream>
/*There is an overflow problem here that needs to be solved!! */
int reverse(int b) {
	int r = 0;
	while(b != 0) {
		r = 10 * r + (b % 10);
		b /= 10;
	}
	return r;
}

int isPalindrome(int c) {
	if(c == reverse(c)) return 1;
	else return 0;
}

int isLychrel(int a) {
	int reva, i, c;
	int b = a;
	for(i = 0;i < 50;i ++) {
		c = b + reverse(b);
		if(isPalindrome(c)) return 0;
		b = c;
	}
	return 1;
}
int main() {
	int i, count = 0;
	
	for(i = 1;i < 10000;i ++) {
		if(isLychrel(i)) count ++;
	}
	cout << count << endl;
	return 0;
}