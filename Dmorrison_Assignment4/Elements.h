/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/
#ifndef ELEMENTS_H_
#define ELEMENTS_H_

class Stack {

private:
	int data;
	Stack* pNext;

public:
	Stack(int);
	Stack* Push(Stack*);
	Stack* Pop();
	void Display();
};

class Queue {

private:
	int data;
	Queue* pNext;

public:
	Queue(int);
	Queue* Push(Queue*);
	Queue* Pop();
	void Display();
};

#endif