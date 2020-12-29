/*
 * Stack.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: student
 */

#include "Stack.hpp"
#include <string>
#include <iostream>
#include <set>
namespace std {

Stack::Stack(int size) {
	// TODO Auto-generated constructor stub
	StackSize = size;
	remain = size;
	header = nullptr;
}

int Stack::RemainStacks(){
	return StackSize;
}

void Stack::push(string sent){
	s * newStacker = new s;
	newStacker->str = sent;
	s * temp = header;
	if(!temp){
		header = newStacker;
		StackSize--;
	}
	if(temp){
		newStacker->next = temp;
		header = newStacker;
		StackSize--;
	}
}
bool Stack::top(string sent){
	if(!header){
			return false;
		}
	if(header){
		sent = header->str;
		return true;
	}
	else{
		return false;
	}
	return false;
}
bool Stack::pop(string &sent){
	s * temp = header;
	if(!temp){
		return true;
	}
	if(temp){
		cout<<temp->str<<endl;
		if(temp->next){
			header = header->next;
			delete temp;
			return true;
		}
		if(temp->next == nullptr){
			delete temp;
			header = nullptr;
			return false;
		}
	}

	return true;
}

//void destroyStack(string sent){
//	s * temp = header;
//	s * temp2;
//	if(header->str == sent){
//		temp2 = header->next;
//		delete header;
//		header = temp2;
//	}
//	while(temp){
//		if(temp->str == sent){
//			temp2->next = temp->next;
//			delete temp;
//		}
//		temp2 = temp;
//		temp = temp->next;
//	}
//}


void Stack::destroy(){
	s * temp1 = header;
	s * temp2;
	while(temp1){
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
		StackSize++;
	}
}

/*Stack::~Stack() {
	// TODO Auto-generated destructor stub
}*/

} /* namespace std */
