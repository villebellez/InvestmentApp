/**
 * Mary Belleville
 * CS-210
 * Project Two: Airgead Banking Investment App
 * 24EW3
 */

#include <iostream>
#include "Investments.h"
using namespace std;

int main() {

	// Testing
	double deposit = 0.0;
	double monthly = 0.0;
	double rate = 0.0;
	int numYears = 0;

	auto account = Investments(deposit, monthly, rate, numYears);

	account.yesMonthlyDeposit();
	account.noMonthlyDeposit();

	return 0;
}