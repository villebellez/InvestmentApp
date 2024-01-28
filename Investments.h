#ifndef INVESTMENTS_H_
#define INVESTMENTS_H_

class Investments {
	public:
		Investments(double deposit, double monthly, double rate, int numYears);
		~Investments();
		void yesMonthlyDeposit();
		void noMonthlyDeposit();

	private:
		double initialDeposit, monthlyDeposit, compoundInterest;
		int numYears;
};

#endif

