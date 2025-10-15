#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<double> calculateMonthlyTotals(double startingAmount, int years, double annualReturnRate, double monthlyContribution) {
    const int months = years * 12;
    const double monthlyReturnRate = annualReturnRate / 1200.0;

    vector<double> monthlyTotals;
    monthlyTotals.reserve(months);  // reserve space for efficiency

    double totalAmount = startingAmount;

    for (int i = 0; i < months; ++i) {
        totalAmount += totalAmount * monthlyReturnRate;  // compound growth
        totalAmount += monthlyContribution;              // monthly contribution
        monthlyTotals.push_back(totalAmount);            // store this month's total
    }

    return monthlyTotals;
}


void getUserInput(double &startingAmount, int &years, double &annualReturnRate, double &monthlyContribution) {
    cout << "Enter the starting amount: ";
    cin >> startingAmount;

    cout << "Enter the number of years: ";
    cin >> years;

    cout << "Enter the annual return rate (in %): ";
    cin >> annualReturnRate;

    cout << "Enter the additional monthly contribution: ";
    cin >> monthlyContribution;
}

int main() {
    double startingAmount = 0.0;
    int years = 0;
    double annualReturnRate = 0.0;
    double monthlyContribution = 0.0;

    getUserInput(startingAmount, years, annualReturnRate, monthlyContribution);

    vector<double> monthlyTotals = calculateMonthlyTotals(startingAmount, years, annualReturnRate, monthlyContribution);

    cout << fixed << setprecision(2);
    cout << "\nMonth-by-month totals:\n";
    for (size_t i = 0; i < monthlyTotals.size(); ++i) {
        cout << "Month " << (i + 1) << ": " << monthlyTotals[i] << " zl\n";
    }

    cout << "\nFinal total after " << years << " years = " 
         << monthlyTotals.back() << " zl" << endl;

    return 0;

}
