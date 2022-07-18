#include <iostream>

void kth_bit_left(int n, int k) {
    
    int c = 1 << (k-1);
    bool isSet = n & c;
    if(isSet)
        std::cout << "Is set" << std::endl;
    else
        std::cout << "Not set" << std::endl;
}

void kth_bit_right(int n, int k) {

    int c = n >> (k - 1);
    bool isSet = c & 1;
    if (isSet)
        std::cout << "Is set" << std::endl;
    else
        std::cout << "Not set" << std::endl;
}


int main()
{
    kth_bit_left(5, 3);
    kth_bit_right(19,4);
    std::cout << "-- Fim --\n";
    std::cin.get();
    
    return 0;
}
