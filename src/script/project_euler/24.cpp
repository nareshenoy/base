#include <iostream>

using namespace std;

int n = 10;
int count = 0;
int perm[10];
int inPerm(int i, int l) {
	int j;
	for(j = 0;j <= l;j ++) {
		if(perm[j] == i) return 1;
	}
	return 0;
}
void MakePermutations(int length) {
	int i;
	if(length < n) {
		for(i = 0; i < n;i ++) {
			if(!inPerm(i, length - 1)) {
				perm[length] = i;
				MakePermutations(length + 1);
			}
		}
	}
	else {
		count ++;
		if(count == 1000000) {
			for(i = 0;i < n;i ++) cout << perm[i];
			cout << endl;
		}
	}
}
int main() {
	int i, j;
	for(i = 0;i < n;i ++) perm[i] = -1;
	MakePermutations(0);
	return 0;
}
