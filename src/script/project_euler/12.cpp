#include <iostream>
//int num_fac[20000];
int GetNumOfFactors(int n) {
	int count = 0, i;

	for(i = 1;i <= n;i ++) {
		if(n % i == 0) count ++;
	}
	return count;
}
int main() {
	int i = 1, num_fac;
	int tri_num;
	/*for(i = 0;i < 20000;i ++) {
		num_fac[i] = -1;
	}
	i = 1;*/
	while(1) {
		if(i % 100 == 0) cout << i << endl;
		tri_num = i * (i + 1) / 2;
		if(i % 2 == 0) {
			num_fac = GetNumOfFactors(i/2) * GetNumOfFactors(i + 1) - 1;
		}
		else {
			num_fac = GetNumOfFactors((i + 1)/2) * GetNumOfFactors(i) - 1;
		}
		if(num_fac > 500) {
			cout << tri_num << endl;
			break;
		}
		i ++;
	}
	return 0;
}
