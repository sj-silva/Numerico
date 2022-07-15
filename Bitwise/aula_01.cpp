#include <iostream>

int main()
{
    int x = 3;
    int y = 5;

    std::cout << "OR: " << (x | y) << std::endl;
    std::cout << "AND: " << (x & y) << std::endl;
    std::cout << "XOR: " << (x ^ y) << std::endl;

    std::cout << "-- Fim --\n";
    std::cin.get();
    
    return 0;
}
