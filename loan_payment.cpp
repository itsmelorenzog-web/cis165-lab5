#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const double PERCENT_DIVISOR = 100.0;
    const double MONTHS_PER_YEAR = 12.0;

    double loan_amount;
    double annual_rate_percent;
    int number_of_payments;

    cout << "Enter loan amount: $";
    cin >> loan_amount;
    cout << "Enter annual interest rate (%): ";
    cin >> annual_rate_percent;
    cout << "Enter number of monthly payments: ";
    cin >> number_of_payments;

    if (!cin || loan_amount <= 0 || annual_rate_percent < 0 || number_of_payments <= 0) {
        cout << "Invalid input. Enter a positive loan, a nonnegative rate, "
             << "and a positive payment count.\n";
        return 1;
    }

    double monthly_rate = annual_rate_percent / PERCENT_DIVISOR / MONTHS_PER_YEAR;
    double monthly_rate_percent = monthly_rate * PERCENT_DIVISOR;
    double monthly_payment;

    // A zero interest rate needs a separate formula to avoid dividing by zero.
    if (monthly_rate == 0.0) {
        monthly_payment = loan_amount / number_of_payments;
    } else {
        double growth_factor = pow(1.0 + monthly_rate, number_of_payments);
        double payment_numerator = monthly_rate * growth_factor;
        double payment_denominator = growth_factor - 1.0;
        monthly_payment = loan_amount * payment_numerator / payment_denominator;
    }

    double amount_paid_back = monthly_payment * number_of_payments;
    double interest_paid = amount_paid_back - loan_amount;

    cout << fixed << setprecision(2);
    cout << "\nMonthly Loan Payment Report\n";
    cout << "--------------------------------\n";
    cout << left << setw(23) << "Loan Amount:" << "$" << loan_amount << "\n";
    cout << left << setw(23) << "Monthly Interest Rate:" << monthly_rate_percent << "%\n";
    cout << left << setw(23) << "Number of Payments:" << number_of_payments << "\n";
    cout << left << setw(23) << "Monthly Payment:" << "$" << monthly_payment << "\n";
    cout << left << setw(23) << "Amount Paid Back:" << "$" << amount_paid_back << "\n";
    cout << left << setw(23) << "Interest Paid:" << "$" << interest_paid << "\n";

    return 0;
}
