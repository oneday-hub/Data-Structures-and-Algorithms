#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

int main() {
    // Input: user's name and number of units consumed
    string userName;
    int unitsConsumed;

    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "Enter the number of units consumed: ";
    cin >> unitsConsumed;

    // Constants for electricity rates
    const double RATE_FIRST_200_UNITS = 0.80; // 80 paise per unit
    const double RATE_NEXT_100_UNITS = 0.90;  // 90 paise per unit
    const double RATE_BEYOND_300_UNITS = 1.00; // Rs 1 per unit
    const double METER_CHARGE = 100.00; // Minimum meter charge
    const double SURCHARGE_PERCENTAGE = 0.15; // 15% surcharge if total amount > Rs 400

    // Calculating charges
    double totalAmount = 0.0;

    if (unitsConsumed <= 200) {
        totalAmount = unitsConsumed * 0.80;
    } else if (unitsConsumed <= 300) {
        totalAmount = 200 * 0.80   + (unitsConsumed - 200) * RATE_NEXT_100_UNITS;
    } else {
        totalAmount = 200 * RATE_FIRST_200_UNITS + 100 * RATE_NEXT_100_UNITS + (unitsConsumed - 300) * RATE_BEYOND_300_UNITS;
    }

    // Adding minimum meter charge
totalAmount += METER_CHARGE;



    // Applying surcharge if total amount > Rs 400
    if (totalAmount > 400.00) {
        totalAmount = SURCHARGE_PERCENTAGE * totalAmount  ;
    }

    // Output: printing charges
    cout << fixed << setprecision(2); // Set precision for displaying amounts
    cout << "Hello, " << userName << "!" << endl;
    cout << "Total Charges: Rs. " << totalAmount << endl;

    return 0;
}
