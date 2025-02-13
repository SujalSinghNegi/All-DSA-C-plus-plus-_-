#include <iostream>
#include <iomanip> // For manipulators like setw, setprecision

int main() {
    double num = 1234.56789;

    std::cout << "Default: " << num << std::endl;
    std::cout << "Fixed: " << std::fixed << std::setprecision(2) << num << std::endl;
    std::cout << "Scientific: " << std::scientific << num << std::endl;
    std::cout << "Width and Fill: " << std::setw(10) << std::setfill('*') << num << std::endl;

    return 0;
}
