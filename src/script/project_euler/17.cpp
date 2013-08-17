#include <iostream>

using namespace std;

int main() {
	char one[] = "one";
	char two[] = "two";
	char three[] = "three";
	char four[] = "four";
	char five[] = "five";
	char six[] = "six";
	char seven[] = "seven";
	char eight[] = "eight";
	char nine[] = "nine";
	char ten[] = "ten";
	char eleven[] = "eleven";
	char twelve[] = "twelve";
	char thirteen[] = "thirteen";
	char fourteen[] = "fourteen";
	char fifteen[] = "fifteen";
	char sixteen[] = "sixteen";
	char seventeen[] = "seventeen";
	char eighteen[] = "eighteen";
	char nineteen[] = "nineteen";
	char twenty[] = "twenty";
	char thirty[] = "thirty";
	char forty[] = "forty";
	char fifty[] = "fifty";
	char sixty[] = "sixty";
	char seventy[] = "seventy";
	char eighty[] = "eighty";
	char ninety[] = "ninety";
	char hundred[] = "hundred";
	char thousand[] = "thousand";
	char and[] = "and";
	int sum = 0;
	sum += strlen(one) + strlen(two) + strlen(three) + strlen(four) + strlen(five) + strlen(six) + strlen(seven) + strlen(eight) + strlen(nine) + strlen(ten) + strlen(eleven) + strlen(twelve) + strlen(thirteen) + strlen(fourteen) + strlen(fifteen) + strlen(sixteen) + strlen(seventeen) + strlen(eighteen) + strlen(nineteen);

	int temp = strlen(one) + strlen(two) + strlen(three) + strlen(four) + strlen(five) + strlen(six) + strlen(seven) + strlen(eight) + strlen(nine);
	sum += strlen(twenty) * 10 + temp;
	sum += strlen(thirty) * 10 + temp;
	sum += strlen(forty) * 10 + temp;
	sum += strlen(fifty) * 10 + temp;
	sum += strlen(sixty) * 10 + temp;
	sum += strlen(seventy) * 10 + temp;
	sum += strlen(eighty) * 10 + temp;
	sum += strlen(ninety) * 10 + temp;

	int till_99 = sum;
	sum += strlen(one) + strlen(hundred);
	sum += 99 * (strlen(one) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(two) + strlen(hundred);
	sum += 99 * (strlen(two) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(three) + strlen(hundred);
	sum += 99 * (strlen(three) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(four) + strlen(hundred);
	sum += 99 * (strlen(four) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(five) + strlen(hundred);
	sum += 99 * (strlen(five) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(six) + strlen(hundred);
	sum += 99 * (strlen(six) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(seven) + strlen(hundred);
	sum += 99 * (strlen(seven) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(eight) + strlen(hundred);
	sum += 99 * (strlen(eight) + strlen(hundred) + strlen(and)) + till_99;
	sum += strlen(nine) + strlen(hundred);
	sum += 99 * (strlen(nine) + strlen(hundred) + strlen(and)) + till_99;

	sum += strlen(one) + strlen(thousand);
	cout << sum << endl;
	return 0;
}
