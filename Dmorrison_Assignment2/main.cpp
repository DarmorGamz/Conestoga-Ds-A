/********************************************
Author: Darren Morrison
Email: dmorriosn8832@conestogac.on.ca
SN: 8258832
*********************************************/

// Includes.
#include <string>
#include <iostream>
#include <iomanip>

// Classes
class Record {
public:
	int iStudentNumber;
	int iMark;
	std::string sName;
	std::string sProgram;
	Record* pNext;
};

// Prototypes.
bool Check(Record**, int);
void Insert(Record**, int, std::string, std::string, int);
void Search_Record(Record**, int);
void Display(Record**);
void Delete(Record**, int);

// Methods.
int main() {
	Record* head = NULL;

	bool bLoop = true; 
	while(bLoop) {
		std::cout << "Please enter your selection!\n1: Insert new record.\n2: Delete student record.\n3: Search a student record.\n4: Display all Student Record.\n5: Exit program.\n: ";
		int selection = 0;
		std::cin >> selection;

		std::string name = "";
		std::string program = "";
		switch(selection) {
			case 1:	// Insert new record.
				std::cout << "Please enter student name: ";
				std::cin >> name;
				std::cout << "Please enter student number: ";
				int number;
				std::cin >> number;
				std::cout << "Please enter student program: ";
				std::cin >> program;
				std::cout << "Please enter student mark: ";
				int mark;
				std::cin >> mark;
				Insert(&head, number, name, program, mark);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "Please enter student number to delete: ";
				int iNum2;
				std::cin >> iNum2;
				std::cout << std::endl;
				Delete(&head, iNum2);
				std::cout << std::endl;
				break;
			case 3: // Search student record.
				std::cout << "Please enter student number to search for: ";
				int iNum;
				std::cin >> iNum;
				std::cout << std::endl;
				Search_Record(&head, iNum);
				std::cout << std::endl;
				break;
			case 4: // Display Records.
				std::cout << std::endl;
				Display(&head);
				std::cout << std::endl;
				break;
			case 5: // Exit Program.
				bLoop = false;
				break;
		}
	}

	// Return success.
	return true;
}


bool Check(Record** head, int number) {
	// Loop through list if not NULL, and verify if number is in list.

	Record* last = *head;
	while(last != NULL) {
		if((*head)->iStudentNumber == number) return true;
		last = last->pNext;
	}

	// Set response.
	return false;
}

void Insert(Record** head, int number, std::string name, std::string program, int mark) {
	if(!Check(head, number)) {
		Record* new_record = new Record();

		Record* last = *head;

		new_record->iStudentNumber = number;
		new_record->sName = name;
		new_record->sProgram = program;
		new_record->iMark = mark;
		new_record->pNext = NULL;

		if((*head) == NULL) { // No items in record node.
			(*head) = new_record;
			return;
		}

		// Increments to last item.
		while(last->pNext != NULL) {
			last = last->pNext;
		}

		// Insert new item.
		last->pNext = new_record;
	}
}

void Search_Record(Record** head, int number) {
	if(Check(head, number)) {
		// Table header.
		std::cout << std::left << std::setw(15) << "Student No." << std::left << std::setw(25)
			<< "Name" << std::left << std::setw(15) << "Program" << std::left << std::setw(3) << "Mark" << std::endl;

		// Table Row.
		std::cout << std::left << std::setw(15) << (*head)->iStudentNumber << std::left << std::setw(25)
			<< (*head)->sName << std::left << std::setw(15) << (*head)->sProgram << std::left << std::setw(3) << (*head)->iMark << std::endl;
	} else {
		std::cout << "RECORD NOT FOUND!" << std::endl;
	}
}

void Display(Record** head) {
	// Print Header of table.
	std::cout << std::left << std::setw(15) << "Student No." << std::left << std::setw(25)
		<< "Name" << std::left << std::setw(15) << "Program" << std::left << std::setw(3) << "Mark" << std::endl;

	Record* last = *head;
	while ((last) != NULL) {
		// Print table row.
		std::cout << std::left << std::setw(15) << last->iStudentNumber << std::left << std::setw(25)
			<< last->sName << std::left << std::setw(15) << last->sProgram << std::left << std::setw(3) << last->iMark << std::endl;

		// Get next node.
		last = last->pNext;
	}
}

void Delete(Record** head, int number) {
	if(Check(head, number)) {
		if((*head)->pNext == NULL) { (*head) = NULL; return; }
		if ((*head)->iStudentNumber == number) { (*head) = (*head)->pNext; return; }
		Record* temp = (*head)->pNext;
		Record* prev = *head;

		while(temp != NULL) {
			if(temp->iStudentNumber == number) {
				if(temp->pNext == NULL) { // At the end.
					prev->pNext = NULL;
				} else {
					prev->pNext = temp->pNext;
				}
				temp = NULL;
				return;
			}
			prev = temp;
			temp = temp->pNext;
		}
	}
}