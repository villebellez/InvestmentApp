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

struct Input {
	double deposit;
	double monthly;
	double rate;
	int years;
};

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

	while (loop == 'y') {
		system("pause");

		system("cls");
		Input i = inputScreen();
		system("pause");

		auto account = Investments(i.deposit, i.monthly, i.rate, i.years);

		account.noMonthlyDeposit();
		account.yesMonthlyDeposit();

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