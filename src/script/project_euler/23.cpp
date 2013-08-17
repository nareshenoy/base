#include <iostream>

using namespace std;

int FindKind(int n) {
	int i, sum = 0;
	for(i = 1;i <= (n / 2); i ++) {
		if(n % i == 0)sum += i;
	}
	if(sum < n) return -1;
	else if(sum == n) return 0;
	else return 1;
}
int main() {
	int a[28124];
	int test[28124];
	int sum = 0, i, j;
	for(i = 1; i < 28124; i ++) {
		a[i] = FindKind(i);
		test[i] = 0;
	}
	/* Find sum of abundant numbers */
	for(i = 1;i < 28124;i ++) {
		for(j = 1;j < 28124;j ++) {
			if(a[i] == 1 && a[j] == 1 && (i + j) < 28124) {
				test[i + j] = 1;
			}
		}
	}
	for(i = 1;i < 28124;i ++) if(test[i] == 0) sum += i;
	cout << sum << endl;
	return 0;
}
