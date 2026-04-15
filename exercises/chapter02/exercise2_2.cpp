#include <iostream>

int main() {
    long dis;
    std::cout << "Please enter a distance in 'long' units: ";
    std::cin >> dis;
    std::cout << "This distance, converted to yards, is: " << dis * 220 << std::endl;
    return 0;
}