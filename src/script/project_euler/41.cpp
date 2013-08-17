#include<iostream>
#include<cmath>

using namespace std;
int checkPrime(int *perm){
	unsigned long long n, i;
	if(perm[9] == 2 || perm[9] == 5 || perm[9] == 8 || perm[9] == 6 || perm[9] == 4) return 0;
	n = 0;
	int k = 1;
	while(k < 10 && perm[k] != -1) k++;
	for(int j = 1; j < k; j++) {
		n += (unsigned long long) (perm[j] * pow(10, k - 1 - j));
	}
	/*n = (unsigned long long)(perm[1] * pow(10, 8) + perm[2] * pow(10, 7));
	n += (unsigned long long)(perm[3] * pow(10, 6) + perm[4] * pow(10, 5));
	n += (unsigned long long)(perm[5] * pow(10, 4) + perm[6] * pow(10, 3));
	n += (unsigned long long)(perm[7] * pow(10, 2) + perm[8] * pow(10, 1));
	n += (unsigned long long)(perm[9]);*/
	//cout << n << endl;
    for(i = 3; i <= (n / 2); i += 2) {
		if((n % i) == 0) return 0;
	}
	cout << "Prime!" << endl;
	return 1;
}
void PnC(int *perm, int *used, int num, int k) {
  if(num == k + 1) {
	  int check = checkPrime(perm);
      if(check) {
		  for(int i = 1;i < k + 1;i ++) cout << perm[i];
		  cout << endl;
	  }
	  for(int i = 1;i < 10;i ++) {
        //cout << perm[i];

	  }
	  //cout << endl;
	  return;
  }
  
    for(int i = k;i > 0;i --) {
	  if(used[i] == 0) {
	 	  perm[num] = i;
		  used[i] = -1;
		  PnC(perm, used, num + 1, k);
		  used[i] = 0;
	  }
    }
  
  return;
}
int main() {
  int i, j;
  int *perm, *used;
  perm = new int[10];
  used = new int[10];
  for(i = 0;i < 10;i ++) {
	  perm[i] = 0;
	  used[i] = 0; // 0 means this number has not been used yet, -1 means the number has been used once
  }
  for(int k = 9; k > 0;k --) {
	  if(k < 9) perm[k + 1] = -1;
	  PnC(perm, used, 1, k);
  }
  return 0;
}