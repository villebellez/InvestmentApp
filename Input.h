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
		Input(double t_initialDeposit = 0.0, double t_monthlyDeposit = 0.0, double t_compoundInterest = 0.0, int t_numYears = 0);
		~Input();

		void inputDouble(double& x, string prompt) const;
		void inputInt(int& x, string prompt) const;
		void inputScreen();

		double getDeposit() const;
		double getMonthly() const;
		double getRate() const;
		int getYears() const;

	private:
		double m_deposit;
		double m_monthly;
		double m_rate;
		int m_years;
};

#endif
