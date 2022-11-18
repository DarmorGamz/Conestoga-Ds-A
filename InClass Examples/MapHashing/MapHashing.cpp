#include <iostream>

#define ArraySize 7

int QuadraticHashIndex(int* tempArray, int key, int n = 0) {
	int QuadHashIndex = (((key % ArraySize) + n^2) % ArraySize);
	if (tempArray[QuadHashIndex] == -1) return QuadHashIndex;
	return QuadraticHashIndex(tempArray, key, (n + 1));
}
int doublHashIndex(int *tempArray, int key, int n = 0) {
	int secondHashIndex = ((key % ArraySize) + (n * (1 + (key % (ArraySize-2)))) % ArraySize);
	if(tempArray[secondHashIndex] == -1) return secondHashIndex;
	return doublHashIndex(tempArray, key, (n+1));
}


int main() {
	// Define Bucket.
	int* tempArray = new int[ArraySize];
	for (int i = 0; i < ArraySize; i++) { tempArray[i] = -1; }

	// Values to Insert.
	int toInsert[] = {50, 700, 76, 85, 92, 73, 101};

	// Loop through values and insert them using a Double/Quadratic Hashing method.
	int tempIndex = 0;
	for(int i = 0; i < ArraySize; i++) {
		tempIndex = doublHashIndex(tempArray, toInsert[i]);
		tempArray[tempIndex] = toInsert[i];
		std::cout << toInsert[i] << " was inserted at index (" << tempIndex << ")" << std::endl;
	}
}