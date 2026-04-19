#include <iostream>

int main() {
    using namespace std;

    const double MILES_PRE_100KM = 62.14;
    const double LITERS_PER_GALLON = 3.875;
    const double CONVERSION = MILES_PRE_100KM * LITERS_PER_GALLON;

    double eu_consumption;
    cout << "请输入欧洲风格的耗油量（升/100公里）: ";
    cin >> eu_consumption;

    double mpg = CONVERSION / eu_consumption;

    cout << "===转换结果===" << endl;
    cout << "欧制: " << eu_consumption << " 升/100公里" << endl;
    cout << "美制: " << mpg << " 英里/加仑" << endl;

    return 0;
}