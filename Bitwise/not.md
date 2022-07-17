 # NOT(~)

* ### Unsigned Numbers

| **Valor**        | **32 Bits** |
|------------------|----------|
| mín=0            | 00...000 |
| máx = $2^{32}-1$ | 11...111 |  

:warning: O valor máximo que podemos armazenar neste tipo de variável é $2^{32}-1=4294967295$

### Exemplo 1:
Considerando o código abaixo

```cpp
 int main()
{
    unsigned int x = 1;
    std::cout << (~x) << std::endl;
    return 0;
}
```
| x:  | 00...001 |
|-----|----------|
| ~x: | 11...110 |

> Saída: $4294967295-1=4294967294$


### Exemplo 2:
```cpp
 int main()
{
    unsigned int x = 3;
    std::cout << (~x) << std::endl;
    return 0;
}
``` 
| x:  | 00...101 |
|-----|----------|
| ~x: | 11...010 |

> Saída: $4294967295-3=4294967292$

* ### Signed Numbers
:information_source: A variação fica compreendida no intervalo $[-2^{31}, 2^{31}-1]$

|   **Valor**  | **32 Bits** |
|:------------:|:-----------:|
| mín=$-2^{31}$ |    10...000 |
| máx=$2^{31}-1$  |    01...111 |

### :fire: Complemento de 2
Representação de inteiros negativos. Enumeramos 2 consequências dessa representação:
* o zero passa a ter uma única representação
* a operação de subtração é realizada como uma soma

> Considere o exemplo de uma representação com 3 bits
> | **3 Bits** | **Valor** |
>|:----------:|:---------:|
>| 000        |     0     |
>| 001        |     1     |
>| 010        |     2     |
>| 011        |     3     |
>| 100        |     -4    |
>| 101        |     -3    |
>| 110        |     -2    |
>| 111        |     -1    |

:information_source: Representação do número negativo $x$ com $n$ bits em complemento de 2 é dada pela fórmula $2^n+x$

### Exemplo 3: 
![equation](https://latex.codecogs.com/png.latex?%5Cbegin%7Barray%7D%7Bccc%7D%20n%3D3%5Ctext%7B%20bits%20%7D%20x%3D-4%5C%5C%202%5E3-4%3D8-4%3D4%5CRightarrow%20100%5C%5C%20%5C%5C%20n%3D3%5Ctext%7B%20bits%20%7D%20x%3D-1%5C%5C%202%5E3-1%3D8-1%3D7%5CRightarrow%20111%5C%5C%20%5Cend%7Barray%7D)

### Exemplo 4:
Subtrair 
### Exemplo 5:
Aplicando a fórmula $2^n+x$ podemos estimar os resultados dos seguintes códigos

* Código 1:

```cpp
 int main()
{
    int x = 3;
    std::cout << (~x) << std::endl;
    return 0;
}
``` 
|  x: | 00...011 |      3     |
|:---:|:--------:|:----------:|
| ~x: | 11...100 | $2^{32}-4$ |
