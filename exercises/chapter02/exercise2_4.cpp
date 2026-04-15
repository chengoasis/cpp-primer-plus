#include <iostream>

int main() {
    using namespace std;
    
    int years, months;
    cout << "Enter your age: ";
    cin >> years;

    months = years * 12;
    cout << years << " years is " << months << " monthes." << endl;
    return 0;
}