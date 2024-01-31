#ifndef INVESTMENTS_H_ 
#define INVESTMENTS_H_

class Investments {
	public:
		Investments(double deposit, double monthly, double rate, int years);
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

