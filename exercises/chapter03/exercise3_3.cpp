#include <iostream>

int main() {
    using namespace std;

    const int MINUTES_PRE_DEGREE = 60;
    const int SECONDS_PRE_MINUTES = 60;
    
    int degrees, minutes , seconds;
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    double decimal_degrees = degrees + 
                             minutes / static_cast<double>(MINUTES_PRE_DEGREE) + 
                             seconds / static_cast<double>(SECONDS_PRE_MINUTES) / MINUTES_PRE_DEGREE;

    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = "
         << decimal_degrees << " degrees" << endl;

    return 0;
}