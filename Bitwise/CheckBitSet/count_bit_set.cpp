#include <iostream>

void count_bits(int n) {
    int conta = 0;
    while (n > 0) {
        conta = conta + (n & 1);
        n = n >> 1;
    }
    std::cout << "Total bits: "<<conta << std::endl;
}

int main()
{
    count_bits(16);
    std::cout << "-- Fim --\n";
    std::cin.get();
    
    return 0;
}
