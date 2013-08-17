#include <iostream>
using namespace std;
int prod[1000000];
/*
The main premise is that the no. of digits in the
product is atleast the max of digits of i, j
So, we will iterate till four digits
*/
int checkProd(int a, int b, int ab) {
  int digits[10];
  int i, j, k;
  i = a;
  j = b;
  if(prod[ab] == 1) return 0;
  for(k = 0;k < 10;k ++) digits[k] = 0;
  while(a != 0) {
    if(digits[a % 10] == 1 || (a % 10 == 0)) return 0;
    else {
      digits[a % 10] = 1; 
      a /= 10;
    }
  }
  while(b != 0) {
    if(digits[b % 10] == 1 || (b % 10 == 0)) return 0;
    else {
      digits[b % 10] = 1;
      b /= 10;
    }
  }
  while(ab != 0) {
    if(digits[ab % 10] == 1 || (ab % 10 == 0)) return 0;
    else {
      digits[ab % 10] = 1;
      ab /= 10;
    }
  }
  k = 0;
  for(k = 1;k < 10;k ++) {
    if(digits[k] == 0) return 0;
  }
  if(k == 10) {
    prod[i * j] = 1;
    cout << i << " " << j << " " << i * j << endl;
    return 1;
  }

}
int main() {
  int i, j;
  int sum = 0;
  for(i = 0;i < 1000000;i ++) prod[i] = 0;
  for(i = 1;i <= 100;i ++) {
    for(j = i + 1; j < 9999;j ++) {
      if(i % 10 != j % 10) {
        if(checkProd(i, j, i * j)) {
          sum += i * j;
        }
      }
    }  
  }
  cout << sum << endl;
  return 0;
}

