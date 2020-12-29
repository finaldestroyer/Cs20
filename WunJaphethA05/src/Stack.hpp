/*
 * Stack.hpp
 *
 *  Created on: Oct 7, 2019
 *      Author: student
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include<string>
namespace std {

class Stack {
private:
	struct s{
		string str;
		s * next = nullptr;
	};
	s * header;
	int StackSize;
	int remain;
public:
	Stack(int);
	void SetStackSize(int);
	int RemainStacks();
	void push(string);
	bool top(string);
	bool pop(string&);
	void destroy();
	//virtual ~Stack();
};

} /* namespace std */

#endif /* STACK_HPP_ */
