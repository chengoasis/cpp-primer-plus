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