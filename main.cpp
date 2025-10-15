#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>   // for numeric_limits
using namespace std;

vector<double> calculateMonthlyTotals(double startingAmount, int years, double annualReturnRate, double monthlyContribution) {
    const int months = years * 12;
    const double monthlyReturnRate = annualReturnRate / 1200.0;

    vector<double> monthlyTotals;
    monthlyTotals.reserve(months);

    double totalAmount = startingAmount;

    for (int i = 0; i < months; ++i) {
        totalAmount += totalAmount * monthlyReturnRate;  // compound growth
        totalAmount += monthlyContribution;              // monthly contribution
        monthlyTotals.push_back(totalAmount);
    }

    return monthlyTotals;
}

void clearScreen() {
    // Cross-platform clear screen
    cout << "\033[2J\033[1;1H"; 
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printMainMenu(double startingAmount, int years, double annualReturnRate, double monthlyContribution) {
    cout << "==== Investment Calculator Menu ====\n\n";
    cout << "      Starting amount     = " << startingAmount << " zl\n";
    cout << "    Monthly contribution  = " << monthlyContribution << " zl\n";
    cout << "     Annual return rate   = " << annualReturnRate << " %\n";
    cout << "      Number of years     = " << years << "\n\n";
    cout << "            Edit data (1)\n";
    cout << "        Start calculation (2)\n";
    cout << "              Exit (3)\n\n";
    cout << "         Choose an option: ";
}

void changeData(double &startingAmount, int &years, double &annualReturnRate, double &monthlyContribution) {
     
    int choice = 0;
    bool running = true;
    
    while (running) {
        clearScreen();
        
        cout << "==== Investment Calculator Menu ====\n\n";
        cout << "(1)   Starting amount     = " << startingAmount << " zl\n";
        cout << "(2) Monthly contribution  = " << monthlyContribution << " zl\n";
        cout << "(3)  Annual return rate   = " << annualReturnRate << " %\n";
        cout << "(4)   Number of years     = " << years << "\n\n";
        cout << "(5)           Back\n\n";
        cout << "         Choose an option: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting amount: ";
                cin >> startingAmount;
                break;
            case 2:
                cout << "Enter monthly contribution: ";
                cin >> monthlyContribution;
                break;
            case 3:
                cout << "Enter annual return rate (%): ";
                cin >> annualReturnRate;
                break;
            case 4:
                cout << "Enter number of years: ";
                cin >> years;
                break;
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid option. Try again.\n";
                waitForEnter();
        }
    }
}

void handleCalculation(double startingAmount, int years, double annualReturnRate, double monthlyContribution) {
    vector<double> monthlyTotals = calculateMonthlyTotals(startingAmount, years, annualReturnRate, monthlyContribution);

    cout << fixed << setprecision(2);
    cout << "\nMonth-by-month totals:\n";
    for (size_t i = 0; i < monthlyTotals.size(); ++i) {
        cout << "Month " << (i + 1) << ": " << monthlyTotals[i] << " zl\n";
    }

    cout << "\nFinal total after " << years << " years = "
         << monthlyTotals.back() << " zl\n";

    waitForEnter();
}

int main() {
    double startingAmount = 0.0;
    int years = 0;
    double annualReturnRate = 0.0;
    double monthlyContribution = 0.0;

    int choice = 0;
    bool running = true;

    while (running) {
        clearScreen();
        printMainMenu(startingAmount, years, annualReturnRate, monthlyContribution);
        cin >> choice;

        switch (choice) {
            case 1:
                changeData(startingAmount, years, annualReturnRate, monthlyContribution);
                break;
            case 2:
                handleCalculation(startingAmount, years, annualReturnRate, monthlyContribution);
                break;
            case 3:
                running = false;
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
                waitForEnter();
        }
    }

    return 0;
}
