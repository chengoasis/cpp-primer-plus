// floatnum.cpp -- floating-point types
// #include <iostream>
// int main() {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     float tub = 10.0 / 3.0;
//     double mint = 10.0 / 3.0;
//     const float million = 1.0e6;

//     cout << "tub = " << tub;
//     cout << ", a million tubs = " << million * tub;
//     cout << ",\nand ten million tubs = ";
//     cout << 10 * million * tub << endl;

//     cout << "mint = " << mint << " and a million mints = ";
//     cout << million * mint << endl;
//     return 0;
// }

// floatnum.cpp -- floating-point types (Modern C++ version)
#include <iostream>
#include <iomanip>  // 用于 setprecision

int main() {
    using namespace std;
    
    // 现代写法：使用 fixed 和 setprecision 控制格式
    cout << fixed << setprecision(6);  // 固定6位小数
    
    // 使用 auto 类型推导
    const auto tub = 10.0f / 3.0f;     // float 字面量加 f
    const auto mint = 10.0 / 3.0;      // double 是默认浮点字面量
    constexpr auto million = 1.0e6;    // constexpr 编译时常量
    
    // 输出结果
    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10.0 * million * tub << endl;
    
    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    
    return 0;
}