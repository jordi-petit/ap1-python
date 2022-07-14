
# 02 · Bucles

## Introducció

### Escriure els nombres de 1..n

```python
n = 13

i = 1
while i <= n:
    print(i)
    i = i + 1
```

### Escriure els nombres senars de 1..n

```python
n = 13

i = 1
while i <= n:
    print(i)
    i = i + 2
```

### Escriure els nombres n..1

```python
n = 13

while n >= 1:
    print(n)
    n = n - 1
```

### Pintar un quadrat

```python
from turtle import *

mida = 100
i = 1
while i <= 4:
    forward(mida)
    left(90)
    i = i + 1
```

### Pintar un polígon regular

```python
from turtle import *
from yogi import *

costats = read(int)  # nombre de costats
mida = read(int)  # mida
i = 1
while i <= costats:
    forward(mida)
    left(360 / costats)
    i = i + 1
```

### Factorial: calcular n! 

```python
from yogi import *

n = read(int)
i = 2
f = 1
while i <= n:
    f = f * i
    i = i + 1
print(f)
```

### Escriure tots els divisors de n (fins a n)

```python
from yogi import *

n = read(int)
d = 1
while d <= n:
    if n % d == 0:
        print(d)
    d = d + 1
```

### Escriure tots els divisors de n (fins a l'arrel)

```python
from yogi import *

n = read(int)
d = 1
while d * d < n:
    if n % d == 0:
        print(d, n // d)
    d = d + 1
if d * d == n:
    print(d)
```

⏰ Veure la diferència de temps per un n gran

### Suma dels dígits d'un nombre

```python
from yogi import *

n = read(int)
s = 0
while n != 0:         
    s = s + n % 10
    n = n // 10
print(s)
```


### Nombre de dígits d'un nombre

```python
from yogi import *

n = read(int)
if n == 0:
    d = 1
else:
    d = 0
    while n != 0:         
        d = d + 1
        n = n // 10
print(d)
```


## Bucles dins de bucles

### Taules de multiplicar

```python
i = 0
while i <= 10:
    j = 0
    while j <= 10:
        print(i, '*', j, '=', i * j)
        j = j + 1
    i = i + 1 
    print()
```

Millor: escriure amb format de text:

```python
print(f'{i:2d} * {j:2d} = {i * j:3d}')
```

### Pintar n quadrats rotats 

```python
from turtle import *

n = 12  # nombre de rotacions
i = 0
while i <= n:    
    j = 1
    while j <= 4:
        forward(100)
        right(90)
        j = j + 1
    i = i + 1 
    right(360 / n)
```

## Màxim comú divisor

### Màxim comú divisor (definició)

```python
from yogi import *

x = read(int)
y = read(int)
d = x
while not (x%d == 0 and y%d == 0):
    d = d - 1
print(d)
```

### Lleis de De Morgan

```
not (A and B)  = (not A) or  (not B)
not (A or  B)  = (not A) and (not B)
```

```python
from yogi import *

x = read(int)
y = read(int)
d = x
while x%d != 0 or y%d != 0:
    d = d - 1
print(d)
```

### Màxim comú divisor (euclides amb restes)

```python
from yogi import *

x = read(int)
y = read(int)
while x != y
    if x > y:
        x = x - y
    else:
        y = y - x
print(x)
```

### Màxim comú divisor (Euclides amb mòduls)

```python
from yogi import *

x = read(int)
y = read(int)
while y != 0:
    r = x % y
    x = y
    y = r
print(x)
```

## Bucle for-range

### Escriure nombres de 1..n

```python
n = 13
for i in range(1, n + 1):
    print(i)
```

### Escriure nombres senars de 1..n

```python
n = 13
for i in range(1, n + 1, 2):
    print(i)
```

### Escriure nombres de n..1

```python
n = 13
for i in range(n, 0, -1):
    print(i)
```

### Range

```pycon
>>> range(10)
range(0, 10)  🥲
>>> list(range(10))
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> list(range(3, 10))
[3, 4, 5, 6, 7, 8, 9]
>>> list(range(3, 10, 2))
[3, 5, 7, 9]
```

### Factorial: calcular n! 

```python
from yogi import *

x = read(int)
f = 1
for i in range(2, n + 1):
    f = f * i
print(f)
```

### Pintar un triangle de rodones

```python
from yogi import *

n = read(int)
for i in range(1, n + 1):
    for j in range(i):
        print('🟣', end='')
    print()
```

### Repeticions de textos

```pycon
>>> 'A' * 5
'AAAAA'
>>> 'pa' * 3
'papapa'
>>> 3 * 'pa'
'papapa'
>>> 0 * 'pa'
''
```

### Pintar un triangle de rodones amb repeticions de textos

```python
from yogi import *

n = read(int)
for i in range(1, n + 1):
    print('🟣' * i)
```
