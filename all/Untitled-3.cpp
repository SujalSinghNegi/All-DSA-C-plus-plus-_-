#include <iostream>
#include <exception>
using namespace std;

void customUnexpected() {
    cout << "Custom unexpected handler called!" << endl;
    exit(1);
}

void func() throw(int) { // Exception specification
    throw 'c'; // Throws unexpected exception
}

int main() {
    set_unexpected(customUnexpected);
    try {
        func();
    } catch (...) {
        cout << "Caught exception" << endl;
    }
}
