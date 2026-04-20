#include "InvestmentAccount.h"

//Implementation for InvestmentAccount

// Constructor for an account without a monthly deposit.
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate) {
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = 0.0;
}

// Constructor for an account with a monthly deposit.
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit) {
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = monthlyDeposit;
}

// Calculates the ending balance after the requested number of years.
double InvestmentAccount::getEndingBalance(int numberOfYears) {
	int totalMonths = numberOfYears * 12;
	double balance = initialAmount;

	for (int month = 1; month <= totalMonths; month++) {
		double total = balance + monthlyDeposit;
		double interest = total * ((annualInterestRate / 100.0) / 12.0);
		balance = total + interest;
	}

	return balance;
}

// Calculates how much interest was earned over the full investment period.
double InvestmentAccount::getInterestEarned(int numberOfYears) {
	int totalMonths = numberOfYears * 12;
	double totalContributions = initialAmount + (monthlyDeposit * totalMonths);
	double endingBalance = getEndingBalance(numberOfYears);

	return endingBalance - totalContributions;
}

// Returns the ending balance as a formatted string for output.
std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears) {
	return format(round(getEndingBalance(numberOfYears), 2));
}

// Returns the total interest earned as a formatted string for output.
std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears) {
	return format(round(getInterestEarned(numberOfYears), 2));
}

// Getter for the initial investment amount.
double InvestmentAccount::getInitialAmount() {
	return initialAmount;
}

// Getter for the monthly deposit amount.
double InvestmentAccount::getMonthlyDeposit() {
	return monthlyDeposit;
}

// Getter for the annual interest rate.
double InvestmentAccount::getAnnualInterestRate() {
	return annualInterestRate;
}

//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}