#include <iostream>

using namespace std;

double light_to_astronomical(double years) {
    return years * 63240.0;
}

int main() {
    double light_years;
    cout << "Enter the number of light years: ";
    cin >> light_years;
    double ast;
    ast = light_to_astronomical(light_years);
    cout << light_years << " light years = " << ast << " astronomical units." << endl;
    return 0;
}