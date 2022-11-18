/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/
#include <iostream>
#include "Elements.h"

using namespace std;

int main()
{
	Stack* pSHead = new Stack(5);
	Stack* p1 = new Stack(10);
	Stack* p2 = new Stack(15);
	Stack* p3 = new Stack(20);

	pSHead = pSHead->Push(p1);
	pSHead = pSHead->Push(p2);
	pSHead = pSHead->Push(p3);
	pSHead->Display();

	pSHead = pSHead->Pop();
	pSHead = pSHead->Pop();
	pSHead->Display();

	cout << endl;

	Queue* pQHead = new Queue(5);
	Queue* p4 = new Queue(10);
	Queue* p5 = new Queue(15);
	Queue* p6 = new Queue(20);

	pQHead = pQHead->Push(p4);
	pQHead = pQHead->Push(p5);
	pQHead = pQHead->Push(p6);
	pQHead->Display();

	pQHead = pQHead->Pop();
	pQHead = pQHead->Pop();
	pQHead->Display();

	return 1;
}