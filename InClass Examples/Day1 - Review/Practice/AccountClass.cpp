#include <iostream>
#include "Account.h"


int main() {
	// Init vars.
	Account* oAccount1 = new Account(); Account* oAccount2 = new Account();
	if(!oAccount1->init("Darren", 123456, 98)) { return false; }
	if(!oAccount2->init("Carter", 24554, -1)) { return false; }

	// Display Account values.
	oAccount1->display();
	oAccount2->display();

	// Return Success.
	return 1;
}