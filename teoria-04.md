
# 04 · Recursivitat

### Factorial 

```python
def factorial(n: int) -> int:
    """donat un natural retorna el seu factorial"""
    if n == 0:
        return 1 
    else:
        return n * factorial(n - 1)
```


### Escriure n en base b

```python
def escriure_base(n: int, b: int) -> None:
    if n >= b:
        escriure_base(n // b, b)
    print(n % b, end='')
```


### Triangle de Koch 

```python
from turtle import *

def fractal_koch(n: int, l: float) -> None:
    if n == 1:
        forward(l)
    else:
        fractal_koch(n - 1, l / 3)
        left(60)
        fractal_koch(n - 1, l / 3)
        right(120)
        fractal_koch(n - 1, l / 3)
        left(60)
        fractal_koch(n - 1, l / 3)

def triangle_koch(n: int, l: float) -> None:
    for i in range(3):
        fractal_koch(n, l)
        right(120)

triangle_koch(5, 200)
done()
```


### Torres de Hanoi 

```python
def hanoi(n: int, src: str, dst: str, aux: str) -> None:
    if n > 0:
        hanoi(n - 1, src, aux, dst)
        print(src, '->', dst)
        hanoi(n - 1, aux, dst, src)

hanoi(5, 'A', 'B', 'C')
```


### Evaluar expressió prefixada

L'entrada és un text del tipus + 2 * 3 5 (=17).

```python
def eval() -> int:
    op = read()
    if op == '+':
        return eval() + eval()
    elif op == '-':
        return eval() - eval()
    elif op == '*':
        return eval() * eval()
    else:
        return int(op)

print(eval())
```
