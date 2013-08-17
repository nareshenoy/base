#include <iostream>
using namespace std;
int testfunc(void) {
	cout << "test" << endl;
	return 1;
}
int main() {
	int k = 2000000;
	//cout << k * (2 * k - 1) << endl;
	if(1 && testfunc()) cout << "goes" << endl;
	return 0;
}
