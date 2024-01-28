#include <iostream>
#include <iomanip>
#include "Investments.h"
using namespace std;


// Default Constructor to create objects
Investments::Investments(double deposit = 0.0, double monthly = 0.0, double rate = 0.0, int years = 0) {
	this->initialDeposit;
	this->monthlyDeposit;
	this->compoundInterest;
	this->numYears;
}

// Destructor to destroy objects
Investments::~Investments() {
}

// Prints report that considers the user-entered monthly deposit.
void Investments::yesMonthlyDeposit() {
	cout << " Balance and Interest with additional Monthly Deposits" << endl;
}

// Prints report that ignores the user-entered monthly deposit.
void Investments::noMonthlyDeposit() {
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
}


