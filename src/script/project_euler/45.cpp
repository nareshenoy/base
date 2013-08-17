#include <iostream>
using namespace std;

int isHexagonal(long long int n, int limit) {
	long long int i;
	long long int k;
	for(i = 1; i <= limit; i ++) {
		k = i * (2 * i - 1);
		if(k == n) return 1;
		if(k > n) return 0;
	}
	return 0;
}
long long int isPentagonal(long long int n, int limit) {
	long long int i, k;
	for(i = 1; i <= limit; i ++) {
		k = i * (3 * i - 1) / 2;
		if(k == n) return i;
		if(k > n) return 0;
	}
	return 0;
}
int main () {
	long long int i, k, j;
	for(i = 286;;i ++) {
		if(i % 10000 == 0) cout << i << endl;
		k = 0;
		j = i * (i + 1)/ 2;
		k = isPentagonal(j, i); 
		if( k > 0 && isHexagonal(j, k)) break;
	}
	cout << i * (i + 1) / 2 << endl;
	return 0;
}
