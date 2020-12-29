//============================================================================
// Name        : WunJaphethA03V2.cpp
// Author      : Japheth Wun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//int fact(int &total, int value){
//	if(value > 0){
//		total = total * value;
//		fact(total,(value-1));
//	}
//	return total;
//}
//int fact(int a){
//	int total = 1;
//	total = fact(total,a);
//	return total;
//}
int fact(int n)
{
    if(n > 1)
        return n * fact(n - 1);
    else
        return 1;
}
int fib(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }
   else{
      return(fib(x-1)+fib(x-2));
   }
}
void prime(int number,int value)
{
	bool rice = false;
	if(value >= 1)
	{
		for(int i = 2; i <= ((int)(ceil(sqrt(number)))); i++)
		{
			if(number % i == 0)
				{
					rice = true;
				}
		}
		if(rice) prime(number + 1, value);
		else
		{
			cout << number << " ";
			prime(number + 1, value - 1);
		}
	}
	else return;
}
void prime (int value)
{
	int primes = 2;
	cout << primes << " ";
	prime(primes + 1, value - 1);
	return;
}
int mult(int a, int b, int c, int d){
	if(c<b){
		a = a+d;
		return mult(a,b,(c+1),d);
	}
	return a;
}
int mult(int a, int b){
	int c = 1;
	return mult(a,b,c,a);
}
string reverseString(string sent, double size, double count){
	if(count<=(size/2)){
		swap(sent[count-1], sent[size-count]);
		return reverseString(sent,size,count+1);
	}
	if(count == (size/2)){
		cout<<sent;
		cout<<endl;
	}
	return sent;
}
string reverseString(string sent){
	string reverse = sent;
	double size = reverse.length();
	double count = 1;
	reverse = reverseString(sent,size,count);
	return reverse;
}
int countOccurrences(string sent, string word)
{
	int size = sent.length();
	int size2 = word.length();

//	if (sent.substr(0,size2) == word)
//	{
//			return countOccurrences(sent.substr(0,size), word) + 1;
//	}
//	return countOccurrences(sent.substr(0,size), word);

	if(sent.length() > 0)
		{
			if(sent.substr(0,size2) == word){
				return countOccurrences(sent.substr(1,size), word) + 1;
			}
			else{
				return countOccurrences(sent.substr(1,size), word);
			}
		}
		else{
			return 0;
		}
}

int main() {
	// factorial
	int count;
	int f=5;
	cout << "factorial of " << f << " is " << fact(f) << endl << endl;
	// Fibonocci
	for (count=0;count < 10;count++)
	{
	cout << "Fibonocci sequence number " << count+1 << " is "
	<< fib(count+1) << endl;
	}
	// primes
	prime (10);
	// multiplication
	int a=6, b=5;
	cout << endl << "product of " << a << " and " << b << " is " <<
	mult(a,b) << endl << endl;
	// string reversal
	string s = "abcde";
	cout << "original string " << s << " reversed string " <<
	reverseString(s) << endl << endl;
	// character counting
	string t="a";
	cout << "number of occurrences of " << t[0] << " in " << s << " is "
	<< countOccurrences(s,t) << endl;
	return 0;
	return 0;
}
