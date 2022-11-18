/********************************************
Author: Darren Morrison
Email: dmorrison9932@conestogac.on.ca
SN: 8258832
*********************************************/

#include <iostream>

class Record {

public:
	std::string lastName;
	std::string firstName;
	int mark;
	int number;
};

Record* InsertionSort(Record array1[], int n);
Record* BubbleSort(Record array2[], int n);
Record* MergeSort(Record array1[], Record array2[], int n1, int n2);
void PrintRecords(Record array[], int n);

int main() {
    Record records[2];
    Record records2[3];
    std::cout << "RECORD 1:" << std::endl;
    for(int i = 0; i < 2; i++) {
        std::cout << "Please enter student " << (i + 1) << "'s First Name: ";
        std::string firstName = "";
        std::cin >> firstName;
        records[i].firstName = firstName;

        std::cout << "Please enter student " << (i + 1) << "'s Last Name: ";
        std::string lastName = "";
        std::cin >> lastName;
        records[i].lastName = lastName;

        std::cout << "Please enter student " << (i + 1) << "'s Student Number: ";
        int studentNumber = 0;
        std::cin >> studentNumber;
        records[i].number = studentNumber;

        std::cout << "Please enter student " << (i + 1) << "'s Mark: ";
        int mark = 0;
        std::cin >> mark;
        records[i].mark = mark;
    } 
    std::cout << "RECORD 2:" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "Please enter student " << (i + 1) << "'s First Name: ";
        std::string firstName = "";
        std::cin >> firstName;
        records2[i].firstName = firstName;

        std::cout << "Please enter student " << (i + 1) << "'s Last Name: ";
        std::string lastName = "";
        std::cin >> lastName;
        records2[i].lastName = lastName;

        std::cout << "Please enter student " << (i + 1) << "'s Student Number: ";
        int studentNumber = 0;
        std::cin >> studentNumber;
        records2[i].number = studentNumber;

        std::cout << "Please enter student " << (i + 1) << "'s Mark: ";
        int mark = 0;
        std::cin >> mark;
        records2[i].mark = mark;
    }

    std::cout << "RECORD 1 sorted with InsertionSort:" << std::endl;
    InsertionSort(records, 2);
    PrintRecords(records, 2);
    
    std::cout << "RECORD 2 sorted with BubbleSort:" << std::endl;
    BubbleSort(records2, 3);
    PrintRecords(records2, 3);

    std::cout << "RECORD 3 merged with MergeSort:" << std::endl;
    Record* array3 = MergeSort(records, records2, 2, 3);
    PrintRecords(array3, 5);
}

Record* InsertionSort(Record array1[], int n) {
    int i, j;
    Record key;
    for (i = 1; i < n; i++) {
        key = array1[i];
        j = i - 1;

        while(j >= 0 && array1[j].lastName > key.lastName) {
            array1[j + 1] = array1[j];
            j = j - 1;
        }
        array1[j + 1] = key;
    }
    return array1;
}
Record* BubbleSort(Record array2[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(array2[j].lastName > array2[j + 1].lastName) {
                Record temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;
            }
        }
    } 
    return array2;
}

Record* MergeSort(Record array1[], Record array2[], int n1, int n2) {
    Record* array3 = new Record[(n1 + n2)];
    int j = 0;
    int k = 0;
    for(int i = 0; i < (n1 + n2); i++) {
        if(j < n1 && k < n2) {
            if (array1[j].lastName < array2[k].lastName) {
                array3[i] = array1[j];
                j++;
            } else if (array2[k].lastName < array1[j].lastName) {
                array3[i] = array2[k];
                k++;
            } else {
                array3[i] = array2[k]; 
                k++;
            }
        } else if (j < n1 && k >= n2) {
            array3[i] = array1[j];
            j++;
        } else {
            array3[i] = array2[k]; 
            k++;
        }
    }
    return array3;
}

void PrintRecords(Record array2[], int n) {
    std::cout << "First Name, Last Name, Mark, Number" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array2[i].firstName << ", " << array2[i].lastName << ", " << array2[i].mark << ", " << array2[i].number << std::endl;
    }
}