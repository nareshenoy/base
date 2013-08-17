#include <iostream>
using namespace std;

int sum(int *cp) {
	int s = 0;
	for(int i = 0;i < 200;i ++) s += cp[i];
	return s;
}
int mult(int *cp, int a) {
	int carry = 0;
	int tmp;
	for(int i = 199; i >= 0;i --) {
		tmp = cp[i] * a;
		cp[i] = (carry + tmp) % 10;
		carry = (carry + tmp) / 10;
	}
	return sum(cp);
}
int main() {
	int a, b, i, k;
	int max = 0;
	int *current_prod;
	current_prod = new int[200];

	for(a = 1; a < 100;a ++) {
		current_prod[199] = a % 10;
		current_prod[198] = (a / 10) % 10;

		for(i = 0;i < 198;i ++) current_prod[i] = 0;

		k = sum(current_prod);
		if(k > max) max = k;
		
		for(b = 2;b < 100; b ++) {
			k = mult(current_prod, a);
			if(k > max) max = k;
		}
	}
	cout << max << endl;
	return 0;
}
