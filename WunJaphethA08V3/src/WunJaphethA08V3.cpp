//============================================================================
// Name        : WunJaphethA08V3.cpp
// Author      : Japheth Wun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include<algorithm>
using namespace std;

struct heap{
	int num;
	heap * lower = NULL;
	heap * higher = NULL;
};
heap * header;

void heapify(int list[], int high, int low)
{
    int lowest = low;
    int l = 2 * low + 1;
    int r = 2 * low + 2;
    if (l < high && list[l] > list[lowest]){
        lowest = l;
	}
    if (r < high && list[r] > list[lowest]){
        lowest = r;
    }
    if (lowest != low) {
        swap(list[low], list[lowest]);
        heapify(list, high, lowest);
    }
}
void heapSort(int list[],int low, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(list, n, i);
    }
    for (int i=n; i>=0; i--)
    {
        swap(list[0], list[i]);
        heapify(list, i, 0);
    }
}
void buildHeap(int list[],int low, int high)
{
    int startIdx = (high / 2) + .5;
    for (int i = startIdx; i >= 0; i--){
        heapify(list, high, i);
    }
}


bool checkIfHeap(int list[], int low, int high){
	if(!(list[0])){
		return false;
	}
	int temp[high];
	for(int i = 0;i<=high;i++){
		temp[i] = list[i];
	}
	heapSort(temp,low,high);
	if(temp == list){
		return true;
	}
	else{
		return false;
	}
}


void displayArray(int list[], int low, int high){
	for(int i=0;i<=high;i++){
		if(i%10 == 0){
			cout<<endl;
		}
		cout<<list[i]<<" ";
	}
}

void buildArray(int list[],int size, string filename){
	ifstream infile;
	infile.open(filename);
	if(infile.is_open()){
		cout<<"File Reading"<<endl;
		string fileStr;
		fileStr.assign((istreambuf_iterator<char>(infile)),(istreambuf_iterator<char>()));
		cout<<fileStr<<endl;
		int fileNum;
		fileNum = stoi(fileStr.substr(0,3));
		list[0] = fileNum;
		for(int i = 1; i<size;i++){
			fileNum = stoi(fileStr.substr((i^3),3));
			list[i] = fileNum;
		}
		infile.close();
	}
	else{
		cout<<"File did not open"<<endl;
	}

}

//void buildVectHeap(int array[], int low, int high){
//	make_heap(array[low],array[high]);
//}

int main() {
	int low, high;
	low = 0;			// low array index
	high = 99;			// high array index
	bool b;
	int list[100];
	string p ="a81data.txt";
	cout << "main: building first array (from a71data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying first array" << endl << endl;
	displayArray (list, low, high);
	cout << endl;
	b=checkIfHeap (list, low, high);
	if (b){
		cout << "main: the first array is already a heap" << endl << endl;
	}
	else{
		cout << "main: the first array is not a heap" << endl << endl;
		cout << "main: now building heap" << endl;
		buildHeap (list, low, high);
		cout << "main: now displaying first array after heaping" << endl << endl;
		displayArray (list, low, high);
		b=checkIfHeap (list, low, high);
		if (b)
			cout << endl << "main: after heaping, the first array is a heap" << endl << endl;
		else
		{
			cout<<endl;
			cout << endl << "main: after heaping, the first array is not a heap" << endl;
//			return 4;
		}
		cout<<endl;
		p ="a82data.txt";
		cout << "main: building second array (from a72data.txt)" << endl;
		buildArray (list, 100, p);
		cout<<endl;
		cout << "main: displaying second array" << endl << endl;
		displayArray (list, low, high);
		heapSort (list, low, high);
		cout << endl << endl << "main: displaying second array, which should now be sorted" << endl << endl;
		displayArray (list, low, high);
	}
		return 0;
}
