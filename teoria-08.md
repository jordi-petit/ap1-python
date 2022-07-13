
# 08 · Llistes

## Operacions fonamentals

**Nomenclatura:** Les llistes de Python també es diuen *arrays*, vectors o taules en altres llenguatges. De fet, *llista* és mal nom, ja que sovint vol dir una altra cosa. En fi.



### Presentació 

**Definició:** Una llista és una col·lecció ordenada d'objectes (del mateix tipus).

```pycon
>>> llista = [50, 24, 50, 12]
>>> llista
[50, 24, 50, 12]
>>> type(llista)
<class 'list'>   
>>> len(llista)
4
>>> sum(llista)
160
>>> max(llista)
50
>>> min(llista)
12
>>> reversed(llista)
<list_reverseiterator object at 0x7fedf6a28d60>
>>> list(reversed(llista))
[12, 50, 24, 50]
>>> sorted(llista)
[12, 24, 50, 50]
>>> for x in llista: print(x)
...
50
24
50
12
```

- `len()` retorna la llargada de la llista
- `sum()` retorna la suma dels elements de la llista
- `max()` retorna el màxim dels elements de la llista
- `min()` retorna el mínim dels elements de la llista
- `list(reversed())` retorna la llista del revés(explicar el `list()` del putu python).
- `sorted(llista)` retorna la llista ordenada.


### Indexació

```pycon
>>> llista[0]
50
>>> llista[1]
24
>>> llista[2]
50
>>> llista[3]
12
>>> llista[4]
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
IndexError: list index out of range
>>> llista[-1]
12
>>> llista[1] *= 2
>>> llista
[50, 48, 50, 12]
```

Accés directe!

### Subllistes

Amb les *slices* es creen noves llistes:

```pycon
>>> xs = [30,50,10,50,60,20,50,70]
>>> xs[2:6]
[10, 50, 60, 20]
>>> xs[:6]
[30, 50, 10, 50, 60, 20]
>>> xs[:2]
[30, 50]
>>> xs[:]
[30, 50, 10, 50, 60, 20, 50, 70]
>>> xs[1:8:2]
[50, 50, 20, 70]
```

### Afegir/treure elements

```pycon
>>> xs = [10, 20, 30]
>>> xs.append(40)
>>> xs
[10, 20, 30, 40]
>>> xs.append(50)
>>> xs
[10, 20, 30, 40, 50]
>>> ys = [60, 70, 80]
>>> xs.extend(ys)
>>> xs
[10, 20, 30, 40, 50, 60, 70, 80]
>>> del(xs[3])   lent! 
>>> xs
[10, 20, 30, 50, 60, 70, 80]
>>> xs.pop()    # ràpid
80
>>> xs
[10, 20, 30, 50, 60, 70]
```

### Operadors

```pycon
>>> xs = [1, 2, 3]
>>> ys = [4, 5, 6]
>>> zs = xs + ys
>>> zs
[1, 2, 3, 4, 5, 6]
>>> xs * 4
[1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3]
>>> 4 in xs
False
>>> 4 in ys
True
>>> 4 not in xs
True
>>> xs == ys
False
```

### Llistes per comprensió

```pycon
>>> [i for i in range(10)]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> [i * 2 for i in range(10)]
[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
>>> [i * 2 for i in range(10) if i % 3 == 0]
[0, 6, 12, 18]
>>> [0 for _ in range(10)]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

## Nombre d'elements iguals al darrer

```python
from yogi import *

# desar tota la seqüència en una llista
L = []
for x in tokens(int):
    L.append(x)

# comptar aparicions del darrer element
n = 0
for x in L:
    if x == L[-1]:
        n += 1
print(n)
```

Amb funcions:

```python
from yogi import *

def llegir_llista() -> list[int]:
    L = []
    for x in tokens(int):
        L.append(x)
    return L

def ocurrencies(L: list[int], elem: int) -> int:
    n = 0
    for x in L:
        if x == elem:
            n += 1
    return n

L = llegir_llista()
print(ocurrencies(L, L[-1]))
```

## Producte escalar i mòdul

```python
def producte_escalar(x: list[float], y: list: [float]) -> float:
    assert len(x) == len(y)
    s = 0.0
    for i in range(len(x)):
        s += x[i] * y[i]
    return s

def modul(x: list[float]) -> float:
    return math.sqrt(producte_escalar(x, x))

v1 = [1.1, 2.2, 3.3]
v2 = [0, 4.2, -2.1]
print(producte_escalar(v1, v2))
print(modul(v1))
```

## Algorisme d'Erastotenes 

Trobar tots els primers fins a un nombre donat.


```python
def eratostenes(n: int) -> list[bool]:
    """Retorna un vector g de n+1 booleans tal que g[i] indica si i és o no és primer. Prec: n >= 2."""
    assert n >= 2
    g = [True] * n
    g[0], g[1] = False, False
    i = 2
    while i * i <= n:
        if g[i]:
            for j in range(2*i, n+1, i):
                g[j] = False
        i += 1
    return g

def primers(n: int) -> list[int]:
    """retorna un vector amb tots els nombres primers <= n amb n >= 2."""

    g = eratostenes(n)
    ps: list[int] = []
    for i in range(2, n+1):
        if g[i]:
            ps.append(i)
    return ps

print(primers(read(int)))
```


## Cercar subtext en un text

Els `str`s són semblants a les llistes. Però són inmutables.

```python
def conte_a(text: str, subtext: str, p: int) -> bool:
    """diu si text conté subtext a la posició p"""
    for i in range(len(subtext)):
        if subtext[i] != text[p + i]:
            return False
    return True

def conte(text: str, subtext: str) -> bool:
    """diu si text conté subtext"""
    n = len(text)
    m = len(subtext)
    for p in range(n - m + 1):
        if conte_a(text, subtext, p):
            return True
    return False
```


## Segment nul més llarg

Un segment nul d'una llista és una subllista tal que la suma dels seus elements és 0.

Donat un vector ordenat creixentment, volem trobar els seu segment nul més gran.

```python
def largest_null_segment (L: list[int]) -> tuple[int, int]:
    """ Pre: L is sorted in increasing order. Post: <left,right> contain the indices of the largest null segment. In the case of an empty null segment, left > right.
    """

    left, right = 0, len(L) - 1
    s = sum(L)
    while s != 0:
        if s > 0:
            s = s – L[right]
            right = right – 1
        else:
            s = s – L[left]
            left = left + 1
    return left, right
```


## Llistes com a paràmetres

```python
def f1(x: int):
    x = 44

a = 3
f1(a)
print(a)        # escriu 3
```

```python
def f2(L: list[int]):
    L = [4, 5, 6]

b = [1, 2, 3]
f2(b)
print(b)        # escriu [1, 2, 3]
```

Però...

```python
def f2(L: list[int]):
    L.append(4)

b = [1, 2, 3]
f2(b)
print(b)        # escriu [1, 2, 3, 4]
```




## Split

El mètode `split` dels textos és molt útil: trenca el text en una llista de textos utilitzant un separador (per paraules per defecte):

```pycon
>>> 'es quan dormo que hi veig clar'.split()
['es', 'quan', 'dormo', 'que', 'hi', 'veig', 'clar']
>>> '   es   quan    dormo que hi veig   clar '.split()
['es', 'quan', 'dormo', 'que', 'hi', 'veig', 'clar']
>>> '30/11/1971'.split('/')
['30', '11', '1971']
```


## Cerca lineal

```python
def posicio(v: list[int], x: int) -> Optional[int]:
    for i in range(len(v)):
        if v[i] == x:
            return i 
    return None
```


## Cerca binària

```python
def posicio(v: list[int], x: int) -> Optional[int]:
    assert ordenat(v)
    return posicio_rev(v, x, 0, len(v) - 1)

def posicio_rec(v: list[int], x: int, esq: int, dre: int) -> Optional[int]:
    if esq > dre:
        return None
    else:
        mig = (dre + esq) // 2
        if x < v[mig]:
            return posicio_rec(v, x, esq, mig - 1)
        elif x > v[mig]:
            return posicio_rec(v, x, mig + 1, dre)
        else:
            return mig

def posicio_ite(v: list[int], x: int, esq: int, dre: int) -> Optional[int]:
    while esq <= dre:
        mig = (dre + esq) // 2
        if x < v[mig]:
            dre = mig - 1
        elif x > v[mig]:
            esq = mig + 1
        else:
            return mig
    return None

def ordenat(v: list[int]) -> bool:
    for i in range(len(v) - 1):
        if v[i] > v[i + 1]:
            return False
    return True
```


## Ordenació per selecció

...

## Ordenació per inserció

...


## Fusió de llistes ordenades

...

## Ordenació per fusió

...



## `sorted` i `sort`

Donada una llista `L`, `sorted(L)` retorna la llista ordenada de petit a gran. `L.sort()` ordena la llista:

```pycon
>>> L = [6, -2, 4, -3, 2, 4, 6, 9, 1]
>>> sorted(L)
[-3, -2, 1, 2, 4, 4, 6, 6, 9]
>>> L.sort()
>>> L
[-3, -2, 1, 2, 4, 4, 6, 6, 9]
```

Amb el paràmetre `reverse` es pot indicar que es vol de gran a petit:

```pycon
>>> L = [6, -2, 4, -3, 2, 4, 6, 9, 1]
>>> sorted(L, reverse=True)
[9, 6, 6, 4, 4, 2, 1, -2, -3]
```

Amb el paràmetre `key` es pot indicar quina funció aplicar a cada element per obtenir-ne el seu ordre.

```pycon
>>> L = [6, -2, 4, -3, 2, 4, 6, 9, 1]
>>> sorted(L, key=abs)
[1, -2, 2, -3, 4, 4, 6, 6, 9]
```

```pycon
>>> L = 'La Rosa porta la rosa'.split()
>>> L
['La', 'Rosa', 'porta', 'la', 'rosa']
>>> sorted(L)
['La', 'Rosa', 'la', 'porta', 'rosa']
>>> sorted(L, key=str.lower)
['La', 'la', 'porta', 'Rosa', 'rosa']
```

```
>>> sorted('Àgata Abel Èric Enric'.split())
['Abel', 'Enric', 'Àgata', 'Èric']
>>> sorted('Àgata Abel Èric Enric'.split(), key=locale.strxfrm)
['Abel', 'Enric', 'Àgata', 'Èric']
```

`locale.strxfrm`: Transforms a string to one that can be used in locale-aware comparisons. 

