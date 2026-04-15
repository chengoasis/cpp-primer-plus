# 第 2 章 Learn C++

## 复习题

**2.1 C++程序的模块叫什么？** 

函数

**2.2 下面的预处理器编译指令是做什么用的？** 

```c++
#include <iostream>
```

在最终编译之前，使用 iostream 文件的内容替换该编译指令。

**2.3 下面的语句是做什么用的？**

```cpp
using namespace std;
```

使程序可以使用 std 名称空间中的定义。

**2.4 什么语句可以用来打印短语“Hello，world”，然后开始新的一 行？** 

```c++
cout << "Hello, world\n";
cout << "Hello, world" << endl;
```

**2.5 什么语句可以用来创建名为cheeses的整数变量？**

```cpp
int cheeses;
```

**2.6 什么语句可以用来将值32赋给变量cheeses？** 

```cpp
chesses = 32;
```

**2.7 什么语句可以用来将从键盘输入的值读入变量cheeses中？** 

```cpp
cin >> chesses;
```

**2.8 什么语句可以用来打印“We have X varieties of cheese,”，其中X 为变量cheeses的当前值。** 

```cpp
cout << "We have " << chesses << " varieties of chesse,";
```

**2.9 下面的函数原型指出了关于函数的哪些信息？** 

```cpp
int froop(double t);
void rattle(int n);
int prune(void);
```

函数froop 接受一个 double 类型的参数，返回类型为 int

函数 rattle 接受一个 int 类型的参数，没有返回参数

函数 prune 不接受餐素，返回一个 int

**2.10 定义函数时，在什么情况下不必使用关键字return？** 

返回类型为 void

**2.11 假设您编写的main( )函数包含如下代码： **

```cpp
cout << "Please enter your PIN: ";
```

**而编译器指出cout是一个未知标识符。导致这种问题的原因很可能 是什么？指出3种修复这种问题的方法。**

可能是没有引入 std 命名空间。解决方法：

```cpp
std::cout << "...";
using namespace std;
using std::cout;
```



## 编程练习

**2.1 编写一个C++程序，它显示您的姓名和地址。**

```Cpp
# include <iostream>

int main() {
    using namespace std;

    cout << "I am Cheng from HangZhou!!!" << endl;
    return 0;
}
```

**2.2 编写一个C++程序，它要求用户输入一个以 long 为单位的距离， 然后将它转换为码（yard，一long 等于 220 码）。**


```Cpp
#include <iostream>

int main() {
    long dis;
    std::cout << "Please enter a distance in 'long' units: ";
    std::cin >> dis;
    std::cout << "This distance, converted to yards, is: " << dis * 220 << std::endl;
    return 0;
}
```

**2.3 编写一个C++程序，它使用 3 个用户定义的函数（包括main()），并生成下面的输出：**

```bash
Three blind mice
Three blind mice
See how they run
See how they run
```
**其中一个函数要调用两次，该函数生成前两行；另一个函数也被调用两次，并生成其余的输出。**


```Cpp
#include <iostream>

using namespace std;

void blind_mice();
void how_they_run();

int main() {
    blind_mice();
    blind_mice();
    how_they_run();
    how_they_run();
    return 0;
}

void blind_mice() {
    cout << "Three blind mice" << endl;
}

void how_they_run() {
    cout << "See how they run" << endl;
}
```

**2.4 编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月，如下所示：**

```bash
Enter your age: 29
```

```Cpp
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
```

**2.5 编写一个程序，其中的main( )调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。该程序按下面的格式要 求用户输入摄氏温度值，并显示结果：**

```bash
Please enter a Celsius value: 20
20 degrees Celsius is 68 degrees Fahrenheit.
```

**转换公式：华氏温度 = 1.8×摄氏温度 + 32.0**

```Cpp
#include <iostream>

using namespace std;

double celsius_to_fahrenheit(double celsius) {
    return 1.8 * celsius + 32.0;
}

int main() {
    double celsius;
    cout << "Please enter a Celsius value: ";
    cin >> celsius;
    double fahrenheit = celsius_to_fahrenheit(celsius);
    cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit" << endl;
    return 0;
}
```

**2.6 编写一个程序，其main( )调用一个用户定义的函数（以光年值为参数，并返回对应天文单位的值）。该程序按下面的格式要求用户输 入光年值，并显示结果：**

```bash
Enter the number of light years: 4.2
4.2 light years = 265608 astromonical units.
```
**天文单位是从地球到太阳的平均距离（约150000000公里或93000000英里），光年是光一年走的距离（约10万亿公里或6万亿英里）（除太阳外，最近的恒星大约离地球4.2光年）。请使用double类型，转换公式为：1光年=63240天文单位**

```Cpp
#include <iostream>

using namespace std;

double light_to_astronomical(double years) {
    return years * 63240.0;
}

int main() {
    double light_years;
    cout << "Enter the number of light years: ";
    cin >> light_years;
    double ast;
    ast = light_to_astronomical(light_years);
    cout << light_years << " light years = " << ast << " astronomical units." << endl;
    return 0;
}
```

**2.7 编写一个程序，要求用户输入小时数和分钟数。在 main() 函数中，将这两个值传递给一个void函数，后者以下面这样的格式显示这两个值：**

```bash
Enter the number of hours: 9
Enter the number of minutes: 28
Time: 9:28
```

```Cpp
#include <iostream>

using namespace std;

void display_time(int h, int m) {
    cout << "Time: " << h << ":" << m << endl;;
}

int main() {
    int hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    display_time(hours, minutes);
    return 0;
}
```





