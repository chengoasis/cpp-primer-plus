# 第 3 章 Learn C++

## 复习题

**3.1 为什么C++有多种整型？**

为了节省内存和适应不同场景。不同整型占用不同字节数，可以根据数据范围选择最合适的类型。例如：

- `short` 占 2 字节，适合小范围数值
- `int` 占 4 字节，最常用
- `long` 和 `long long` 占更大空间，适合大数值

**3.2 声明与下述描述相符的变量。**

```cpp
// a. short整数，值为80
short a = 80;

// b. unsigned int整数，值为42110
unsigned int b = 42110;

// c. 值为3000000000的整数（超出int范围，需用long long）
long long c = 3000000000LL;
```

**3.3 C++提供了什么措施来防止超出整型的范围？**

C++没有自动防止溢出的措施。超出范围会导致：

- 无符号整型：回绕（如 255+1 = 0）
- 有符号整型：未定义行为（结果不可预测）

程序员需要自己注意，或使用 `<climits>` 中的宏检查：

```cpp
#include <climits>
if (value > INT_MAX) { /* 处理溢出 */ }
```

**3.4 33L与33之间有什么区别？**

| 写法  | 类型   |
| :---- | :----- |
| `33`  | `int`  |
| `33L` | `long` |

`33L` 中的 `L` 后缀表示这是 `long` 类型的字面量。

**3.5 下面两条C++语句是否等价？**

```cpp
char grade = 65;
char grade = 'A';
```

等价。在 ASCII 编码中，65 对应字符 `'A'`。但第二种可读性更好，推荐使用。

**3.6 如何使用C++来找出编码88表示的字符？指出至少两种方法。**

```cpp
// 方法1：直接赋值并输出
char ch1 = 88;
cout << ch1 << endl;  // 输出 'X'

// 方法2：使用 static_cast
cout << static_cast<char>(88) << endl;

// 方法3：printf
printf("%c", 88);
```

**3.7 将long值赋给float变量会导致舍入误差，将long值赋给double变量呢？将long long值赋给double变量呢？**

| 转换                   | 是否有舍入误差                            |
| :--------------------- | :---------------------------------------- |
| `long` → `float`       | 可能有（float 精度约 7 位有效数字）       |
| `long` → `double`      | 通常没有（double 精度约 15-16 位）        |
| `long long` → `double` | 可能有（$2^{53}$ 以内精确，更大可能舍入） |

**原因**：`double` 有 53 位有效数字，可精确表示 $2^{53}$（约 9e15）以内的整数。

**3.8 下列C++表达式的结果分别是多少？**

```cpp
// a. 8 * 9 + 2 = 72 + 2 = 74
// b. 6 * 3 / 4 = 18 / 4 = 4（整数除法）
// c. 3 / 4 * 6 = 0 * 6 = 0（整数除法）
// d. 6.0 * 3 / 4 = 18.0 / 4 = 4.5
// e. 15 % 4 = 3
```

**3.9 假设x1和x2是两个double变量，您要将它们作为整数相加，再将结果赋给一个整型变量。请编写一条完成这项任务的C++语句。如果要将它们作为double值相加并转换为int呢？**

```cpp
double x1, x2;
int sum;

// a. 作为整数相加，结果赋给整型变量
sum = static_cast<int>(x1) + static_cast<int>(x2);

// b. 作为double值相加并转换为int
sum = static_cast<int>(x1 + x2);
```



**3.10 下面每条语句声明的变量都是什么类型？**

```cpp
auto cars = 15;           // int
auto iou = 150.37f;       // float
auto level = 'B';         // char
auto crat = U'U00002155'; // char32_t（Unicode字符）
auto fract = 8.25f/2.5;   // double（8.25f是float，2.5是double，结果提升为double）
```

**注意**：`8.25f / 2.5` 中 `float` 和 `double` 运算，结果提升为 `double`。



## 编程练习

**3.1 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。**

```cpp
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
```

**3.2 编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用3个变量来存储这些信息。）该程序报告其BMI。为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸），并将以英寸为单位的身体高转换为以米为单位的身体高（1英寸=0.0254米）。然后，将以磅为单位的体重转换为以千克为单位的体重（1千克=2.2磅）。最后，计算相应的BMI—体重（千克）除以身高（米）的平方。用符号常量表示各种转换因子。**

```cpp
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
```

**3.3 编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。**

```cpp
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
```

**3.4 编写一个程序，要求用户以整数方式输入秒数（使用long或long long变量存储），然后以天、小时、分钟和秒的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。**

```cpp
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
```

**3.5 编写一个程序，要求用户输入全球当前的人口和美国当前的人口（或其他国家的人口）。将这些信息存储在long long变量中，并让程序显示美国（或其他国家）的人口占全球人口的百分比。**

```cpp
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
```

**3.6 编写一个程序，要求用户输入驱车里程（英里）和使用汽油量（加仑），然后指出汽车耗油量为一加仑的里程。如果愿意，也可以让程序要求用户以公里为单位输入距离，并以升为单位输入汽油量，然后指出欧洲风格的结果——即每100公里的耗油量（升）。**

```cpp
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
```

**3.7 编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）），然后将其转换为美国风格的耗油量—每加仑多少英里。注意，除了使用不同的单位计量外，美国方法（距离/燃料）与欧洲方法（燃料/距离）相反。100公里等于62.14英里，1加仑等于3.875升。**

```cpp
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
```