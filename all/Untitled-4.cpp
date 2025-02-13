#include <iostream>
#include <exception>
using namespace std;

[[noreturn]] void customTerminate() {
    cout << "Custom terminate handler called!" << endl;
    exit(1);
}

void func() noexcept(false) { // Use noexcept instead of throw(type)
    throw 'c'; // This will invoke terminate since it's not handled
}

int main() {
    set_terminate(customTerminate); // Set a custom terminate handler

    try {
        func(); // Throws an exception
    } catch (int e) {
        cout << "Caught int exception: " << e << endl;
    } catch (...) {
        cout << "Caught unknown exception" << endl;
    }

    cout<<"hello"<<endl;

    return 0;
}
