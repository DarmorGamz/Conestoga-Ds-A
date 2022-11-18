#include <iostream>

using namespace std;
inline double Max(double, double);
inline char Max(char, char);

//void main() {
//    cout << Max(1.0, 3.0) << "\n"; // Double
//    cout << Max('C', 'A') << "\n"; // Char
//    cout << Max(1, 2) << "\n"; // Int
//    cout << Max(10000000, 10000001) << "\n"; // Long
//}

inline double Max(double x, double y) { return x >= y ? x : y; }
inline char Max(char x, char y) { return x >= y ? x : y; }