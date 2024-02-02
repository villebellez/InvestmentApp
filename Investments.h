#ifndef INVESTMENTS_H_ 
#define INVESTMENTS_H_

/**
* @class Investments
* @brief Handles investment calculations.
*/
class Investments {
	public:
		Investments(double t_initialDeposit = 0.0, double t_monthlyDeposit = 0.0, double t_compoundInterest = 0.0, int t_numYears = 0);
		~Investments();

		void yesMonthlyDeposit() const;
		void noMonthlyDeposit() const;

	private:
		double m_deposit;
		double m_monthly;
		double m_rate;
		int m_years;
};

#endif

