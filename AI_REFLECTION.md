# AI Reflection — Lab 5

I used ChatGPT to help put together the two C++ programs, the README, and this reflection. It helped organize the formulas into variables, format the output, and test the programs. The planning notes in the README were also drafted with AI, so I am not presenting them as something I wrote before requesting code.

One decision I kept was using a separate calculation when a loan has 0% interest. The normal loan formula would have a zero in the denominator, so the program divides the loan amount by the number of payments in that case. That seemed like a useful way to prevent an error without making the rest of the program harder to read.

For verification, ChatGPT compiled both programs using g++ with warnings enabled and ran four sets of inputs. For the $10,000 loan at 12% over 36 months, it got a $332.14 monthly payment and $1,957.15 in interest, which matched the calculated values. Those runs were done in the AI environment, not on my computer.

This lab helped show how percentages and `pow()` fit into financial formulas. I still need more practice writing these calculations from scratch and checking the programs independently.
