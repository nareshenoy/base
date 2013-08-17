#include <iostream>
#include <string>
using namespace std;

int digits[10];
int numDigits(int n) {
	int count = 0;
	while(n != 0) {
		n /= 10;
		count ++;
	}
	return count;
}
int addDigits(int n) {
  int count = 0;
  while(n != 0) {
	if(n % 10 == 0) return 0;
    else if(digits[n % 10] != 0) return 0;
	else {
		digits[n % 10] = 1;
		n /= 10;
		count ++;
	}
  }
  return count;
}
int main() {
  int i, j, k, retVal, count;
  char* buffer = new char[10];
  string maxprod;
  string prod;
  maxprod.assign("");

  for(i = 1;i < 10000;i ++) {
    prod.assign("");
	for(k = 0;k < 10;k ++) digits[k] = 0;
	count = 0;
    for(j = 1;j <= 9/numDigits(i);j ++) {
      //cout << i << " " << j << " " << endl;
	  retVal = addDigits(j * i);
//	  cout << "HERE" << endl;
      if(retVal) {
		count += retVal;
		itoa(j * i, buffer, 10);
        prod.append(buffer);
	  }
	  else break;
//	  cout << "HERE2" << endl;
	  if(count >= 9) break;
	}
	if(count == 9) {
	  if(maxprod.compare(prod) < 0) {
        cout << prod.c_str() << endl;
        maxprod.assign(prod);
	  }
	}
  }
  cout << maxprod.c_str() << endl;
  return 0;
}
