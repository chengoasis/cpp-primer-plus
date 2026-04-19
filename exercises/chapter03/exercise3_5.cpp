#include <iostream>

int main() {
    using namespace std;

    long long population, us_population;
    cout << "Enter the world's population: ";
    cin >> population;
    cout << "Enter the population of the US: ";
    cin >> us_population;

    double percentage = 100.0 * us_population / population;

    cout << "The population of the US is ";
    cout << percentage;
    cout << "% of the world populations." << endl;
    return 0;
}