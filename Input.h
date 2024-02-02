#ifndef INPUT_H 
#define INPUT_H

#include <iostream> 
#include <iomanip>
#include <limits>
using namespace std;

/**
* @class Input
* @brief Handles user input for the application.
*/
class Input {
	public:
		Input(double dep = 0.0, double mon = 0.0, double r = 0.0, int y = 0); // Defaults for constructor
		~Input();
		void inputDouble(double& x, string prompt) const;
		void inputInt(int& x, string prompt) const;
		void inputScreen();

		double getDeposit() const;
		double getMonthly() const;
		double getRate() const;
		int getYears() const;

	private:
		double deposit;
		double monthly;
		double rate;
		int years;
};

#endif
