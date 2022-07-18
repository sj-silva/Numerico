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

int table[256];

void initialize() {
    table[0] = 0;
    for (int i = 1; i < 256; i++) {
        // lembre que i/2 = i>>2( caso anterior)
        //ex: table[5] = 5&1 + table[2] = 1+1 = 2
        table[i] = (i & 1) + table[i / 2];
    }
    
}

void lookupTable(int n) {
    
    int conta = 0;
    conta+= table[n & 0xff];
    
    n = n >> 8;
    conta += table[n & 0xff];
   
    n = n >> 8; 
    conta += table[n & 0xff];
    
    n = n >> 8;
    conta += table[n & 0xff];
    
    std::cout << "Total bits(Lookup Table): " << conta << std::endl;
}

int main()
{
    initialize();

    int num = 23;
    count_bits(num);
    brian_kernighan(num);
    lookupTable(num);
    

    std::cout << "-- Fim --\n";
    std::cin.get();
    
    return 0;
}
