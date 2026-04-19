#include <iostream>

int main() {
    using namespace std;

    double miles, gallons;

    cout << "请输入驱车里程（英里）: ";
    cin >> miles;
    
    cout << "请输入使用汽油量（加仑）: ";
    cin >> gallons;

    double mpg = miles / gallons;
    cout << "该车耗油量为 " << mpg << " 英里/加仑" << endl;

    return 0;
}