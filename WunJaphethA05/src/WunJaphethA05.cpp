//============================================================================
// Name        : WunJaphethA05.cpp
// Author      : Japheth Wun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Stack.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
		Stack s(5);
		string st;
		bool b;
		s.push("aaaaa");
		s.push("bbbbb");
		s.push("ccccc");
		s.push("ddddd");
		s.push("eeeee");

		cout << "main: start of part 1" << endl;
		b = s.top(st);
		cout << "main: top of stack " << st << endl;
		b = s.pop(st);
		cout << "main: just popped this ->" << st << endl;
		b = s.top(st);
		cout << "main: new top of stack after pop " << st << endl;
		b = s.pop(st);
		cout << "main: just popped this ->" << st << endl;
		b = s.pop(st);
		cout << "main: just popped this ->" << st << endl;
		b = s.pop(st);
		cout << "main: just popped this ->" << st << endl;
		b = s.pop(st);
		cout << "main: just popped this ->" << st << " stack should now be empty" << endl;
		b = s.top(st);
		if (b)
		{
			cout << "main: stack non-empty when it should be empty" << endl;
			return 4;
		}
		else
		{
			cout << "main: stack empty when it's empty" << endl;
		}

		cout << endl << "main: start of part 2" << endl;
		s.push("aaaaa");	// 1st element 1st array
		s.push("bbbbb");
		s.push("ccccc");
		s.push("ddddd");
		s.push("eeeee");
		s.push("fffff");	// 1st element 2nd array
		s.push("ggggg");
		s.push("hhhhh");
		s.push("iiiii");
		s.push("jjjjj");
		s.push("kkkkk");	// 1st element 3rd array

		b = s.top(st);
		cout << "main: top of stack " << st << endl;
		cout << "main: before while loop " << st << endl;
		b = s.pop(st);
		while (b)
		{
			cout << "main: element of stack " << st << endl;
			b=s.pop(st);
		}

		cout <<"main: before destroy"<< endl;
		s.destroy();
		cout <<"main: after destroy"<< endl;
		s.push("zzzzz");
		b=s.top(st);
		cout << "main: new top of stack " << st << endl;
		s.destroy();

		return 0;
}
