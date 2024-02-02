#include "Input.h" 

/** Constructor
*/
Input::Input(double t_initialDeposit, double t_monthlyDeposit, double t_compoundInterest, int t_numYears):
    m_deposit(t_initialDeposit), m_monthly(t_monthlyDeposit), m_rate(t_compoundInterest), m_years(t_numYears) {
}

/** Destructor
*/
Input::~Input() = default;

/**
 * Asks user to enter either an integer or a double with a prompt that is passed through the function.
 * Verifies that the user input is valid.
 *
 * @param x, prompt
*/
void Input::inputDouble(double& x, string prompt) const {
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
void Input::inputInt(int& x, string prompt) const {
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


/** Gets user-input variables to be used for calculations.
*/
void Input::inputScreen() {
    cout << setfill('*') << setw(38) << "" << endl;
    cout << "* * * * * * * DATA INPUT * * * * * * *" << endl;
    cout << setfill('*') << setw(38) << "" << endl;

    inputDouble(m_deposit, "Initial Investment Amount: $");
    inputDouble(m_monthly, "Monthly Deposit: $");
    inputDouble(m_rate, "Annual Interest: %");
    inputInt(m_years, "Number of years: ");
}

/**
 * Four getter functions to pass user-input to main()
 *
 * @return deposit, monthly, rate, years
 */
double Input::getDeposit() const {
    return m_deposit;
}
double Input::getMonthly() const {
    return m_monthly;
}
double Input::getRate() const {
    return m_rate;
}
int Input::getYears() const {
    return m_years;
}
