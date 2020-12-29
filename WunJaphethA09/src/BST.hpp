/*
 * BST.hpp
 *
 *  Created on: Nov 18, 2019
 *      Author: student
 */

#ifndef BST_HPP_
#define BST_HPP_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
using namespace std;

class BST {
private:
	struct Treenode
	{
		int nodeValue;
		int bf = 0;									//Balance Factor
		Treenode * Lchild = NULL;
		Treenode * Rchild = NULL;
	};
	Treenode * root;

	void traverseInOrderInternal(Treenode *);		// internal functions - all by subtree
	void traversePreOrderInternal(Treenode *);
	void traversePostOrderInternal(Treenode *);
	bool traverseLevelOrderInternal(Treenode *, int);
	void print2DInternal(Treenode *, int);

	void deleteInternal (Treenode * &);				// internal delete function

	int heightInternal(Treenode *);					// internal BF functions
	void setallBFInternal(Treenode *);
	int getLargestBFInternal(Treenode *);

public:

	BST();
	void insert(Treenode*, int&);
	void insert (int &);				// user functions - all whole tree
	bool search (int &);
	void udelete (int &);

	void setallBF();					// sets BF for whole tree
	int height();						// height of whole tree
	int getLargestBF();					// largest BF in whole tree

	void traverseLevelOrder();			// traversal functions
	void print2D();
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();

	virtual ~BST();
};

#endif /* BST_HPP_ */
