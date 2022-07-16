# NOT(~)

### Unsigned Numbers

| **Valor**        | **32 Bits** |
|------------------|----------|
| mín=0            | 00...000 |
| máx = $2^{32}-1$ | 11...111 |  

:warning: O valor máximo que podemos armazenar neste tipo de variável é $2^{32}-1=4294967295$

Considerando o código abaixo

```cpp
 int main()
{
    unsigned int x = 1;
    std::cout << (~x) << std::endl;
    return 0;
}
```
Como 
| x:  | 00...001 |
|-----|----------|
| ~x: | 11...110 |

> Saída: $4294967295-1=4294967294$
