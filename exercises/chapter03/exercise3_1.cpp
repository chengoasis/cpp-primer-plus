#include <iostream>

int main() {
    using namespace std;
    
    const int INCHES_PER_FOOT = 12;

    int total_inches;

    cout << "Please enter your hight: ";
    cin >> total_inches;

    int feet = total_inches / INCHES_PER_FOOT;
    int inches = total_inches % INCHES_PER_FOOT;

    cout << total_inches << " 英寸 = "
         << feet << " 英尺 " << inches << " 英寸." << endl;
         
    return 0;
}