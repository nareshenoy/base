#include <iostream>
#include <fstream>

using namespace std;
int SumOfAlphabets(char *a) {
	int i = 0;
	int sum = 0;
	while(a[i] != '\0') {
		sum += a[i] - 64;
		i ++;
	}
	return sum;
}
int main() {
	ifstream inp;
	char a[5163][20], t[20];
	int i, n, j, sum = 0;

	inp.open("22.txt");
	for(i = 0;i < 5163; i ++) {
		inp.getline(a[i], 20);
	}
	n = 5163;
	for (i = n - 2; i >= 0; -- i) {
      for (j = 0; j <= i; ++ j) {
         if (strcmp(a[j], a[j + 1]) > 0) {
            strcpy(t, a[j]);
            strcpy(a[j], a[j + 1]);
            strcpy(a[j + 1], t);
         }
      }
    }
	for(i = 0; i < 5163; i ++) {
		sum += ((i + 1) * SumOfAlphabets(a[i]));
	}
	cout << sum << endl;
	return 0;
}
