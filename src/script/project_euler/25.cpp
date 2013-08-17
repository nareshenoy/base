#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//ofstream out;
	//out.open("25.txt");
	int a[1001], b[1001], c[1001];
	int carry, i, j, count;

	for(i = 1; i < 1001; i ++) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	a[1000] = 1;
	b[1000] = 1;
	count = 2;
	while(1) {
		carry = 0;
		for(i = 1000;i >= 1; i --) {
			c[i] = (a[i] + b[i]) % 10 + carry;
			carry = (a[i] + b[i]) / 10;
		}
		count ++;
		for(j = 1000; j >= 1; j --) {
				a[j] = b[j];
				b[j] = c[j];
		}
		if(c[1] > 0) break;
	}
	//for(j = 1;j < 1001;j ++) out << c[j];
	//out << endl;
	//out.close();
	cout << count;
	return 0;
}
