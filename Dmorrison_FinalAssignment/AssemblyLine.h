/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

#ifndef ASSEMBLYLINE_H_
#define ASSEMBLYLINE_H_

/** INCLUDES ******************************************************************/
#include "Task.h"
#include "Product.h"


/** CLASSES, STRUCTURES AND ENUMERATIONS *************************************/
class AssemblyLine {
	private:
		Task* pTask;
		AssemblyLine* pNext;
	public:
		AssemblyLine(Task*);
		bool Push(AssemblyLine*);
		void Run();
		Product* MoveProduct();
		void AddProduct(Product*);
};

extern AssemblyLine* Head;

#endif /* ASSEMBLYLINE_H_ */