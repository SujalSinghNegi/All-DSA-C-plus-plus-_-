#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Base* obj = new Derived();
    Derived* derivedObj = dynamic_cast<Derived*>(obj); // Safe downcast
    if (derivedObj) {
        cout << "Cast successful!" << endl;
    } else {
        cout << "Cast failed!" << endl;
    }
    delete obj;
    return 0;
}
