/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "AssemblyLine.h"

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**
*  Main Program entry.
*  @return int Return success.
*/
int main() {
    // Create array of Products. Task will be created based on this list.
	const char* products[] = { "CPU", "GPU", "RAM", "Monitor", "Controller", "VR Headset", "AR Glasses" };
    int ProductArrayLength = (sizeof(products) / sizeof(char*));

    // Add all the Tasks to the AssemblyLine.
    if(ProductArrayLength > 0) { // Skips if there are no Product Tasks to add.
        for(int i = 0; i < ProductArrayLength; i++) {
            Head->Push(new AssemblyLine(new Task((std::string)products[i])));
        }
    }

    // Return Success.
    return 1;
}