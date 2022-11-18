// Includes.
#include <iostream>

// Prototypes.
int DigitalRoot(int);
int DigitalSum(int);
int Fib(int);
double calcPower(double, int);

// Main Loop.
int main() {
	// Print value of x^y.
	//std::cout << calcPower(2, -3);

	//std::cout << digitSum(1729);
	//std::cout << DigitalRoot(56345);
	int i = 0; int n = 15;
	while (i < n) {
		std::cout << Fib(i) << ' ';
		i++;
	}
	
	// Return Success.
	return true;
}

double calcPower(double x, int y) {
	if(y > 0) { // Exponent is positive.
		return x * calcPower(x, --y);
	} else if(y < 0) { // Exponent is negative.
		return 1 / x * calcPower(x, ++y);
	} else return 1; // Exponent is 0
}

int DigitalSum(int n) {
	if (n > 0) {
		return (n%10) + DigitalSum(n/10);
	} else return 0;
}

int DigitalRoot(int n) {
	if(n%10 == 0) return n;

	n = n%10 + DigitalRoot(n/10);
	return n < 10 ? n : DigitalRoot(n);
}

int Fib(int n) {
	if (n == 0 || n == 1) return n;
	return Fib(n - 1) + Fib(n - 2);
}