#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "InvestmentAccount.h"

using namespace std;

// Function prototype to display yearly results for an investment account
void displayOutput(InvestmentAccount account, int numberOfYears);

int main() {

    // Variables to store user input
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;
    char choice = 'y';

    // Loop allows the user to test multiple scenarios
    while (choice == 'y' || choice == 'Y') {

        cout << "Data Input" << endl;

        // Get initial investment amount and validate input
        cout << "Initial Investment Amount: $";
        cin >> initialInvestment;
        while (initialInvestment <= 0) {
            cout << "Please enter a non-zero or non-negative value: $";
            cin >> initialInvestment;
        }

        // Get monthly deposit and validate input
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        while (monthlyDeposit <= 0) {
            cout << "Please enter a non-zero or non-negative value: $";
            cin >> monthlyDeposit;
        }

        // Get annual interest rate and validate input
        cout << "Annual Interest: %";
        cin >> annualInterest;
        while (annualInterest <= 0) {
            cout << "Please enter a non-zero or non-negative value: %";
            cin >> annualInterest;
        }

        // Get number of years and validate input
        cout << "Number of years: ";
        cin >> numberOfYears;
        while (numberOfYears <= 0) {
            cout << "Please enter a non-zero or non-negative value: ";
            cin >> numberOfYears;
        }

        // Pause before displaying results
        cout << "\nPress Enter to continue . . .";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // Create two account objects:
        // one without monthly deposits and one with monthly deposits
		InvestmentAccount accountWithoutDeposit(initialInvestment, annualInterest); //Object instance for account without monthly deposits
		InvestmentAccount accountWithDeposit(initialInvestment, annualInterest, monthlyDeposit); //object instance for account with monthly deposits

        // Display results for both scenarios
        displayOutput(accountWithoutDeposit, numberOfYears);
        cout << endl;
        displayOutput(accountWithDeposit, numberOfYears);

        // Ask user if they want to repeat the program
        cout << "\nWould you like to enter another set of values? (y/n): ";
        cin >> choice;

        // Closing message
        if (choice != 'y' && choice != 'Y') {
            cout << "\nThank you for using AIRGEAD BANKING.\nDeveloper: Justin Carlo Florida" << endl;
            
            return 0;
        }
    }

    return 0;
}

// Displays yearly balance and interest results
void displayOutput(InvestmentAccount account, int numberOfYears) {

    // Display header depending on whether monthly deposit is used
    if (account.getMonthlyDeposit() == 0) {
        cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
    }
    else {
        cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    }

    // Column headers
    cout << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;

    // Loop through each year and display results
    for (int year = 1; year <= numberOfYears; year++) {
        cout << left << setw(10) << year
            << setw(25) << account.getEndingBalanceFormatted(year)
            << setw(25) << account.getInterestEarnedFormatted(year) << endl;
    }
}