#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>   // for numeric_limits
using namespace std;

void calculateMonthlyTotals(double startingAmount, int years, double annualReturnRate, double monthlyContribution, vector<double> &monthlyTotals) {
    const int months = years * 12;
    const double monthlyReturnRate = annualReturnRate / 1200.0;
    monthlyTotals.reserve(months);

    double totalAmount = startingAmount;

    for (int i = 0; i < months; ++i) {
        totalAmount += totalAmount * monthlyReturnRate;
        totalAmount += monthlyContribution;
        monthlyTotals.push_back(totalAmount);
    }
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printMainMenu(double startingAmount, int years, double annualReturnRate, double monthlyContribution) {
    cout << "\033[2J\033[1;1H"; //clear screen
    
    cout << "====== Investment Calculator ======\n\n";
    cout << "      Starting amount     = " << startingAmount << " zl\n";
    cout << "    Monthly contribution  = " << monthlyContribution << " zl\n";
    cout << "     Annual return rate   = " << annualReturnRate << " %\n";
    cout << "      Number of years     = " << years << "\n\n";
    cout << "            Edit data (1)\n";
    cout << "        Start calculation (2)\n";
    cout << "          View outcome (3)\n";
    cout << "              Exit (4)\n\n";
    cout << "         Choose an option: ";
}

void changeData(double &startingAmount, int &years, double &annualReturnRate, double &monthlyContribution) {
     
    int choice = 0;
    bool running = true;
    
    while (running) {
        cout << "\033[2J\033[1;1H";  //clear screen
        
        cout << "====== Investment Calculator ======\n\n";
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

void printOutcome(vector<double> monthlyTotals) {
    cout << "\nMonth-by-month totals:\n";
    for (size_t i = 0; i < monthlyTotals.size(); ++i) {
        cout << "Month " << (i + 1) << ": " << monthlyTotals[i] << " zl\n";
    }

    cout << "\nFinal total after " << monthlyTotals.size()/12 << " years = "
         << monthlyTotals.back() << " zl\n";
}

int main() {
    double startingAmount = 0.0;
    int years = 0;
    double annualReturnRate = 0.0;
    double monthlyContribution = 0.0;

    vector<double> monthlyTotals;

    int choice = 0;
    bool running = true;

    while (running) {
        printMainMenu(startingAmount, years, annualReturnRate, monthlyContribution);
        cin >> choice;

        switch (choice) {
            case 1:
                changeData(startingAmount, years, annualReturnRate, monthlyContribution);
                break;
            case 2:
                calculateMonthlyTotals(startingAmount, years, annualReturnRate, monthlyContribution, monthlyTotals);
                cout << "Calculation completed\n";
                waitForEnter();
                break;
            case 3:
                printOutcome(monthlyTotals);
                waitForEnter();
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid option. Try again.\n";
                waitForEnter();
        }
    }

    return 0;
}