/**
 * Mary Belleville
 * CS-210
 * Project Two: Airgead Banking Investment App
 * 24EW3
 */

#include <iostream>
#include <iomanip>
#include "Investments.h"
#include "Input.h"
using namespace std;

/** Outputs the default display screen.
*/
void displayScreen() {
	cout << setfill('*') << setw(38) << "" << endl;
	cout << "* * * * * * * DATA INPUT * * * * * * *" << endl;
	cout << setfill('*') << setw(38) << "" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	cout << endl;
}

int main() {
	char loop = 'y';

	displayScreen();

	// Loops program until user specifies they do not wish to input different variables.
	while (loop == 'y') {
		system("pause");
		system("cls");

		auto i = Input();
		i.inputScreen();
		double deposit = i.getDeposit();
		double monthly = i.getMonthly();
		double rate = i.getRate();
		int years = i.getYears();
		system("pause");

		// Allows user to input initial amounts and get a print out of all calculations with those variables.
		auto account = Investments(deposit, monthly, rate, years);
		account.noMonthlyDeposit();
		account.yesMonthlyDeposit();

		// Verifies user-entered answer to repeat the program is either 'y' or 'no', otherwise throws error.
		do {
			cout << endl << "Would you like to enter different values? (y/n): ";
			cin >> loop;
			loop = tolower(loop);

			if (loop == 'y' || loop == 'n') {
				break;}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl; }
		} 
		while (true);

		if (loop != 'y') {
			break;
		}
	}
	return 0;
}