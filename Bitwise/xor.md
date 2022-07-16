## XOR 

* Esta operação equivale a soma módulo 2.
* Forma analítica:  $f(x,y)=x+y-2xy$
* Expressão Equivalente:
  - XOR =  $(A\cdot\bar{B})+(\bar{A} \cdot B)$ = (A AND ~B) OR (~A AND B)
   
| A | B | ~A | ~B | A AND ~B | ~A AND B | (A AND ~B) OR (~A AND B) |
|:-:|:-:|:--:|:--:|:--------:|:--------:|:------------------------:|
| 0 | 0 |  1 |  1 |     0    |     0    |             0            |
| 0 | 1 |  1 |  0 |     0    |     1    |             1            |
| 1 | 0 |  0 |  1 |     1    |     0    |             1            |
| 1 | 1 |  0 |  0 |     0    |     0    |             0            |

  - XOR =  $(A+B)\cdot(\bar{A}+\bar{B})$ = (A OR B) AND (~A OR ~B)

| A | B | ~A | ~B | A OR B | ~A OR ~B | (A OR B) AND (~A OR ~B) |
|:-:|:-:|:--:|:--:|:------:|:--------:|:-----------------------:|
| 0 | 0 |  1 |  1 |    0   |     1    |            0            |
| 0 | 1 |  1 |  0 |    1   |     1    |            1            |
| 1 | 0 |  0 |  1 |    1   |     1    |            1            |
| 1 | 1 |  0 |  0 |    1   |     0    |            0            |
