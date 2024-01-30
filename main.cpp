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

Input inputScreen() {
	double deposit;
	double monthly;
	double rate;
	int years;
	Input i;

	cout << setfill('*') << setw(38) << "" << endl;
	cout << "* * * * * * * DATA INPUT * * * * * * *" << endl;
	cout << setfill('*') << setw(38) << "" << endl;

	cout << "Initial Investment Amount: $";
	cin >> deposit;

	cout << "Monthly Deposit: $";
	cin >> monthly;

	cout << "Annual Interest: %";
	cin >> rate;

	cout << "Number of years: ";
	cin >> years;

	i.deposit = deposit;
	i.monthly = monthly;
	i.rate = rate;
	i.years = years;

	return i;
}

int main() {
	string loop = "y";

	displayScreen();

	while (loop == "y") {
		system("pause");

		system("cls");
		Input i = inputScreen();
		system("pause");

		auto account = Investments(i.deposit, i.monthly, i.rate, i.years);

		account.yesMonthlyDeposit();
		account.noMonthlyDeposit();

		cout << endl << "Would you like to enter different values? (y/n): ";
		cin >> loop;

		// TODO: Error catching for anything other than y/n
		if (loop != "y") {
			break;
		}
	}
	return 0;
}