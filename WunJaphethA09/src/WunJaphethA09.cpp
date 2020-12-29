//============================================================================
// Name        : WunJaphethA09.cpp
// Author      : Japheth wun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "BST.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

//	https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

int main() {
	BST mytree;
		int i;
		bool b;

	/* start with this small tree and test code
	// will be easier to debug
		i=5;
		mytree.insert(i);
		i=8;
		mytree.insert(i);
		i=3;
		mytree.insert(i);
		i=12;
		mytree.insert(i);
		i=9;
		mytree.insert(i);
		mytree.print2D();
		mytree.setallBF();
		cout << "-------------------------------------------" << endl;
		mytree.print2D();
		cout <<" largest BF " << mytree.getLargestBF() << endl;
		i = 9;
		b = mytree.search(i);
		if (b)
			cout << "search for 9 successful" << endl;
		else
			cout << "search for 9 not successful" << endl;
		return 0;
	*/

	// use this code and tree when the small tree is working
		int array[14] = {60,50,70,30,53,80,35,57,75,32,40,77,48,45};
		for (int i=0;i<14;i++)
		{
			mytree.insert(array[i]);
		}



	/*
		cout << "traverse inorder" << endl;
		mytree.traverseInOrder();
		cout << "traverse preorder" << endl;
		mytree.traversePreOrder();
		cout << "traverse postorder" << endl;
		mytree.traversePostOrder();
	*/
		mytree.print2D();
		cout << "-------------------------------------------" << endl;
		mytree.setallBF();
		mytree.print2D();
		cout <<" largest BF " << mytree.getLargestBF() << endl;
		cout << "-------------------------------------------" << endl;
		i = 46;
		mytree.insert(i);
		i = 47;
		mytree.insert(i);
		mytree.setallBF();
		mytree.print2D();
		cout <<" largest BF " << mytree.getLargestBF() << endl;
		cout << "-------------------------------------------" << endl;
		i=45;
		mytree.udelete(i);
		mytree.setallBF();
		mytree.print2D();
		i = 53;
		b = mytree.search(i);
		if (b)
			cout << "search for 53 successful" << endl;
		else
			cout << "search for 53 not successful" << endl;
		return 0;
}
