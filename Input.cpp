#include "Input.h" 

/** Constructor
*/
Input::Input(double d, double m, double r, int y):
    deposit(d), monthly(m), rate(r), years(y) {
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

    inputDouble(deposit, "Initial Investment Amount: $");
    inputDouble(monthly, "Monthly Deposit: $");
    inputDouble(rate, "Annual Interest: %");
    inputInt(years, "Number of years: ");
}

/**
 * Four getter functions to pass user-input to main()
 *
 * @return deposit, monthly, rate, years
 */
double Input::getDeposit() const {
    return deposit;
}
double Input::getMonthly() const {
    return monthly;
}
double Input::getRate() const {
    return rate;
}
int Input::getYears() const {
    return years;
}
