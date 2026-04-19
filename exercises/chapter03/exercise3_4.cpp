#include <iostream>

int main() {
    using namespace std;

    const int HOURS_PRE_DAY = 24;
    const int MINUTES_PRE_HOURS = 60;
    const int SECONDS_PRE_MINUTES = 60;

    const int SECONDS_PRE_HOURS = SECONDS_PRE_MINUTES * MINUTES_PRE_HOURS;
    const int SECONDS_PRE_DAY = SECONDS_PRE_HOURS * HOURS_PRE_DAY;

    long long total_seconds;
    cout << "Enter the number of seconds: ";
    cin >>  total_seconds;

    long long days = total_seconds / SECONDS_PRE_DAY;
    long long remain_seconds = total_seconds % SECONDS_PRE_DAY;

    long long hours = remain_seconds / SECONDS_PRE_HOURS;
    remain_seconds = remain_seconds % SECONDS_PRE_HOURS;

    long long minutes = remain_seconds / SECONDS_PRE_MINUTES;
    long long seconds = remain_seconds % SECONDS_PRE_MINUTES;

    cout << total_seconds << " seconds = ";
    cout << days << " days, ";
    cout << hours << " hours, ";
    cout << minutes << " minutes, ";
    cout << seconds << " seconds" << endl;

    return 0;
}