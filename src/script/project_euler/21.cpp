#include <iostream>

using namespace std;
int GetDi(int i) {
	int sum = 0;
	for(int j = 1;j <= (i / 2); j ++) {
		if(i % j == 0) sum += j;
	}
	return sum;
}
int main(){ 
	int i, j, sum = 0;
	int d[10000];
	for(i = 0; i < 10000;i ++) {
		d[i] = GetDi(i);
	}
	for(i = 0;i < 10000;i ++) {
		for(j = i + 1;j < 10000;j ++) {
			if(d[i] == j && d[j] == i) {
				sum += i + j;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
