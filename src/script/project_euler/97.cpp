#include <iostream>
using namespace std;

int main() {
  int res[11];
  long long int i;
  int j, k, carry;
  for(i = 0;i < 11;i ++) res[i] = 0;
  res[10] = 1;
  for(i = 1;i <= 7830457;i ++) {
    carry = 0;
    for(j = 10;j > 0;j --) {
	  k = res[j] * 2 + carry;
	  res[j] = k % 10;
	  carry = k / 10;
	}
  }
  cout << i << endl;
  carry = 0;
  for(j = 10; j > 0; j --) {
    k = res[j] * 28433 + carry;
    res[j] = k % 10;
    carry = k / 10;
  }
  res[10] += 1;
  for(i = 1;i < 11;i ++) cout << res[i];
  return 0;
}