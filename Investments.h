#ifndef INVESTMENTS_H_ 
#define INVESTMENTS_H_

/**
* @class Investments
* @brief Handles investment calculations.
*/
class Investments {
	public:
		Investments(double deposit = 0.0, double monthly = 0.0, double rate = 0.0, int years = 0); // Defaults for constructor
		~Investments();
		void yesMonthlyDeposit() const;
		void noMonthlyDeposit() const;

	private:
		double initialDeposit;
		double monthlyDeposit;
		double compoundInterest;
		int numYears;
};

#endif

