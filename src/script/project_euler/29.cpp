#include <iostream>
#include <fstream>

using namespace std;
int Relation(int *a, int* b) {
	int i, j;
	for(i = 0;i < 202;i ++) {
		if(a[i] < b[i]) return -1;
		else if(a[i] > b[i]) return 1;
	}
	return 0;
}
int main() {
	ofstream out;
	int res[9801][202];
	int carry = 0, temp, i, j, a, b, k, pos;
	out.open("29.txt");
	
	for(a = 2;a <= 100; a ++) {
		for(b = 2; b <= 100; b ++) {
			pos = (a - 2) * 99 + b - 2;
			for(i = 0;i < 202;i ++) res[pos][i] = 0;
			res [pos][201] = 1;

			for(k = b;k >= 1; k --) {
				carry = 0;
				for(i = 201;i >= 0;i --) {
					temp = res[pos][i] * a + carry;
					res[pos][i] = temp % 10;
					carry = temp / 10;
				}
			}
			out << a << " " << b << " ";
			k = 0;
			while(res[pos][k] == 0) k ++;
			for(i = k;i <= 201;i ++) {
				out << res[pos][i];
			}
			out << endl;
		}
	}

	int count = 1;
	for(i = 1;i < 9801;i ++) {
		for(j = 0; j < i;j ++) {
			if(Relation(res[i], res[j]) == 0) break;
		}
		if(j == i) count ++;
	}
	cout << count << endl;
	//cout << sum << endl;
	return 0;
}

