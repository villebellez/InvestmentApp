#include <iostream>
#include <iomanip>
#include "Investments.h"
using namespace std;

// Default constructor to create objects
Investments::Investments(double deposit, double monthly, double rate, int years): 
	initialDeposit(deposit), monthlyDeposit(monthly), compoundInterest(rate), numYears(years) {
}

// Destructor to destroy objects
Investments::~Investments() = default;

// Prints report that ignores the user-entered monthly deposit.
void Investments::noMonthlyDeposit() const {
	int year = 1;
	double yearEnd = initialDeposit;

	cout << endl;
	cout << "BALANCE AND INTEREST WITHOUT ADDITIONAL MONTHLY DEPOSITS" << endl;
	cout << setfill('=') << setw(74) << "" << endl;
	cout << "Year" << setfill(' ') << setw(30) << "Year End Balance" << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(74) << "" << endl;

	while (year <= numYears) {
		double interestEarned = yearEnd * compoundInterest / 100;
		yearEnd += interestEarned;

		cout << right << setfill(' ') << setw(2) << year << fixed << setprecision(2) << setw(21) << "$" << yearEnd << setw(32) << "$" << interestEarned << endl;

		year++;
	}
	cout << endl;
}

// Prints report that considers the user-entered monthly deposit.
void Investments::yesMonthlyDeposit() const {
	int year = 1;
	double yearEnd = initialDeposit;

	cout << endl;
	cout << "BALANCE AND INTEREST WITH ADDITIONAL MONTHLY DEPOSITS" << endl;
	cout << setfill('=') << setw(74) << "" << endl;
	cout << "Year" << setfill(' ') << setw(30) << "Year End Balance" << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(74) << "" << endl;


	while (year <= numYears) {
		int month = 1;
		double interestEarned = 0.0;
		double monthEnd = yearEnd;

		while (month <= 12) {
			monthEnd += monthlyDeposit;
			double monthlyRate = monthEnd * compoundInterest / (100 * 12);

			interestEarned += monthlyRate;
			monthEnd += monthlyRate;
			month++;
		}
		yearEnd = monthEnd;

		cout << right << setfill(' ') << setw(2) << year << fixed << setprecision(2) << setw(21) << "$" << yearEnd << setw(32) << "$" << interestEarned << endl;

		year++;
	}
}


