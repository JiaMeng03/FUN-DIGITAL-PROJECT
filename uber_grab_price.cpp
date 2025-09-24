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