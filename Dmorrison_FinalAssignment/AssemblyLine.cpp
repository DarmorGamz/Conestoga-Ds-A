/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "AssemblyLine.h"

/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/
AssemblyLine* Head = nullptr;

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
AssemblyLine::AssemblyLine(Task* pTask) {
	this->pTask = pTask;
	this->pNext = nullptr;
}

/**
* Adds a AssemblyLine object to the end of the Linked List.
* @param AssemblyLine* pAssemblyLine pointer to AssemblyLine object.
* @return bool Success result.
*/
bool AssemblyLine::Push(AssemblyLine* pAssemblyLine) {
	// Shouldn't happen.
	if(pAssemblyLine == nullptr) { return false; }

	// Check if Head is empty. Saves space by not creating more instances below.
	if(Head == nullptr) {
		Head = pAssemblyLine;
		return true;
	}

	// Loop through until the back is found.
	AssemblyLine* tPrev = nullptr;
	AssemblyLine* tEntry = Head;
	while(tEntry != nullptr) {
		tPrev = tEntry;
		tEntry = tEntry->pNext;
	}

	// Add the object to the end of the list.
	tPrev->pNext = pAssemblyLine;

	// Return Success.
	return true;
}

/**
* Interface function for the Task Class's Run() function.
* @return void No return value.
*/
void AssemblyLine::Run() {
	this->pTask->Run();
}

/**
* Interface function for the Task Class's MoveProduct() function.
* @return Product* Returns a pointer to a product object. *Note, Can be nullptr.
*/
Product* AssemblyLine::MoveProduct() {
	return this->pTask->MoveProduct();	
}

/**
* Adds a product to the current AssemblyLine object's Task Queue.
* @param Product* pProduct pointer to Product structure instance.
* @return void No return value.
*/
void AssemblyLine::AddProduct(Product* pProduct) {
	this->pTask->AddProduct(pProduct);
}