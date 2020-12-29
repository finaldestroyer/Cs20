//============================================================================
// Name        : WunJaphethA06v3.cpp
// Author      : Japheth Wun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "AltQueue.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	int size,pgen,pend,ctick;
	cout<<"Enter size"<<endl;;
	cin>>size;
	cout<<"Enter pgen"<<endl;
	cin>>pgen;
	cout<<"Enter pend"<<endl;
	cin>>pend;
	cout<<"Enter ctick"<<endl;
	cin>>ctick;
	AltQueue c(size,pgen,pend,ctick);
	c.Program();
	c.report();
	return 0;
}
