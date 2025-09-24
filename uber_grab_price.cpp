#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// Rates (RM per km)
constexpr double GRAB_PER_KM = 1.20;
constexpr double UBER_PER_KM = 1.30;

// Format currency with up to 2 decimal places but trim trailing zeros:
// e.g. 3.60 -> "3.6", 3.00 -> "3"
string formatCurrency(double amount) {
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    string s = oss.str();
    // trim trailing zeros
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    return s;
}

// Display header
void displayHeader() {
    cout << "\n======== Ride Fare Calculator =========" << endl;
    cout << "|   Compare GrabCar and Uber fares    |" << endl;
    cout << "=======================================\n" << endl;
}

int main() {
    displayHeader();

    double distanceKm;
        
    cout << "Enter distance in km: ";

    if (!(cin >> distanceKm)) {
        cerr << "Invalid input. Please enter a numeric distance (e.g., 3 or 2.5)." << endl;
        return 1;
    }

    if (distanceKm < 0 || distanceKm == 0) {
        cerr << "Distance cannot be negative or zero." << endl;
        return 1;
    }

    double grabPrice = distanceKm * GRAB_PER_KM;
    double uberPrice = distanceKm * UBER_PER_KM;

    // Output
    cout << "\n======== Total Fare ========" << endl;
    cout << "GrabCar: RM " << formatCurrency(grabPrice) << endl;
    cout << "Uber: RM " << formatCurrency(uberPrice) << endl;

    if (grabPrice < uberPrice) {
        cout << "\nGrabCar is cheaper by RM " << formatCurrency(uberPrice - grabPrice) << endl;
    } else if (uberPrice < grabPrice) {
        cout << "\nUber is cheaper by RM " << formatCurrency(grabPrice - uberPrice) << endl;
    }

    cout << "\nThank you for using the Ride Fare Calculator!" << endl;
    return 0;
}