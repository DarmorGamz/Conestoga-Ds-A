/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

// Includes
#include <iostream>

// Constants
const int TABLE_SIZE = 10;

// Structures
struct Person {
	std::string name;
	int age;

	Person(std::string str, int value) : name(str), age(value) {};
};

struct keyValuePairT {
	std::string key;
	Person* value;

	keyValuePairT* next;
	keyValuePairT(std::string key, Person *value) {
		this->key = key;
		this->value = value;
		this->next = nullptr;
	}
};


//QUESTION:  What is the purpose of this table?  What does it hold?
// The purpose of the table is to hold n(TABLE_SIZE: 10) pointer's to Person structures. 
// This table holds the location in memory to the structs, not the actual Person structs data.
keyValuePairT** hash_table;

/**
*  Used to get index in hashtable.
*  @param String name Name to hash into an index.
*  @return unsigned int Returns index.
*/
unsigned int hash(std::string name) {
	int length = name.length();
	const char* ptmp = name.c_str();
	unsigned int hash_value = 0;

	for (int i = 0; i < length; i++) {
		hash_value += (unsigned int)*ptmp;

		//QUESTION:  What is the purpose of line 30 (just below)?
		// This is the Hash algo were using for a string. It iterates for the name length, index value hash name.length times. This is mod by Table_Size(10).
		hash_value = (hash_value * (unsigned int)*ptmp) % TABLE_SIZE;
		ptmp++;
	}

	return hash_value;
}

/*QUESTION: This hash function is designed to work with character strings. Do a quick
			search of the internet and find a hash function to support interger data.

uint64_t xorshift(const uint64_t& n,int i) {
  return n^(n>>i);
}
uint64_t hash(const uint64_t& n) {
  uint64_t p = 0x5555555555555555ull; // pattern of alternating 0 and 1
  uint64_t c = 17316035218449499591ull;// random uneven integer constant;
  return c*xorshift(p*xorshift(n,32),32);
}

NOTE:  This function does not have to be implemented, just give the algorithm
*/

/**
*  Helper function to initalize the hashtable.
*  @return void Returns nothing.
*/
void init_hash_table() {
	//QUESTION:  Why is it important to initialize your hash table elements to nullptr?
	// Without initalizing each element, when iterating through you can run into unexpected left over data, or
	// 'garbage' that was never cleaned up. This can affect your expected results and be difficult to debug.
	hash_table = new keyValuePairT*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++) {
		hash_table[i] = nullptr;
	}
}

/**
*  Helper function to print table formatted.
*  @return void Returns nothing.
*/
void print_hash_table() {
	// Loops through hashlist index and prints each list item.
	for(int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i] == nullptr) {
			std::cout << "\t" << i << " -----" << "\n";
		} else {
			std::cout << "\t" << i << " ";
			keyValuePairT* prev = nullptr;
			keyValuePairT* entry = hash_table[i];
			
			while(entry != nullptr) {
				prev = entry;
				entry = entry->next;
				std::cout << prev->value->name.c_str() << ", ";
			}
			std::cout << std::endl;
		}	
	}
	std::cout << std::endl;
}

/**
*  Inserts a Person struct into hashtable.
*  @param String name Name of Person struct to remove.
*  @return bool Returns success.
*/
bool hash_table_insert(Person* p) {
	// Shouldn't happen. Catchs invalid Person struct.
	if(p == nullptr) return false;

	// Init vars.
	int index = hash(p->name);
	keyValuePairT* prev = nullptr;
	keyValuePairT* entry = hash_table[index];

	// Loop through to end of list.
	while(entry != nullptr) {
		prev = entry;
		entry = entry->next;
	}

	// Add or Insert keypair.
	entry = new keyValuePairT(p->name, p);
	if(prev == nullptr) {
		hash_table[index] = entry;
	} else {
		prev->next = entry;
	}

	// Return success.
	return true;
}

/**
*  Look for a Person struct using name. returns nullptr if it doesnt exist..
*  @param String name Name of Person struct to remove.
*  @return Person* Returns struct of found person.
*/
Person* hash_table_lookup(std::string name) {
	// Init vars.
	bool flag = false;
	int index = hash(name);

	// Get first keypair at index.
	keyValuePairT* entry = hash_table[index];

	// Loop through and see if key(name) is in the linked list.
	while(entry != nullptr) {
		if (entry->key == name) {
			return entry->value;
		}
		entry = entry->next;
	}

	// Person was not found.
	return nullptr;
}

/**
*  Removes a Person struct from Hashtable if it exists.
*  @param String name Name of Person struct to remove.
*  @return Person* Returns struct of deleted KeyPair.
*/
Person* hash_table_delete(std::string name) {
	// Init vars.
	int index = hash(name);
	// Get first keypair at index.
	keyValuePairT* entry = hash_table[index];
	keyValuePairT* prev = nullptr;

	// Loop through hashtable index to find pair(name)
	while(entry != nullptr) {
		if(entry->value->name == name) break;
		prev = entry;
		entry = entry->next;
	}
	// Update ->next value to not lose end of list.
	if(prev != nullptr) {
		prev->next = entry->next;
	}	

	// Cleanup and return value if found.
	Person* tmp = entry->value;
	delete entry;
	return tmp;
}

/**
*  Main Program entry.
*  @return int Returns success.
*/
int main() {
	std::cout << "Joe" << "  " << hash("Joe") << std::endl;
	std::cout << "Jane" << "  " << hash("Jane") << std::endl;
	std::cout << "Elliott" << "  " << hash("Elliott") << std::endl;
	std::cout << "Conestoga" << "  " << hash("Conestoga") << std::endl;
	std::cout << "Franz" << "  " << hash("Franz") << std::endl;
	std::cout << "Jeff" << "  " << hash("Jeff") << std::endl;
	std::cout << "Sheng" << "  " << hash("Sheng") << std::endl;
	std::cout << "Wendy" << "  " << hash("Wendy") << std::endl;
	
	init_hash_table();
	print_hash_table();

	Person Joe("Joe", 50);
	Person Jane("Jane", 47);
	Person Elliott("Elliott", 43);
	Person Conestoga("Conestoga", 15);
	Person Franz("Franz", 55);
	Person Jeff("Jeff", 52);
	Person Sheng("Sheng", 40);
	Person Wendy("Wendy", 13);

	hash_table_insert(&Joe);
	hash_table_insert(&Jane);
	hash_table_insert(&Elliott);
	hash_table_insert(&Conestoga);
	hash_table_insert(&Franz);
	hash_table_insert(&Jeff);
	hash_table_insert(&Sheng);
	hash_table_insert(&Wendy);
	print_hash_table();

	return 1;
}