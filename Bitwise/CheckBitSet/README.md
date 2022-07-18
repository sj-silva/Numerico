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
