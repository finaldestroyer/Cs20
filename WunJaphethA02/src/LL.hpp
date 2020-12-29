/*
 * LL.hpp
 *
 *  Created on: Sep 16, 2019
 *      Author: student
 */

#ifndef LL_HPP_
#define LL_HPP_
#include <string>
#include <iostream>

using namespace std;
template<class T>
class LL {
private:
	struct LLnode{
		T content;
		LLnode * next;
	};
	LLnode * header;
public:
	LL(){
		header = NULL;
	}

	void display_list(){
		LLnode * temp;
		temp = header;
		if(!temp){
			cout<<"No nodes"<<endl;
			return;
		}
		while(temp){
			cout<<temp->content<<endl;
			temp = temp->next;
		}
	}
	void push_front(T text){
		LLnode * temp;
		temp = header;
		LLnode * newL = new LLnode;
		newL->content = text;
		newL -> next = temp;
		header = newL;
	}
	void push_back(T text){
		LLnode * newL = new LLnode;
		newL->next=nullptr;
		newL->content= text;
		LLnode * temp;
		temp = header;
		if(temp==nullptr)
		{
			header=newL;
		}
		else
		{
			while(temp->next!=nullptr)
			{
				temp = temp->next;
			}
			temp->next = newL;
		}
	}
	int list_length (){
		int count = 0;
		if(!header)
		{
			return count;
		}
		LLnode * temp;
		temp = header;
		while(temp)
		{
			count++;
			temp = temp -> next;
		}
		return count;
	}
	string retrieve_front (){
		string text;
		if(!header){
			text = "No nodes";
			cout<<text<<endl;
			return text;
		}
		text = header->content;
		cout<<"The content of the first Node is "<<text<<endl;
		return text;
	}
	string retrieve_back (){
		LLnode * temp;
		temp = header;
		string text;
		if(temp)
		{
			while(temp->next)
			{
				temp = temp->next;
			}
			text = temp->content;
}
		else
		{
			{
				text = "no nodes";
				cout<<text<<endl;
				return text;
				}
		}
			return text;
		}
//	void destroy_list(LLnode * &header){
//			LLnode * temp1;
//			LLnode * temp2;
//			temp1 = header;
//			while(temp1){
//				temp2 = temp1->next;
//				delete temp1;
//				temp1 = temp2;
//			}
//			temp1 = NULL;
//		}
//	void destroy_list(){
//			LLnode * temp = header;
//			destroy_list(temp);
//		}
	void destroy_list(){
			LLnode * temp = header;
			LLnode * temp2;
			if(!temp){
				cout<<"nothing to destroy"<<endl;
				return;
			}
			while(temp){
				temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
			header = NULL;
		}
	bool search_list(T value){
		LLnode * temp;
		temp = header;
		while(temp){
			if(temp->content == value ){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool delete_node(T value){
		LLnode * temp = header;
		LLnode * temp2;
		if(header->content == value){
			temp2 = header->next;
			delete header;
			header = temp2;
		}
		while(temp){
			if(temp->content == value){
				temp2->next = temp->next;
				delete temp;
				return true;
			}
			temp2 = temp;
			temp = temp->next;
		}
		return false;
	}

//	virtual ~LL();
};

 /* namespace std */

#endif /* LL_HPP_ */
