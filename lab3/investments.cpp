// File: investments.cpp
// Created by: Joseph Shaffer
// Created on: September 14, 2016


/* This program takes and initial investment
in dollars with an interest rate and the number of months
for the investment to calculate how much money the investment 
will make over those months when compounded annually and 
continuously. The program also calculates the profit from these 
investments and not just the money made. Then the program compares 
how much one investment type makes compared to the other in a dollar
amount */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

	/* initInvest = initial investment in dollars
	rate = interest rate
	months = number of months given by user
	dollars is the amount of money from initial investment compounded annually
	years = months divided by 12
	profit = dollars - initial investment, difference in money made and money put into investment
	euler is a constant
	finalD is dollars from investment compounded continuously
	finalP is profit from finalD - initInvest
	f is the difference between finalD and dollars
	*/
	int initInvest, rate, months;
	double dollars, years, profit, euler(2.71828), finalD, finalP, f;

	// Get initial investment from user
	cout << "Enter initial investment (dollars): ";
	cin >> initInvest;
	
	// Get interest rate from user
	cout << "Enter interest rate per year (percentage): ";
	cin >> rate;
	
	// Get number of months from user
	cout << "Enter number of months: ";
	cin >> months;

	// Calculate years from months
	years = months / 12.0;
	
	// Calculate money from investment compounded annually
	dollars = initInvest * pow((1.0 + (rate / 100.0)), years);
	
	// Calculate profit from investment
	profit = dollars - initInvest;

	// Print out money from investment and profit
	cout << "Value of your investment compounded annually after " << years << " year(s) is " << dollars << " dollars." << endl;
	cout << "Profit from your investment after " << years << " years(s) is " << profit << " dollars." << endl << endl;

	// Calculate money from investment compounded continuously
	finalD = initInvest * pow(euler, ((rate / 100.0) * years));
	// Calculate profit from this investment
	finalP = finalD - initInvest;
	// Calculate difference in profits from investments
	f = finalP - profit;

	// Print out money from this investment and corresponding profit
	cout << "Value of your investment continuously compounded after " << years << " year(s) is " << finalD << " dollars." << endl;
	cout << "Profit from this investment is " << finalP << " dollars." << endl << endl;

	// Print out difference in investment types
	cout << "The difference between both investment types is " << f << " dollars." << endl;

	return 0;
}	
