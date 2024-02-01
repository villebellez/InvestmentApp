/**
 * Mary Belleville
 * CS-210
 * Project Two: Airgead Banking Investment App
 * 24EW3
 */

#include <iostream>
#include <iomanip>
#include "Investments.h"
using namespace std;

// Structure that groups the Input-related variables together in order to pass through the inputScreen function.
struct Input {
	double deposit;
	double monthly;
	double rate;
	int years;
};

// Outputs the blank display screen.
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

/**
 * Asks user to enter either an integer or a double with a prompt that is passed through the function.
 * Verifies that the user input is valid.
 *
 * @param x, prompt
 */
void inputDouble(double& x, string prompt) {
	while (true) {
		cout << prompt;
		cin >> x;

		if (!cin.fail()) {
			break;
		}
		else {
			cout << "(Invalid input. Please enter an integer or a double.)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

/**
 * Asks user to enter an integer with a prompt that is passed through the function.
 * Verifies that the user input is valid.
 *
 * @param x, prompt
 */
void inputInt(int& x, string prompt) {
	while (true) {
		cout << prompt;
		cin >> x;

		if (!cin.fail()) {
			break;
		}
		else {
			cout << "(Invalid input. Please enter an integer.)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}


/**
 * Gets user-input variables to be used for calculations.
 *
 * @return structure of deposit, monthly, rate, years
 */
Input inputScreen() {
	double deposit;
	double monthly;
	double rate;
	int years;
	Input i;

	cout << setfill('*') << setw(38) << "" << endl;
	cout << "* * * * * * * DATA INPUT * * * * * * *" << endl;
	cout << setfill('*') << setw(38) << "" << endl;

	inputDouble(deposit, "Initial Investment Amount: $");
	inputDouble(monthly, "Monthly Deposit: $");
	inputDouble(rate, "Annual Interest: %");
	inputInt(years, "Number of years: ");

	i.deposit = deposit;
	i.monthly = monthly;
	i.rate = rate;
	i.years = years;

	return i;
}

int main() {
	char loop = 'y';

	displayScreen();

	// Loops program until user specifies they do not wish to input different variables.
	while (loop == 'y') {
		system("pause");

		system("cls");
		Input i = inputScreen();
		system("pause");

		// Allows user to input initial amounts and get a print out of all calculations with those variables.
		auto account = Investments(i.deposit, i.monthly, i.rate, i.years);
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