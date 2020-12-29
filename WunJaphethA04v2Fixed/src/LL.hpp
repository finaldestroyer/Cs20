/*
 * LL.hpp
 *
 *  Created on: Oct 2, 2019
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
			LLnode * next = NULL;
		};
		LLnode * header;
public:
	LL(){
		header = NULL;
	}
	void display_list(LLnode * temp){
		if(temp){
			cout<<temp->content<<endl;
			display_list(temp->next);
		}
		else{
			return;
		}
	}
	void display_list(){
		if(!header){
			cout<<"No nodes"<<endl;
			return;
		}
		LLnode * temp;
		temp = header;
		display_list(temp);
	}
	int list_length(int count, LLnode * header){
			if(!header)
			{
				return count;
			}
			LLnode * temp;
			temp = header;
			if(temp)
			{
				count++;
				temp = temp -> next;
				return list_length(count,temp);
			}
			return count;
		}
	int list_length (){
		int count = 0;
		LLnode * temp;
		temp = header;
		return list_length(count,temp);
	}
	void push_front(T text){
			LLnode * temp;
			temp = header;
			LLnode * newL = new LLnode;
			newL->content = text;
			newL -> next = temp;
			header = newL;
		}
	void push_back(T text, LLnode * temp){
		if(temp->next != NULL)
		{
			push_back(text,temp->next);
		}
		if(temp->next == NULL){
			LLnode * newL = new LLnode;
			newL->content = text;
			temp->next = newL;
		}
	}
	void push_back(T text){
		if(header == NULL){
			LLnode*	temp = new LLnode;
			temp->content = text;
			header = temp;
			return;
		}
		LLnode * temp;
		temp = header;
		if(temp){
			push_back(text,temp);
		}
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
	string retrieve_back(LLnode * temp){
		string text = "";
		if(temp->next)
		{
			return retrieve_back(temp->next);
		}
		if(!temp->next){
			text = temp->content;
			return text;
		}
		return text;
	}
	string retrieve_back(){
		if(header == NULL){
			return NULL;
		}
		LLnode * temp;
		temp = header;
		return retrieve_back(temp);
	}
	void destroy_list(LLnode * temp, LLnode * temp2){
		if(!temp){
			return;
		}
		if(temp){
			temp2 = temp->next;
			delete temp;
			temp = temp2;
			destroy_list(temp,temp2);
		}
	}
	void destroy_list(){
		if(!header){
			cout<<"nothing to delete"<<endl;
		}

		LLnode * temp = header;
		LLnode * temp2 = temp;
		destroy_list(temp,temp2);

		header = NULL;
	}
	bool search_list(T value, LLnode * temp){
		if(temp){
			if(temp->content == value ){
				return true;
			}
			temp = temp->next;
			return search_list(value,temp);
		}
		else{
			return false;
		}
	}
	bool search_list(T value){
		if(header->content == value){
			return true;
		}
		LLnode * temp;
		temp = header;
		return search_list(value,temp);
	}
	bool delete_node(T value, LLnode * temp, LLnode * temp2){
		if(temp){
			if(temp->content == value){
				temp2->next = temp->next;
				delete temp;
				return true;
			}
			temp2 = temp;
			temp = temp->next;
			return delete_node(value, temp, temp2);
		}
		else{
			return false;
		}
	}
	bool delete_node(T value){
		if(header->content == value){
			LLnode * temp;
			temp = header->next;
			delete header;
			header = temp;
			return true;
		}
		LLnode * temp = header;
		LLnode * temp2 = temp;
		return delete_node(value,temp,temp2);
	}

	//virtual ~LL();
};

#endif /* LL_HPP_ */
