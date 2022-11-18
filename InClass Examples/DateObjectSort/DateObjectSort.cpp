#include <iostream>

class Date {
public:
	int day;
	int month;
	int year;

	Date(int dayt, int montht, int yeart) {
		day = dayt;
		month = montht;
		year = yeart;
	}
};

void selectionSort(Date *arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for(j = i + 1; j < n; j++)
			if(arr[j]->year < arr[min_idx]->year) {
				min_idx = j;
			} else if(arr[j]->year == arr[min_idx]->year && arr[j]->month < arr[min_idx]->month) {
				min_idx = j;
			} else if(arr[j]->year == arr[min_idx]->year && arr[j]->month == arr[min_idx]->month && arr[j]->day < arr[min_idx]->day) {
				min_idx = j;
			}
				
			if(min_idx != i) {
				Date temp = *arr[min_idx];
				*arr[min_idx] = *arr[i];
				*arr[i] = temp;
			}
    }
	for (int i = 0; i < 10; i++) {

		std::cout << arr[i]->day << '/' << arr[i]->month << '/' << arr[i]->year << std::endl;
	}
}

int main() {
	Date *dateArray[10];

	for (int i = 0; i < 10; i++) {
		int day = rand() % 30 + 1;
		int month = rand() % 12 + 1;
		int year = (rand() % 30 + 10) + 2000;
		Date *temp = new Date(day, month, year);

		dateArray[i] = temp;
		std::cout << dateArray[i]->day << '/' << dateArray[i]->month << '/' << dateArray[i]->year << std::endl;
	}
	std::cout << std::endl;
	selectionSort(dateArray, 10);
}

