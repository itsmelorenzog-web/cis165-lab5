# CIS 165 Lab 5 — Financial Calculations

This lab has two C++ programs: one calculates savings after a year of compound interest, and the other calculates monthly loan payments. Both ask for input and print a report with the results.

## Program plans

These notes explain the plan used for each program. ChatGPT helped prepare the notes and code; the notes do not establish that I wrote a plan before getting AI-generated code.

### 1. Compound interest

- **Inputs:** Starting balance, annual interest rate (as a percentage), and times compounded in one year.
- **Conversion:** Divide the entered interest rate by 100 to change it to decimal form.
- **Intermediate variable:** `growth_factor`, which is `1 + annual_rate / times_compounded`.
- **Calculations:** Multiply the principal by `pow(growth_factor, times_compounded)` to find the final amount. Subtract the principal to get the interest earned.
- **Output:** Interest rate, times compounded, principal, interest earned, and amount in savings.
- **Tests:** Try $1,000 at 4.25% compounded 12 times, and $2,500 at 5% compounded 4 times. Compare the printed results with calculations from the formula.

### 2. Monthly loan payment

- **Inputs:** Loan amount, annual interest rate (as a percentage), and number of monthly payments.
- **Conversion:** Divide the annual percentage by 100 and then by 12 to get the monthly decimal rate.
- **Intermediate variables:** `monthly_rate`, `growth_factor`, `payment_numerator`, and `payment_denominator`.
- **Calculations:** Use `pow(1 + monthly_rate, number_of_payments)` in the payment formula. Multiply the monthly payment by the number of payments for the total paid back, then subtract the loan amount for the interest paid.
- **Output:** Loan amount, monthly interest rate, number of payments, monthly payment, amount paid back, and interest paid.
- **Tests:** Try a $10,000 loan at 12% for 36 months, then a $5,000 loan at 6% for 24 months. Check the total and interest as well as the monthly payment.

The loan program also handles a 0% interest rate by dividing the loan amount by the number of payments instead of using the usual formula, which would divide by zero.

## Compile and run

With a C++17 compiler installed, open a terminal in the folder containing the `.cpp` files and run:

```bash
g++ -std=c++17 -Wall -Wextra compound_interest.cpp -o compound_interest
g++ -std=c++17 -Wall -Wextra loan_payment.cpp -o loan_payment
```

On Linux or macOS:

```bash
./compound_interest
./loan_payment
```

On Windows with g++ installed:

```powershell
.\compound_interest.exe
.\loan_payment.exe
```

Type the interest rate as a percentage, such as `4.25` for 4.25%.

## Testing

Expected values were calculated from the formulas using full precision, then rounded to two decimal places. The actual values below come from compiling and running both programs in ChatGPT's test environment. The programs were compiled with `-std=c++17 -Wall -Wextra -pedantic` and produced no warnings. These are AI-run tests, not a claim that I ran them on my own computer.

| Program and test | Inputs | Expected results | Actual results (AI-run) | Match or correction |
| --- | --- | --- | --- | --- |
| Compound interest — assigned | $1,000, 4.25%, 12 | Interest: $43.34; savings: $1,043.34 | Interest: $43.34; savings: $1,043.34 | Match |
| Compound interest — changed | $2,500, 5%, 4 | Interest: $127.36; savings: $2,627.36 | Interest: $127.36; savings: $2,627.36 | Match |
| Loan payment — assigned | $10,000, 12%, 36 | Payment: $332.14; total: $11,957.15; interest: $1,957.15 | Payment: $332.14; total: $11,957.15; interest: $1,957.15 | Match |
| Loan payment — changed | $5,000, 6%, 24 | Payment: $221.60; total: $5,318.47; interest: $318.47 | Payment: $221.60; total: $5,318.47; interest: $318.47 | Match |

**Extra test:** A $1,000 loan at 0% interest for 12 payments printed $83.33 as the monthly payment, $1,000.00 paid back, and $0.00 interest.

## Understanding the code

**Why divide percentages by 100?** A percent means out of 100. For example, 4.25% is 0.0425, and that's the number the formula needs.

**What does `pow` do?** It raises one number to the power of another. `pow(2, 3)` means 2 cubed, which is 8.

**What changes when there are more compounding periods?** Interest gets added more often. At the same stated annual rate, that usually makes the final savings balance a little higher.

**How do you find the monthly interest rate?** Divide the annual percentage by 100, then divide by 12. For example, 12% per year becomes 0.01 per month.

**Why use `double`?** Interest rates and money calculations often have decimals. A `double` can store those values with much more precision than an `int`.

**Why calculate with full precision?** Rounding a monthly payment too early can change the total when it gets multiplied by many months. I only format the displayed result to two decimal places.

**How are total repayment and interest calculated?** Total repayment is the unrounded monthly payment times the number of payments. Interest is that total minus the original loan.

**Why put calculations in variables first?** It makes each step easier to read and check. It also keeps complicated formulas out of the `cout` statements.

## Files

- `compound_interest.cpp` — compound interest calculator
- `loan_payment.cpp` — monthly loan calculator
- `README.md` — plans, commands, tests, and explanations
- `AI_REFLECTION.md` — notes about using AI on the assignment
