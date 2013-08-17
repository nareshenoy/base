#include <iostream>

using namespace std;

int main () {
	int i, day;
	day = 2;
	int count = 0;
	/* For January */
	for(i = 1901;i <= 2000;i ++) {
		if((i - 1) % 4 == 0 && i != 1901) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 5;
	/* For February */
	for(i = 1901;i <= 2000;i ++) {
		if((i - 1) % 4 == 0 && i != 1901) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 5;
	/* For March */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 1;
	/* For April */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 3;
	/* For May */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 6;
	/* For June */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 1;
	/* For July */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 4;
	/* For August */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 7;
	/* For September */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 2;
	/* For October */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 5;
	/* For November */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	day = 7;
	/* For December */
	for(i = 1901;i <= 2000;i ++) {
		if(i % 4 == 0) day += 2;
		else day += 1;
		if(day % 7 == 1) count ++;
	}
	cout << count << endl;
	return 0;
}
