/*
 * AltQueue.hpp
 *
 *  Created on: Oct 23, 2019
 *      Author: student
 */

#ifndef ALTQUEUE_HPP_
#define ALTQUEUE_HPP_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class AltQueue {
private:
	struct Transaction{
		int ID;							//transaction ID   - string
		int workUnit;					//work units  - int
		Transaction * next;
	};
	Transaction * q;
	int clock, qSize, probGen, probEnd, clockTick, end, front, index;
	bool transStart = false;

	//	Reported Variables
	int transactionsGenerated = 0;
	int transactionsProcessed = 0;
	int transactionsStarted = 0;
	int unprocessedTrans = 0;
//	Transaction * queue[];
public:
	AltQueue(int,int,int,int);
	bool Full();
	bool Empty();

	void EnQueue(int);
	void DeQueue();

	void Program();
	void Display();
	void report();


//	virtual ~AltQueue();
};


#endif /* ALTQUEUE_HPP_ */
