#include <iostream>
using namespace std;

int main() {
  int p;
  int a, b, c, count, max = 0, max_idx;
  for(p = 3; p <= 1000;p ++) {
    count = 0;
    for(a = 1; a <= p - 3; a ++) {
      for(b = a + 1; b <= (p - a - 1); b ++) {
        c = p - (a + b);
        if(a * a + b * b == c * c) {
          count ++;
        }
      }
    }
	if( count > max) {
      max = count;
      max_idx = p;
    }
  }
  cout << max_idx << " " << max << endl;
  return 0;
}
