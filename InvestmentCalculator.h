#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>
using namespace std;

InvestmentCalculator::InvestmentCalculator(double initialInvestment,
    double monthlyDeposit,
    double annualInterestRate,
    int numberOfYears)
    : m_initialInvestment(initialInvestment),
    m_monthlyDeposit(monthlyDeposit),
    m_annualInterestRate(annualInterestRate),
    m_numberOfYears(numberOfYears) {
}

void InvestmentCalculator::printInputScreen() const {
    cout << "********************************\n";
    cout << "************ Data Input ********\n";
    cout << "Initial Investment Amount:  $" << fixed << setprecision(2) << m_initialInvestment << "\n";
    cout << "Monthly Deposit:            $" << fixed << setprecision(2) << m_monthlyDeposit << "\n";
    cout << "Annual Interest:            " << fixed << setprecision(2) << m_annualInterestRate << "%\n";
    cout << "Number of years:            " << m_numberOfYears << "\n";
    cout << "********************************\n";
}

static void printReportHeader(const string& title) {
    cout << "\n\n" << title << "\n";
    cout << "=====================================================\n";
    cout << left << setw(10) << "Year"
        << right << setw(20) << "Year End Balance"
        << right << setw(25) << "Year End Earned Interest" << "\n";
    cout << "-----------------------------------------------------\n";
}

static void runReport(double initialInvestment, double monthlyDeposit, double annualRate, int years) {
    double balance = initialInvestment;
    double monthlyRate = (annualRate / 100.0) / 12.0;

    for (int year = 1; year <= years; ++year) {
        double interestThisYear = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double interest = (balance + monthlyDeposit) * monthlyRate;
            interestThisYear += interest;
            balance = balance + monthlyDeposit + interest;
        }

        cout << left << setw(10) << year
            << right << setw(20) << fixed << setprecision(2) << balance
            << right << setw(25) << fixed << setprecision(2) << interestThisYear
            << "\n";
    }
}

void InvestmentCalculator::printReportNoMonthlyDeposit() const {
    printReportHeader("Balance and Interest Without Additional Monthly Deposits");
    runReport(m_initialInvestment, 0.0, m_annualInterestRate, m_numberOfYears);
}

void InvestmentCalculator::printReportWithMonthlyDeposit() const {
    printReportHeader("Balance and Interest With Additional Monthly Deposits");
    runReport(m_initialInvestment, m_monthlyDeposit, m_annualInterestRate, m_numberOfYears);
}
