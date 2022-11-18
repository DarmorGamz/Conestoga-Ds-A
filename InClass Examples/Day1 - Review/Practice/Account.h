// account.h
// Defining the class Account.
// ---------------------------------------------------
#ifndef _ACCOUNT_ // Avoid multiple inclusions.
#define _ACCOUNT_
#include <iostream>
#include <string>
using namespace std;
class Account
{
	private: 
		string name; 
		unsigned long nr; 
		double balance; 
	public: 
		bool init(const string& sTempName, unsigned long lTempNR, double dTempBalance) {
			name = sTempName;
			nr = lTempNR;
			balance = dTempBalance;

			return true;
		}
		void display() {
			cout << "Name: " << this->name << endl;
			cout << "Account Number: " << this->nr << endl;
			cout << "Balance: " << this->balance << endl;
		}
};
#endif // _ACCOUNT_
