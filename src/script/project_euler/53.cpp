#include <iostream>
using namespace std;

int main() {
  int n, r, i;
  int count = 0;
  double prod = 1, arr_prod[101];
  int factarr[101];
  for(i = 1;i < 101;i ++) {
    prod *= i;
	while(prod >= 10) {
		prod /= 10;
		count ++;
	}
	factarr[i] = count;
	arr_prod[i] = prod;
	cout << i << " " << arr_prod[i] << " " << factarr[i] << endl;
  }
  factarr[0] = 0;
  arr_prod[0] = 1;
  count = 0;
  for(n = 1; n <= 100; n ++) {
    for(r = 0; r <= n; r ++) {
      if(((factarr[n] - factarr[n - r] - factarr[r]) >=  8) || 
		  ((factarr[n] - factarr[n - r] - factarr[r]) == 6 && (arr_prod[n] / arr_prod[r] / arr_prod[n - r]) >= 1) ||
		  ((factarr[n] - factarr[n - r] - factarr[r]) == 7 && (arr_prod[n] * 10 / arr_prod[r] / arr_prod[n - r]) >= 1) ||
		  ((factarr[n] - factarr[n - r] - factarr[r]) == 8 && (arr_prod[n] * 100 / arr_prod[r] / arr_prod[n - r]) >= 1)) {
		  count ++;
		  //cout << n << " " << r << endl;
	  }
	}
  }
  cout << count << endl;
  return 0;
}
