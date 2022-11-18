#include <iostream>

using namespace std;

// Define Prototypes.
void swap(float*, float*);
void swap(float&, float&);
void swap(float, float);

//bool main() {
//	// Init vars.
//	float fA = 5; float fB = 6;
//
//	swap(&fA, &fB);
//	cout << "A: " << fA << ", B: " << fB << "\n";
//
//	swap(fA, fB);
//	cout << "A: " << fA << ", B: " << fB;
//
//	// Return Success.
//	return true;
//}

void swap(float* p1, float* p2) // Pointer version
{
	float temp; // Temporary variable
	temp = *p1; // Above call points p1
	*p1 = *p2; // to x and p2 to y.
	*p2 = temp;
}
void swap(float& a, float& b) // Reference version
{
	float temp; // Temporary variable
	temp = a; // For above call
	a = b; // a equals x and b equals y
	b = temp;
}

void swap(float a, float b)
{
	float temp; // Temporary variable
	temp = a; // For above call
	a = b; // a equals x and b equals y
	b = temp;
}

