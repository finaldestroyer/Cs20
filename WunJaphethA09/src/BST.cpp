/*
 * BST.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: student
 */

#include "BST.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

BST::BST() {
	// TODO Auto-generated constructor stub
	root  = nullptr;
}
bool BST::search(int & value)
{
	Treenode * current;
	bool found = false;
	if (root == nullptr)
	{
		cout << "search: tree is empty" << endl;
		exit (1);
	}
	else
	{
		current = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else if (current->nodeValue > value)
			{
				current = current->Lchild;
			}
			else
			{
				current = current->Rchild;
			}
		}
	}
	return found;
}
void BST::udelete(int & value)
{
	Treenode * current; 		// pointer to node we're looking at
	Treenode * trailing; 		// trailing pointer to parent

	bool found = false;
	if (root == NULL)
	{
		cout << "udelete:  empty tree" << endl;
		exit (1);
	}
	else
	{
		current = root;
		trailing = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else
			{
				trailing = current;
				if (current->nodeValue > value)
				{
					current = current->Lchild;
				}
				else
				{
					current = current->Rchild;
				}
			}
		}
		if (current == nullptr)
		{
			cout << "udelete:  not found" << endl;
		}
		else if (found)
		{
			if (current == root)
			{
				deleteInternal(root);
			}
			else if (trailing->nodeValue > value)
			{
				deleteInternal(trailing->Lchild);
			}
			else
			{
				deleteInternal(trailing->Rchild);
			}
		}
	}
}
void BST::deleteInternal (Treenode * &p)
{
	Treenode * current;			// pointer to node we're looking at
	Treenode * trailing;		// trailing pointer to parent
	Treenode * temp;			// temp pointer for delete

	if (p == nullptr)
	{
		cout << "delete: null node" << endl;
		exit(1);
	}
	else if(p->Lchild == nullptr && p->Rchild == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if(p->Lchild == nullptr)
	{
		temp = p;
		p = temp->Rchild;
		delete temp;
	}
	else if(p->Rchild == nullptr)
	{
		temp = p;
		p = temp->Lchild;
		delete temp;
	}
	else
	{
		current = p->Lchild;
		trailing = nullptr;
		while (current->Rchild != nullptr)
		{
			trailing = current;
			current = current->Rchild;
		}
		p->nodeValue = current->nodeValue;
		if (trailing == NULL)
		{
			p->Lchild = current->Lchild;
		}
		else
		{
			trailing->Rchild = current->Lchild;
		}
		delete current;

	}
}
void BST::traverseInOrder()
{
	traverseInOrderInternal(root);
}
void BST::traversePreOrder()
{
	traversePreOrderInternal(root);
}
void BST::traversePostOrder()
{
	traversePostOrderInternal(root);
}
void BST::print2D()
{
    print2DInternal(root, 0);
}
void BST::traverseLevelOrder()
{
    int level = 1;
    while (traverseLevelOrderInternal(root,level))
    {
    	cout << endl;
        level++;
    }
}
void BST::traverseInOrderInternal(Treenode * p)
{
	if (p == nullptr)
	{
		cout << "enter inorder with null" << endl;
	}
	else
	{
		cout << "enter inorder " << p ->nodeValue << endl;
	}
	if (p != nullptr)
	{
		traverseInOrderInternal(p->Lchild);
		cout << p->nodeValue << endl;
		traverseInOrderInternal(p->Rchild);
	}
}
void BST::traversePreOrderInternal(Treenode * p)
{
	if (p != nullptr)
	{
		cout << p->nodeValue << endl;
		traversePreOrderInternal(p->Lchild);
		traversePreOrderInternal(p->Rchild);
	}
}
void BST::traversePostOrderInternal(Treenode * p)
{
	if (p != nullptr)
	{
		traversePostOrderInternal(p->Lchild);
		traversePostOrderInternal(p->Rchild);
		cout << p->nodeValue << endl;
	}
}
bool BST::traverseLevelOrderInternal(Treenode * p, int level)
{
    if (p == nullptr)
        return false;
    if (level == 1)
    {
    	cout << p->nodeValue << "   ";
    	return true;
    }
    bool l = traverseLevelOrderInternal(p->Lchild, level-1);
    bool r = traverseLevelOrderInternal(p->Rchild, level-1);
    return l || r;
}
void BST::print2DInternal(Treenode *root, int space)
{
	int count=8;
    if (root == NULL)
        return;
    space += count;
    print2DInternal(root->Rchild, space);	// process right (top of page)
    cout<<endl;								// display node after spacing
    for (int i = count; i < space; i++)
        cout<<" ";
    cout<<root->nodeValue<<"("<<root->bf<<")"<<"\n";
    print2DInternal(root->Lchild, space);	// process left (bottom of page)
}
int BST::height()
{
	return heightInternal(root);
}
int BST::heightInternal(Treenode* p)
{
	if (p != nullptr)
	{
		int lh, rh;
		lh = heightInternal(p->Lchild);
		rh = heightInternal(p->Rchild);
		if (lh > rh)
		{
			lh++;
			return lh;
		}
		else
		{
			rh++;
			return rh;
		}
	}
	else
	{
		return -1;
	}
}
void BST::insert(Treenode * leaf, int &a){
	Treenode * trav;
	while(leaf){
		trav = leaf;
		if(leaf->nodeValue == a){
			throw a;
		}
		else if(leaf->nodeValue > a){
			leaf = leaf->Lchild;
		}
		else if(leaf->nodeValue < a){
			leaf = leaf->Rchild;
		}
	}
	Treenode * temp = new Treenode;
	temp->nodeValue = a;
	if(trav->nodeValue > a){
		trav->Lchild = temp;
	}
	if(trav->nodeValue < a){
		trav->Rchild = temp;
	}
}
void BST::insert(int &a){
	Treenode * temp;
	if(root == NULL){
		temp = new Treenode;
		temp->nodeValue = a;
		root = temp;
		return;
	}
	temp = root;
	insert(temp,a);
}
void BST::setallBFInternal(Treenode * leaf){
	if (leaf != nullptr){
		int lLeaf, rLeaf;
		lLeaf=heightInternal(leaf->Lchild);
		rLeaf=heightInternal(leaf->Rchild);
		leaf->bf=rLeaf-lLeaf;
		setallBFInternal(leaf->Lchild);
		setallBFInternal(leaf->Rchild);
		return;
	 }
}
void BST::setallBF(){
	setallBFInternal(root);

}
int BST::getLargestBFInternal(Treenode * leaf){
	if (leaf != nullptr){
		int lLeaf, rLeaf;
		lLeaf=getLargestBFInternal(leaf->Lchild);
		rLeaf=getLargestBFInternal(leaf->Rchild);
		if (abs(leaf->bf)>abs(lLeaf)){
			lLeaf=leaf->bf;
		}
		else if(abs(leaf->bf)>abs(rLeaf)){
			rLeaf=leaf->bf;
		}
		if (abs(lLeaf)>abs(rLeaf)){
			return lLeaf;
		}
		else{
			return rLeaf;
		}
	}
	else{
		return 0;
	}
}
int BST::getLargestBF(){
	return getLargestBFInternal(root);
}


BST::~BST() {
	// TODO Auto-generated destructor stub
}

