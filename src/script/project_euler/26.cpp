#include <iostream>

using namespace std;

int GetCycle(int d) {
	int start = 1;
	int remainder[10];
	int count = 0;
	int i, k;
	for(i = 0;i < 10;i ++) remainder[i] = -1;

	while(1) {
		start *= 10;
		if(start % d == 0) return 0;
		else {
			/* If the number has occured already check if 
			   remainder was the same, if not, continue
			   else return 
			*/
			k = start / d;
			if(remainder[k] != -1) {
				if(start % d == remainder[k]) return count;
				else count ++;
			}
			else {
				remainder[k] = start % d;
				count ++;
			}

		}
		start %= d;
	}
}

int main() {
	int d, max;
	int n[1001];
	int overall_max = 0, i;

	for(d = 2; d <= 1000;d ++) {
		/* First check if it is a prime number 
	       if it is, then continue else get max 
		   of cycles of all its factors 
		*/
		max = 0;
		for(i = 2; i <= (d / 2); i ++) {
			if(d % i == 0) {
				if(n[i] > max) max = n[i];
			}
		}
		n[d] = max;
		if(max > overall_max) overall_max = max;
		if(max == 0) {
			n[d] = GetCycle(d);
			if(n[d] > overall_max) overall_max = n[d];
		}
	}
	for(d = 2; d <= 1000;d ++) cout << n[d] << "  ";
	cout << endl;
	cout << overall_max << endl;
	return 0;
}
