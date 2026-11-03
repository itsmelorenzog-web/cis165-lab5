#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const double PERCENT_DIVISOR = 100.0;

    double principal;
    double annual_rate_percent;
    int times_compounded;

    cout << "Enter principal balance: $";
    cin >> principal;
    cout << "Enter annual interest rate (%): ";
    cin >> annual_rate_percent;
    cout << "Enter times compounded per year: ";
    cin >> times_compounded;

    if (!cin || principal <= 0 || annual_rate_percent < 0 || times_compounded <= 0) {
        cout << "Invalid input. Enter a positive principal, a nonnegative rate, "
             << "and a positive compounding count.\n";
        return 1;
    }

    double annual_rate = annual_rate_percent / PERCENT_DIVISOR;
    double growth_factor = 1.0 + annual_rate / times_compounded;
    double amount = principal * pow(growth_factor, times_compounded);
    double interest_earned = amount - principal;

    cout << fixed << setprecision(2);
    cout << "\nCompound Interest Report\n";
    cout << "------------------------------\n";
    cout << left << setw(22) << "Interest Rate:" << annual_rate_percent << "%\n";
    cout << left << setw(22) << "Times Compounded:" << times_compounded << "\n";
    cout << left << setw(22) << "Principal:" << "$" << principal << "\n";
    cout << left << setw(22) << "Interest Earned:" << "$" << interest_earned << "\n";
    cout << left << setw(22) << "Amount in Savings:" << "$" << amount << "\n";

    return 0;
}
