#include <iostream>
#include <fstream>
using namespace std;
int value(char *a) {
	int i = 0, sum = 0;
	while(a[i] != '\0' && a[i] != '\n') {
		sum += a[i] - 64;
		i ++;
	}
	return sum;
}
int isTriangle(int n) {
	int i;
	for(i = 1; i <= n; i ++) {
		if(i * (i + 1) == 2 * n) return 1;
	}
	return 0;
}
int main() {
	char *word = new char[20];
	int count = 0, k;
	ifstream words;

	words.open("42.txt");
	while(!words.eof()) {
		words.getline(word, 20);
		k = value(word);
		if(isTriangle(k)) {
			count ++;
		}
	}
	cout << count << endl;
	words.close();
	return 0;
}