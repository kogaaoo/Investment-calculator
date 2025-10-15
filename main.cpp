#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    double starting_amount = 0;
    int years = 0;
    double return_rate = 0;
    int monthly_contribution = 0;
    double total_amount = 0;

    cout << "Enter the starting amount: ";
    cin >> starting_amount;
    cout << "Enter the number of years: ";
    cin >> years;
    cout << "Enter the annual return rate (in %): ";
    cin >> return_rate;
    cout << "Enter the additional monthly contribution: ";
    cin >> monthly_contribution;

    int months = years * 12;
    total_amount = starting_amount;
    double monthly_return = return_rate/1200;
    cout << monthly_return << endl << endl;

    for (int i = 0; i < months; ++i) {
        cout << total_amount << endl;
        cout << total_amount * monthly_return;
        total_amount += total_amount * monthly_return;
        cout << total_amount << endl;
        total_amount += monthly_contribution;
        cout << total_amount << endl << endl;
    }

    cout << "Total amount = " << setprecision(2) << fixed << total_amount << "zl";

    return 0;
}