/*
 * AltQueue.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: student
 */

#include "AltQueue.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

AltQueue::AltQueue(int size,int probG,int probE,int clockT) {
	// TODO Auto-generated constructor stub
	clock = 0;
	index = 0;
	end = qSize-1;
	front = 0;
	qSize = size;
	probGen = probG;
	probEnd = probE;
	clockTick = clockT;
	q = new Transaction[size];
}

bool AltQueue::Empty(){
	if(index == 0){
		return true;
	}
	else{
		return false;
	}
}
bool AltQueue::Full(){
	if(index == qSize){
		return true;
	}
	else{
		return false;
	}
}
void AltQueue::EnQueue(int x){
	if(Full()){
		return;
	}
	else{
		end = (end+1)%qSize;
		q[end].workUnit = x;
		index++;
	}
}
void AltQueue::DeQueue(){
	if(Empty()){
		return;
	}
	else{
		front=(front+1)%qSize;
		index--;
	}
}



void AltQueue::Program(){
	while(clock<clockTick){
		srand(time(0));
		int x = rand() % 100+1;
		if(x <= probGen){
			EnQueue(x);
			transactionsGenerated++;
			index++;
		}
		if(clock<clockTick){
//		processing:
		if(transStart == false){
			transStart = true;
			DeQueue();
			transactionsStarted++;
		}
//		leaving:
		if(transStart == true){
			if(x <probEnd){
				transStart = false;
				transactionsProcessed++;
			}
		}
		clock++;
		}
	}
}

void AltQueue::Display(){
	for(int i=0;i<qSize;i++){
		cout<<q<<endl;
	}
}

void AltQueue::report(){
//	# clock ticks
//	# transactions generated
//	# transactions started
//	# transactions processed
//	# completed transactions
// 	# unprocessed transactions;
	int i;
	i = clock;
	cout<<"Count Ticks: "<<i<<endl;
	i = transactionsGenerated;
	cout<<"Transactions generated: "<<i<<endl;
	i = transactionsStarted;
	cout<<"Transactions started: "<<i<<endl;
	i = transactionsProcessed;
	cout<<"Transactions processed: "<<i<<endl;
	i = unprocessedTrans;
	cout<<"Unprocessed transactions: "<<i<<endl;

}

//AltQueue::~AltQueue() {
//	// TODO Auto-generated destructor stub
//}

