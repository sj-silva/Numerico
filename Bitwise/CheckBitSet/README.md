# Check bit set

Observar se o ***k-ésimo*** bit no número ***n***  está ***ligado***.

### :fire: Máscara 1
Usamos o *left-shift*. 
* Movemos *(k-1)* bits para esquerda o número **1** 
* Aplicamos o operador *AND*

**n &(1<<(k-1))**

### :fire: Máscara 2
Usamos o *right-shift*. 
* Movemos *(k-1)* vezes os bits do número **n**  
* Aplicamos o operador *AND* com o número **1**

**((n>>(k-1)) & 1)**

### :fire: Algoritmo Brian Kernighan

Ao subtrair *1* unidade de um número todos os bits a partir o último *1* serão trocados. Com isso o $1\Rightarrow 0$ e $0\Rightarrow 1$   

| 19 | 10011 |
|:--:|:-----:|
| 18 | 10010 |
| 17 | 10001 |
| 16 | 10000 |
| 15 | 01111 |

```cpp
void brian_kernighan(int n) {
    int conta = 0;
    while (n > 0) {
        n = n & (n - 1);
        conta++;
    }
    std::cout << "Total bits(Brian Kernighan): " << conta << std::endl;
}
```

### :fire: Lookup Table
1. Considerando que um inteiro tem 32 bits dividimos em 4 blocos de 8 bits.

| **00000000** | 00000000 | **00000000** | 00000000 |
|:------------:|:--------:|--------------|----------|

2. Cada bloco representa um número no intervalo $[0,255]$

3. Criamos uma tabela de tamanho $256$  onde **table[i] = número de set bits do número i**

| _table[0]=0_ |
|:------------:|
| _table[1]=1_ |
| _table[2]=1_ |
| _table[3]=2_ |
| _table[4]=1_ |
| _table[5]=2_ |

4. Criamos a máscara **m=0xff=11111111**. Ao fazermos **table[n&m]** teremos como resultado o número de **set bits** do primeiro bloco. 

5. Fazemos um loop com **n=n>>8**

```cpp
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
```
