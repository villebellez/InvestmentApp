#include <iostream>
#include <iomanip>
#include "Investments.h"
using namespace std;

/** Constructor
*/
Investments::Investments(double deposit, double monthly, double rate, int years):
	initialDeposit(deposit), monthlyDeposit(monthly), compoundInterest(rate), numYears(years) {
}

/** Destructor
*/
Investments::~Investments() = default;

/**
 * Calculates interest earned during the specified time period, ignoring user-entered monthly deposit.
 * Prints report.
 */
void Investments::noMonthlyDeposit() const {
	int year = 1;
	double yearEnd = initialDeposit;

	// Header output.
	cout << endl;
	cout << "BALANCE AND INTEREST WITHOUT ADDITIONAL MONTHLY DEPOSITS" << endl;
	cout << setfill('=') << setw(74) << "" << endl;
	cout << "Year" << setfill(' ') << setw(30) << "Year End Balance" << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(74) << "" << endl;

	// Loops through each year, adding interest earned to the year end balance, then prints results.
	while (year <= numYears) {
		double interestEarned = yearEnd * compoundInterest / 100;
		yearEnd += interestEarned;

		// Balance output.
		cout << right << setfill(' ') << setw(2) << year << fixed << setprecision(2) << setw(21) << "$" << yearEnd << setw(32) << "$" << interestEarned << endl;

		year++;
	}
	cout << endl;
}

/**
 * Calculates interest earned during the specified time period, including user-entered monthly deposit.
 * Prints report.
 */
void Investments::yesMonthlyDeposit() const {
	int year = 1;
	double yearEnd = initialDeposit;

	// Header output.
	cout << endl;
	cout << "BALANCE AND INTEREST WITH ADDITIONAL MONTHLY DEPOSITS" << endl;
	cout << setfill('=') << setw(74) << "" << endl;
	cout << "Year" << setfill(' ') << setw(30) << "Year End Balance" << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(74) << "" << endl;

	// Loops through each year, adding interest earned to the year end balance, then prints results.
	while (year <= numYears) {
		int month = 1;
		double interestEarned = 0.0;
		double monthEnd = yearEnd;

		// Loops through each month of each year of its outside loop, adding the accumulation of interest at the end of every month.
		while (month <= 12) {
			monthEnd += monthlyDeposit;
			double monthlyRate = monthEnd * compoundInterest / (100 * 12);

			interestEarned += monthlyRate;
			monthEnd += monthlyRate;
			month++;
		}
		yearEnd = monthEnd;

		// Balance output.
		cout << right << setfill(' ') << setw(2) << year << fixed << setprecision(2) << setw(21) << "$" << yearEnd << setw(32) << "$" << interestEarned << endl;

		year++;
	}
}


