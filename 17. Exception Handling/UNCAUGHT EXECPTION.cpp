#include <iostream>
#include <exception>
using namespace std;

void checkException() {
    if (uncaught_exception()) {
        cout << "An exception is currently being handled." << endl;
    } else {
        cout << "No exception is being handled." << endl;
    }
}

int main() {
    try {
        throw 42;
    } catch (...) {
        checkException(); // Outputs: An exception is currently being handled.
    }
    return 0;
}
