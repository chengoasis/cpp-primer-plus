// exceed.cpp -- exceeding some integer limits
#include <iostream>
#define ZERO 0
#include <climits>

int main() {
    using namespace std;

    short sam = SHRT_MAX;
    unsigned short sue = sam;

    cout << "sam has " << sam << " dollars and sue has " << sue;
    cout << " dollars deposited." << endl;
    sam = sam + 1;
    sue = sue + 1;
    cout << "sam has " << sam << " dollars and sue has " << sue;
    cout << " dollars deposited.\nPoor Sam!" << endl;
    sam = ZERO;
    sue = ZERO;
    cout << "sam has " << sam << " dollars and sue has " << sue;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl;
    sam = sam - 1;
    sue = sue - 1;
    cout << "sam has " << sam << " dollars and sue has " << sue;
    cout << " dollars deposited." << endl;
    return 0;
}