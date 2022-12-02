/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "Task.h"
#include <iostream>

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
Task::Task(std::string name) { // TODO Does there need to be an inital quantity to the inventory.
	this->Name = name;

	// Each task gets 1 item to start. Should add a Random number?
	Item* temp = new Item();
	temp->Name = name;
	this->Inventory.push(temp);

	Item* temp2 = new Item();
	temp2->Name = name;
	this->Inventory.push(temp2);

	Item* temp3 = new Item();
	temp3->Name = name;
	this->Inventory.push(temp3);
}

/**
* Using FIFO determine if the next item in the queue needs this Task's component. Do something about it, and set it's status.
* @return void No return value.
*/
void Task::Run() {
	if(!this->ProdQ.empty()) {
		// Gets next ready item in queue.
		Product* tempProduct = this->ProdQ.front();
		int index = -1;
		for(int i = 0; i < 8; i++) { // TODO break this loop if item is found to be faster.
			if(tempProduct->Components[i].Name == this->Name) {
				if (!this->Inventory.empty()) { // If this inventory isn't empty.
					this->Inventory.pop(); // Takes a component out of the inventory and puts it on the product.
					tempProduct->Components[i].SN = tempProduct->SN; // Update the part to match the product.
					if (tempProduct->status != BackOrdered) { // Dont override a backorder status.
						tempProduct->status = Status::Ready; // Udpate Status;
					}
				} else {
					tempProduct->status = Status::BackOrdered; // Udpate Status;
				}
			}
		}
		if(tempProduct->status != BackOrdered) { // Dont override a backorder status.
			tempProduct->status = Status::Ready; // Udpate Status;
		}
	}
}

/**
* Using FIFO determine if the next item in the queue is ready to move. Pop it from the queue.
* @return void No return value.
*/
Product* Task::MoveProduct() {
	if(!this->ProdQ.empty()) {
		Product* tempProduct = this->ProdQ.front();
		if(tempProduct->status == Status::Ready || tempProduct->status == Status::BackOrdered) {
			this->ProdQ.pop(); // Remove product from this queue.
			return tempProduct;
		}
		return nullptr; // Item is not Ready.
	} else {
		return nullptr; // No items in queue.
	}
}

/**
* Using FIFO add a product to the end of the queue.
* @param Product* pProduct pointer to Product structure instance.
* @return void No return value.
*/
void Task::AddProduct(Product* pProduct) {
	this->ProdQ.push(pProduct);
}