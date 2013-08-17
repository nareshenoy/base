#include <iostream>
#include <fstream>
#include <cmath>
long long int req[201];
int counter = 0;
int count = 0;
ofstream out;
void printStack(void) {
	int i;
	for(i = 0;i < counter;i ++) out << req[i] << " ";
	out << endl;
}
void pushStack(int i) {
	req[counter] = i;
	counter ++;
}
void popStack(void) {
	counter --;
	req[counter] = -1;
	return;
}
long long int NoOfWaysToMake(int n, int token) {
	int a, b, c, d, e, f, g, h;
	if(n == 0) {
		//out << token << " ";
		printStack();
		count ++;
		return 1;
	}
	else if (n < 0) {
		return 0;
	}
	else {
		//if(req[n] != -1) return req[n];
		//else {
			if(counter == 0) {
				pushStack(1);
				a = NoOfWaysToMake(n - 1, 1);
				popStack();
				//count = a;

				pushStack(2);
				b = NoOfWaysToMake(n - 2, 2);
				popStack();
				//count += b;

				pushStack(5);			
				c = NoOfWaysToMake(n - 5, 5);
				popStack();
				//count += c;

				pushStack(10);			
				d = NoOfWaysToMake(n - 10, 10);
				popStack();
				//count += d;

				pushStack(20);			
				e = NoOfWaysToMake(n - 20, 20);
				popStack();
				//count += e;

				pushStack(50);			
				f = NoOfWaysToMake(n - 50, 50);
				popStack();
				//count += f;

				pushStack(100);			
				g = NoOfWaysToMake(n - 100, 100);
				popStack();
				//count += g;

				pushStack(200);			
				h = NoOfWaysToMake(n - 200, 200);
				popStack();
				//count += h;
				return count;
			}
			else {
				if(1 >= req[counter - 1]) {
					pushStack(1);
					a = NoOfWaysToMake(n - 1, 1);
					popStack();
					//count += a;
				}
				if(2 >= req[counter - 1]) {
					pushStack(2);
					b = NoOfWaysToMake(n - 2, 2);
					popStack();
					//count += b;
				}
				if(5 >= req[counter - 1]) {
					pushStack(5);			
					c = NoOfWaysToMake(n - 5, 5);
					popStack();
					//count += c;
				}
				if(10 >= req[counter - 1]) {
					pushStack(10);			
					d = NoOfWaysToMake(n - 10, 10);
					popStack();
					//count += d;
				}
				if(20 >= req[counter - 1]) {
					pushStack(20);			
					e = NoOfWaysToMake(n - 20, 20);
					popStack();
					//count += e;
				}
				if(50 >= req[counter - 1]) {
					pushStack(50);			
					f = NoOfWaysToMake(n - 50, 50);
					popStack();
					//count += f;
				}
				if(100 >= req[counter - 1]) {
					pushStack(100);			
					g = NoOfWaysToMake(n - 100, 100);
					popStack();
					//count += g;
				}
				if(200 >= req[counter - 1]) {
					pushStack(200);			
					h = NoOfWaysToMake(n - 200, 200);
					popStack();
					//count += h;
				}
				out << endl;
				return (count);
			}
	}
}
int main() {
	long long int n, i;
	out.open("31.txt");
	for(i = 0; i < 201;i ++) req[i] = -1;
	//for(i = 1;i < 201;i ++) {
		n = NoOfWaysToMake(200, 0);
		out << "<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	//}
	//n = NoOfWaysToMake(200);
	cout << count << endl;
	return 0;
}
