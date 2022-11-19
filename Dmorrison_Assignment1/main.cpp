/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

	// Includes.
	#include <iostream>
	#include <fstream>
	#include <string>

	// Prototypes.
	void ReadFile();
	bool isPalindrome(std::string);

	int main(void) {
		ReadFile();
	}

	void ReadFile() {
		// Init vars.
		std::ifstream oFile("InputFile.txt");
		std::string sLine;

		// Loop through lines of input file.
		while(getline(oFile, sLine)) {
			if(isPalindrome(sLine)) {
				std::cout << sLine << " : is a palindrome\n";
			} else {
				std::cout << sLine << " : is not a palindrome\n";
			}
		}
	}

	bool isPalindrome(std::string sString) {
		// Remove whitespace. Will be 'slower' because it runs on each iteration. Could move it to main function.
		sString.erase(std::remove_if(sString.begin(), sString.end(), std::isspace), sString.end());

		// If str is 1 char, its a palindrome.
		if(sString.length() == 1) return true;

		// If first and last letter of a string are equal, recurse. If length is 2 return true; Otherwise, false.
		if(sString[0] == sString[sString.length() - 1]) {
			if(sString.length() == 2) return true;
			return isPalindrome(sString.substr(1, sString.length() - 2));
		} else {
			return false;
		}
	}


