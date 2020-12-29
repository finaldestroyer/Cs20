//============================================================================
// Name        : WunJaphethA04v2Fixed.cpp
// Author      : Japheth Wun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "LL.hpp"
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	LL <string> ll1;
		cout << "main: length of empty list - " << ll1.list_length() <<endl;
		cout << "main: trying to display empty list" << endl;
		ll1.display_list();
		cout << "main: trying to display initial size of ll1 - " << ll1.list_length() << endl;
		ll1.push_front("aaaaa");
		ll1.push_back("bbbbb");
		ll1.push_front("before aaaaa");
		ll1.push_back("after bbbbb");
		cout << "main: length of ll1 after 4 pushes - " << ll1.list_length() << endl;
		cout << "main: now trying to display ll1 after 4 push's" << endl;
		ll1.display_list();
		cout << "main: displaying final size of ll1 - " << ll1.list_length()<< endl;
		ll1.destroy_list();
		cout << "main: displaying size of list 1 after destroy - " << ll1.list_length() << endl;
		cout << endl;

		LL <string> ll2;
		ll2.push_front("33333");
		ll2.push_front("22222");
		ll2.push_front("11111");
		ll2.push_back("44444");
		ll2.push_back("55555");
		ll2.push_back("66666");
		cout << "main: now trying to display ll2 after 6 push's" << endl;
		ll2.display_list();
		cout << "main: now searching for node 44444" << endl;
		if (ll2.search_list("44444"))
		{
		cout <<"main: found node 44444" << endl;
		}
		else
		{
		cout << "main: did not find node 44444" << endl;
		}
		cout << "main: now searching for node 44445" << endl;
		if (ll2.search_list("44445"))
		{
		cout <<"main: found node 44445" << endl;
		}
		else
		{
		cout << "main: did not find node 44445" << endl;
		}
		cout << "main: now trying to delete node 44444" << endl;
		if (ll2.delete_node("44444"))
		{
		cout <<"main: node 44444 deleted" << endl;
		}
		else
		{
		cout << "main: did not find 44444 for delete" << endl;
		}
		if (ll2.search_list("44444"))
		{
		cout <<"main: searched for 44444 after delete, found" <<
		endl;
		}
		else
		{
		cout << "main: searched for 44444 after delete, not found" << endl;
		}
		cout << "main: displaying whole list after delete 44444" << endl;
		ll2.display_list();
		cout << "main: now trying to delete node 11111" << endl;
		if (ll2.delete_node("11111"))
		{
		cout <<"main: node 11111 deleted" << endl;
		}
		else
		{
		cout << "main: did not find node 11111 for delete" << endl;
		}
		cout << "main displaying whole list after delete 11111" << endl;
		ll2.display_list();
		ll2.destroy_list();

	return 0;
}
