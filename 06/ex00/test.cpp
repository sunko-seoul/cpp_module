#include <iostream>
#include <limits>

int main() {

    float a = 3.40282e+40;
    if (a > std::numeric_limits<float>::min())
        std::cout << "overflow" << std::endl;
    std::cout << "Minimum value of float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Maximum value of float: " << std::numeric_limits<float>::max() << std::endl;

    int c = 2147483648;
    if (c > std::numeric_limits<int>::max())
            std::cout << "int overflow" << std::endl;

    return 0;
}
