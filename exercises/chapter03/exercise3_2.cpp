#include <iostream>

int main() {
    using namespace std;

    const int INCHES_PER_FOOT = 12;
    const double METER_PER_INCH = 0.0254;
    const double KG_PER_POUND = 1.0 / 2.2;

    int feet, inches; 
    double pounds;

    cout << "Please enter your height (in feet and inches): ";
    cin >> feet >> inches;
    cout << "Please enter your weight: ";
    cin >> pounds;

    double height = (feet * INCHES_PER_FOOT + inches) * METER_PER_INCH;
    double weight = pounds * KG_PER_POUND;

    double bmi = weight / (height * height);

    cout << "\n ========= BMI =========" << endl;
    cout << "身高: " << feet << " 英尺 " << inches << " 英寸 = " 
         << height << " 米" << endl;
    cout << "体重: " << pounds << " 磅 = " << weight << " 千克" << endl;
    cout << "BMI: " << bmi << endl;

    return 0;
}