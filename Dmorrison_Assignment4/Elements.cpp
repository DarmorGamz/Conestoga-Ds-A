/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/
#include "Elements.h"
#include <iostream>

Stack::Stack(int iTempdata) {
	data = iTempdata;
	pNext = NULL;
}

Stack* Stack::Push(Stack* tempStack) {
	// Add item to stack.
	tempStack->pNext = this;

	// Set Response.
	return tempStack;
}

Stack* Stack::Pop() {
	// Grab next item.
	Stack* temp = this->pNext;

	// Delete first item.
	delete this;

	// Set Response. Return second item.
	return temp;
}

void Stack::Display() { // Professor didn't specify if to print from last to first, or first to last. 
	// Create a copy of Head.
	Stack* temp = this;
	while (temp != NULL) {
		// Print data with comma.
		std::cout << temp->data;

		// Iterate stack.
		temp = temp->pNext;
		if (temp != NULL) std::cout << ", ";
	}

	std::cout << std::endl;
	
}

Queue::Queue(int iTempdata) {
	data = iTempdata;
	pNext = NULL;
}

Queue* Queue::Push(Queue* tempQueue) {
	// Add item to stack.
	tempQueue->pNext = this;

	// Set Response.
	return tempQueue;
}

Queue* Queue::Pop() {
	// Grab next item.
	Queue* front = this;
	Queue* temp = this;
	Queue* last = this;

	// Iterate to the start of queue.
	while (last->pNext != NULL) {
		last = last->pNext;
		if (last->pNext == NULL) continue;
		temp = last;
	}

	// Remove queue item.
	delete last;
	temp->pNext = NULL;

	// Set Response.
	return this;
}

void Queue::Display() { // Professor didn't specify if to print from last to first, or first to last. 
	// Create a copy of Head.
	Queue* temp = this;
	while (temp != NULL) {
		// Print data with comma.
		std::cout << temp->data;

		// Iterate stack.
		temp = temp->pNext;
		if (temp != NULL) std::cout << ", ";
	}

	std::cout << std::endl;

}