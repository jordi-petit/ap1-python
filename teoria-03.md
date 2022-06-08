# 03 · Subprogrames i tipus


**Nomenclatura:** Una funció té una *capçalera*, una *documentació* i un *cos*. Els *paràmetres formals* són els paràmetres són per definir la funció, els *paràmetres reals* són per utilitzar la funció. Les funcions només s'haurien de comunicar a través dels seus paràmetres. De moment guardem el terme *funció* per subprograma que retorna un resultat i no provoca cap efecte (funció pura) i *acció* per subprograma que no retorna res i provoca algun efecte (escriptura, lectura, llançament de míssils, ...).

## Funcions 

### màxim2 

```python
def màxim2(x: int, y: int) -> int:
    """retorna el màxim de dos enters"""
    if x >= y:
        return x 
    else:
        return y

a = read(int)
b = read(int)
m = màxim2(a, b)
print(m)
```

### màxim3 

```python
def màxim2(x: int, y: int) -> int:
    """retorna el màxim de dos enters"""
    if x >= y:
        return x 
    else:
        return y

def màxim3(x: int, y: int, z: int) -> int:
    """retorna el màxim de tres enters"""
    return màxim2(màxim2(x, y), z)

a = read(int)
b = read(int)
c = read(int)
m = màxim3(a, b, c)
print(m)
```


### Factorial 

```python
def factorial(n: int) -> int:
    """donat un natural retorna el seu factorial"""
    f = 1
    for i in range(2, n + 1):
        f = f * i
    return f
```

### Primalitat per prova de divisors 

Lenta:

```python
def es_primer(n: int) -> bool:
    """donat un natural retorna si és o no primer"""
    if n <= 1:
        return False 
    for d in range(2, n):
        if n % d == 0:
            return False 
    return True

print(es_primer(100000007))
```

Ràpida:

```python
def es_primer(n: int) -> bool:
    """donat un natural retorna si és o no primer"""
    if n <= 1:
        return False 
    d = 2
    while d * d <= n:
        if n % d == 0:
            return False 
        d = d + 1
    return True

print(es_primer(100000007))
```

⏰ Comparació de temps (100000007 és primer)


## Tipus

1. Tipus bàsics: int, float, bool, str
1. Funcions predefinides: max, min, abs 
1. import math: pi, e, inf, sqrt, isqrt, factorial, gcd, sin, cos, tan, asin, acos, atan, ...
1. Conversions: int(), float(), str()

```pycon
>>> 11 // 2
5
>>> 11 / 2
5.5
>>> type(11 // 2)
<class 'int'>
>>> type(11 / 2)
<class 'float'>
>>> type(11 == 2)
<class 'bool'>
>>> type('Marta')
<class 'str'>

>>> max(45, 12)
45
>>> min(45, 12)
12
>>> min('petit', 'gran')
'gran'
>>> 'petit' < 'gran'
False

>>> int(3.1)
3
>>> int(3.9)
3
>>> int('123')
123
>>> float(13)
13.0
>>> float('3.50')
3.5
>>> str(45)
'45'
>>> str(45.5)
'45.5'
```

## Accions

### Escriure un rectangle / un quadrat

```python
def escriure_rectangle(files: int, columnes: int, caràcter: str) -> None:
    """escriu un rectangle de mida files⨉columnes utilitzant caràcter"""
    for i in range(files):
        print(caràcter * columnes)

def escriure_quadrat(mida: int, caràcter: str) -> None:
    """escriu un rectangle de mida mida⨉mida utilitzant caràcter"""
    escriure_rectangle(mida, mida, caràcter)

escriure_rectangle(3, 3, 'O')
print()
escriure_quadrat(3, 'O')
```


### Escriure un nombre del revés

```python
def escriure_del_revés(n: int) -> None:
    if n == 0:
        print(0)
    else:
        while n != 0:
            print(n % 10, end='')
            n = n // 10
        print()
```

```python
def escriure_del_revés(n: int) -> None:
    if n == 0:
        print(0)
        return   # Return None
    while n != 0:
        print(n % 10, end='')
        n = n // 10
    print()
```


### Pintar un quadrat amb turtle

```python
def pintar_quadrat(mida: int) -> None:
    for _ in range(4):
        forward(mida)
        left(90)

# aplicació: pintar molts quadrats rotats
rotacions = 12
for _ in range(rotacions):
    pintar_quadrat(100)
    right(360 / rotacions)
```


### Pintar un polígon regular amb turtle

```python
def pintar_polígon_regular(mida: int, costats: int) -> None:
    for _ in range(costats):
        forward(mida)
        left(360 / mida)

def pintar_quadrat(mida: int) -> None:
    pintar_polígon_regular(mida, 4)
```

## Funcions que retornen més d'un valor

Algunes vegades ens calen funcions que retornen més d'un valor: tuples.

### Descomposició horària

```python
def descomposió_horària(n: int) -> tuple[int, int, int]:
    h = n // 3600
    m = (n // 60) % 60
    s = n % 60
    return h, m, s

# desempaquetar el resultat és fàcil:
hh, mm, ss = descomposió_horària(4376)
```


### Sumar un segon a una hora

```python
def sumar_un_segon(h: int, m: int, s: int) -> tuple[int, int, int]:
    s = s + 1
    if s == 60:
        s = 0
        m = m + 1
        if m == 60:
            m = 0
            h = h + 1
            if h == 24:
                h = 0
    return h, m, s

# i ara ja es pot instroduir l'assignació múltiple:
h, m, s = 23, 59, 59
h, m, s = sumar_un_segon(h, m, s)
print(h, m, s)
```

## Assignació múltiple

```pycon
>>> a, b = 1, 2
>>> a
1
>>> b
2
>>> x, y = a, b
>>> x
1
>>> y
2
>>> y, x = x, y
>>> x
2
>>> y
1
```