#include <iostream>
using namespace std;

void reduce(int num, int den) {
  int j = num;
  for(int i = 2;i <= j;i ++) {
    while(num % i == 0 && den % i == 0) {
      num /= i;
      den /= i;
    }
  }
  cout << num << " / " << den << endl;
  return;
}
int checkFrac(int num, int den) {
  int a, b, c, d, i;
  a = num;
  b = den;
  for(i = 2;i <= num;i ++) {
    while(a % i == 0 && b % i == 0) {
      a /= i;
      b /= i;
    }
  }
  c = num;
  d = den;
  if(c % 10 == d / 10) {
    c /= 10;
    d %= 10;
    if(c >= d) return 0;
    for(i = 2;i <= c;i ++) {
      while(c % i == 0 && d % i == 0) {
        c /= i;
        d /= i;
      }
    }
    if( a == c && b == d) {
      cout << num << "/" << den << endl;
      return 1;
    }
  }
  return 0;
}

int main() {
  int i, j, k;
  int num = 1, den = 1, count = 0;
  for(i = 10;i < 100;i ++) {
    for(j = i + 1;j < 100;j ++) {
      k = checkFrac(i, j);
      if(k == 1) {
        num *= i;
        den *= j;
        count ++;
      }
    }
  }
  cout << count << " " << num << " / " << den << " "; 
  reduce(num, den);
  return 0;
}

