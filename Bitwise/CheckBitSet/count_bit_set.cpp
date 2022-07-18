#include <iostream>

void count_bits(int n) {
    int conta = 0;
    while (n > 0) {
        conta = conta + (n & 1);
        n = n >> 1;
    }
    std::cout << "Total bits(naive): "<<conta << std::endl;
}

void brian_kernighan(int n) {
    int conta = 0;
    while (n > 0) {
        n = n & (n - 1);
        conta++;
    }
    std::cout << "Total bits(Brian Kernighan): " << conta << std::endl;
}

int main()
{
    count_bits(19);
    brian_kernighan(19);

    std::cout << "-- Fim --\n";
    std::cin.get();
    
    return 0;
}
