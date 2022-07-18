#include <iostream>

void check_set(int n, int k) {
    
    int c = 1 << (k-1);
    bool isSet = n & c;
    if(isSet)
        std::cout << "Is set" << std::endl;
    else
        std::cout << "Not set" << std::endl;
}


int main()
{
    check_set(5, 3);
    std::cout << "-- Fim --\n";
    std::cin.get();
    
    return 0;
}
