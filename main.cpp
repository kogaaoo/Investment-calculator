#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib> // for system("cls")
using namespace std;

vector<double> calculateMonthlyTotals(double startingAmount, int years, double annualReturnRate, double monthlyContribution) {
    const int months = years * 12;
    const double monthlyReturnRate = annualReturnRate / 1200.0;

    vector<double> monthlyTotals;
    monthlyTotals.reserve(months);

    double totalAmount = startingAmount;

    for (int i = 0; i < months; ++i) {
        totalAmount += totalAmount * monthlyReturnRate;
        totalAmount += monthlyContribution;
        monthlyTotals.push_back(totalAmount);
    }

    return monthlyTotals;
}

int main() {
    double startingAmount = 0.0;
    int years = 0;
    double annualReturnRate = 0.0;
    double monthlyContribution = 0.0;

    int choice = 0;
    bool running = true;

    while (running) {
        // Clear screen (Windows)
        system("cls");
        // Or use: cout << "\033[2J\033[1;1H"; for cross-platform

        cout << "==== Investment Calculator Menu ====\n";
        cout << "1. Set starting amount (current: " << startingAmount << ")\n";
        cout << "2. Set number of years (current: " << years << ")\n";
        cout << "3. Set annual return rate % (current: " << annualReturnRate << ")\n";
        cout << "4. Set monthly contribution (current: " << monthlyContribution << ")\n";
        cout << "5. Start calculation\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting amount: ";
                cin >> startingAmount;
                break;
            case 2:
                cout << "Enter number of years: ";
                cin >> years;
                break;
            case 3:
                cout << "Enter annual return rate (%): ";
                cin >> annualReturnRate;
                break;
            case 4:
                cout << "Enter monthly contribution: ";
                cin >> monthlyContribution;
                break;
            case 5: {
                vector<double> monthlyTotals = calculateMonthlyTotals(startingAmount, years, annualReturnRate, monthlyContribution);

                cout << fixed << setprecision(2);
                cout << "\nMonth-by-month totals:\n";
                for (size_t i = 0; i < monthlyTotals.size(); ++i) {
                    cout << "Month " << (i + 1) << ": " << monthlyTotals[i] << " zl\n";
                }

                cout << "\nFinal total after " << years << " years = "
                     << monthlyTotals.back() << " zl" << endl;

                system("pause"); // wait for user before returning to menu
                break;
            }
            case 6:
                running = false;
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
                system("pause");
        }
    }

    return 0;
}
