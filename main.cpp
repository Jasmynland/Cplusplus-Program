#pragma once
#pragma once

class InvestmentCalculator {
public:
    InvestmentCalculator(double initialInvestment,
        double monthlyDeposit,
        double annualInterestRate,
        int numberOfYears);

    void printInputScreen() const;
    void printReportNoMonthlyDeposit() const;
    void printReportWithMonthlyDeposit() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;
};
