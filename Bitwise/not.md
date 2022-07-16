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
