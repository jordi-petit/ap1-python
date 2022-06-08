# 01 · Primers programes

## Programa que escriu Hola

```python
# programa que escriu Hola
print('Hola!')
```

## Programa que escriu Hola i Adéu

```python
# programa que escriu Hola i Adéu
print('Hola!')
print('Adéu!')
```

## Programa que pinta un triangle amb la tortuga

```python
import turtle

turtle.forward(100)
turtle.right(120)
turtle.forward(100)
turtle.right(120)
turtle.forward(100)
turtle.done()  # espera que es tanqui la finestra
```


## Programa que pinta un triangle amb mida variable

```python
import turtle

mida = 100 # això és una variable
turtle.forward(mida)
turtle.right(120)
turtle.forward(mida)
turtle.right(120)
turtle.forward(mida)
turtle.done()  
```

## Programa que pinta un 8 amb la tortuga

```python
from turtle import *

radi = 50
circle(radi)
right(180)
circle(radi)
done()
```

## Programa que llegeix un nom i saluda

```shell
pip3 install yogi
```

```python
from yogi import *

print('Com et dius?')
nom = read(str)
print('Hola', nom)
```

## Producte de dos nombres

```python
from yogi import *

x = read(int)
y = read(int)
p = x * y
print(p)
```

```python
from yogi import *

x = read(int)
y = read(int)
print(x * y)
```

```python
from yogi import *

print(read(int) * read(int))
```

## Màxim de dos valors

```python
from yogi import *

a = read(int)
b = read(int)
if a > b:
    m = a
else:
    m = b
print(m)
```

## Valor absolut

```python
from yogi import *

x = read(int)
if x < 0:
    x = -x
print(x)
```

# T12 Expressions i assignacions

## Operadors aritmètics

```
+ suma
- resta i canvi de signe
* producte
// divisió entera
% rest de la divisió entera (mòdul)
** potència
```

```pycon
>>> 2 + 3
5
>>> 2 - 4
-2
>>> 7 * 3
21
>>> 18 // 3
6
>>> 19 // 3
6
>>> 18 % 3
0
>>> 19 % 3
1
>>> 2 ** 3
8
```

Prioritat: com és habitual en matemàtiques.

```pycon
>>> 2 * 3 + 4
10
>>> 2 * (3 + 4)
14
```

## Descomposició horària

A partir d'un nombre natural `n` amb un cert temps en segons, calcular tres nombres `h`, `m` i `s` amb el mateix temps expressat en hores, minuts i segons.

```python
from yogi import *

n = read(int)
h = n // 3600
m = (n // 60) % 60
s = n % 60
print(h, m, s)
```

## Incrementar

```pycon
>>> i = 2
>>> i
2
>>> i = i + 1
>>> i
3
```

## Doblar

```pycon
>>> j = 4
>>> j
4
>>> j = j * 2
>>> j
8
```

## Operadors relacionals

```
==
!=
<
>
<=
>=
```

```pycon
>>> a = 12
>>> b = 23
>>> a == b
False
>>> a != b
True
>>> a < b
True
>>> a > b
False
>>> a <= b
True
>>> a >= b
False
```

## Operadors lògics

```
not 
and 
or
```

```pycon
>>> x = 4
>>> y = 8
>>> z = 12

>>> not x < y
False

>>> x > y or y < z
True
>>> x > y or y > z
False

>>> x < y and y < z
True
>>> x > y and y < z
False
>>> x > y and y > z
False

# això no sol funcionar en altres LPs
>>> x <= y <= z    
True
>>> x == y <= z    
False
```

## Màxim de tres nombres

```python
from yogi import *

a = read(int)
b = read(int)
c = read(int)
if a >= b and a >= c:
    m = a 
elif b >= a and b >= c:
    m = b
else:
    m = c
print(c)
```

## Sumar un segon a una hora 

```python
from yogi import *

h = read(int)
m = read(int)
s = read(int)
s = s + 1
if s == 60:
    s = 0
    m = m + 1
    if m == 60:
        m = 0
        h = h + 1
        if h == 24:
            h = 0
print(h, m, s)
```

## Intercanvi

```pycon
>>> a = 2
>>> b = 3
>>> a = b
>>> b = a ❌
```

```pycon
>>> a = 2
>>> b = 3
>>> c = a
>>> a = b
>>> b = c
>>> a
3
>>> b
2
```
