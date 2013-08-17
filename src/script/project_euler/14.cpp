#include <iostream>

using namespace std;
int len_chain[1000000];
/*int LengthOfChain(int n) {
	//if(n > 333000) cout << n << " in function" << endl;
	if(n == 1) return 1;
	if(n == 0) return 0;
	if(n % 2 == 0) {
		if((n / 2) < 1000000) {
			if(len_chain[n/2] != -1 && n < 1000000) {
				len_chain[n] = 1 + len_chain[n / 2];
			}
			else if(n >= 1000000 && len_chain[n/2] != -1)
				return (1 + len_chain[n/2]);
			else if(len_chain[n/2] == -1 && n < 1000000){
				len_chain[n] = 1 + LengthOfChain(n / 2);
				return len_chain[n];
			}
			else {
				return (1 + LengthOfChain(n / 2));
			}
		}
		else {
			return (1 + LengthOfChain(n / 2));
		}
	}
	else {
		if(n < 1000000) {
			len_chain[n] = 1 + LengthOfChain(3 * n + 1);
			if((3 * n + 1) < 1000000) len_chain[3 * n + 1] = len_chain[n] - 1;
			return len_chain[n];
		}
		else {
			return (1 + LengthOfChain(3 * n + 1));
		}
	}
}*/
int LengthOfChain(long long int n) {
//	cout << "Here "  << n << endl;
	long long int t, tdash, temp;
	if(n < 1000000) {
		if(len_chain[n] != -1) {
	//		cout << "Returning " << len_chain[n] << " " << n << endl;
			return len_chain[n];
		}
	}
	/*if(n == 1) return 1;
	if(n == 0) return 0;*/
	if(n % 2 == 0) {
	//	cout << "GAGA" << endl;
		t = n / 2;
		if(t >= 1000000) {
			temp = LengthOfChain(t);
	//		cout << "Returning " << 1 + temp  << " " << n << endl;
			return (1 + temp);
		}
		else {
			if(n >= 1000000) {
	//			cout << "HOHO" << endl;
				if(len_chain[t] != -1) {
	//				cout << "HEHE" << endl;
	//				cout << "Returning " << 1 + len_chain[t]  << " " << n << endl;
					return (1 + len_chain[t]);
				}
				else {
	//				cout << "HIHI" << endl;
					len_chain[t] = LengthOfChain(t);
	//				cout << "Returning " << 1 + len_chain[t]  << " " << n << endl;
					return (1 + len_chain[t]);
				}
			}
			else {
				if(len_chain[t] != -1) {
					len_chain[n] = 1 + len_chain[t];
	//				cout << "Returning " << len_chain[n]  << " " << n << endl;
					return len_chain[n];
				}
				else {
					len_chain[t] = LengthOfChain(t);
					len_chain[n] = 1 + len_chain[t];
	//				cout << "Returning " << len_chain[n]  << " " << n << endl;
					return len_chain[n];
				}
			}
		}
	}
	else {
		tdash = 3 * n + 1;
		if(n >= 1000000) {
			temp = LengthOfChain(tdash);
	//		cout << "Returning " << 1 + temp  << " " << n << endl;
			return(1 + temp);
		}
		else {
			if(tdash >= 1000000) {
				len_chain[n] = 1 + LengthOfChain(tdash);
	//			cout << "Returning " << len_chain[n]  << " " << n << endl;
				return len_chain[n];
			}
			else {
				if(len_chain[tdash] != -1) {
					len_chain[n] = 1 + len_chain[tdash];
	//				cout << "Returning " << len_chain[n]  << " " << n << endl;
					return len_chain[n];
				}
				else {
					len_chain[tdash] = LengthOfChain(tdash);
					len_chain[n] = 1 + len_chain[tdash];
	//				cout << "Returning " << len_chain[n]  << " " << n << endl;
					return len_chain[n];
				}
			}
		}
	}
}

int main () {
	int i, j;
	int l, max = 0, max_num = 0;
	for(i = 0;i < 1000000;i ++) len_chain[i] = -1;
	len_chain[0] = 0;
	len_chain[1] = 1;

	for(i = 1; i < 1000000;i ++) {
		if(i % 1000 == 0) cout << i << " " << max << " " << max_num << endl;
		//if(i > 1000) cout << i << endl;
		l = LengthOfChain(i);
		/*if(i == 333344) {
			cout << l << endl;
			return 0;
		}*/
		if(l > max) {
			max = l;
			max_num = i;
		}
	}
	cout << max << " " << max_num << endl;
	return 0;
}
