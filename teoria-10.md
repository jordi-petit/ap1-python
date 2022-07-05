
# 10a · Conjunts

Els conjunts de Python permeten enmagatzemar conjunts finits d'elements. L'ordre i les repeticions no importen.

## Exemple

```pycon
>>> a: set[str] = {'Anna', 'Berta', 'Carla'}
>>> a
{'Carla', 'Berta', 'Anna'}
>>> len(a)
3
>>> 'Berta' in s
True
>>> 'Zoe' in s
False
>>> for x in a: print(x)
Carla
Berta
Anna
>>> a.add('Dafne')
>>> a
{'Carla', 'Berta', 'Dafne', 'Anna'}
>>> b = set('Maria Mireia Miriam'.split())
>>> c = set('Anna Carles Berta'.split())
>>> (a | b) & c
{'Berta', 'Anna'}
```

## Declaració de tipus

```python
s1: set[int]
s2: set[str]
s3: set[set[str]]
```

## Operacions bàsiques

- `{x1, x2, ...}`: crea un conjunt amb elements `x1`, `x2`, ... Si es vol el conjunt buit cal fer `set()` perquè `{}` és el diccionari buit.

- `set(L)`: crea un conjunt amb els elements de la llista `L`.

- `len(s)`: retorna el cardinal del conjunt `s`. 

- `s.add(x)`:  afegeix l'element `x` al conjunt `s`.

- `s.erase(x)`:  esborra l'element `x` del conjunt `s` (s'enfada si no hi és).

- `s.discard(x)`:  esborra l'element `x` del conjunt `s` (no s'enfada si no hi és).

- `s.pop()`:  elimina i retorna un element arbitrari de `s` (`s` no pot ser buit).

- `x in s` o `x not in s`:  diu si `x` és o no en `s`.

- `for x in s: ...`: itera sobre tots els elements del conjunt (en un ordre arbitrari). Mentre s'itera sobre un conjunt no es poden afegir/treure-li elements.

- `a | b`: retorna l'unió dels conjunts.

- `a & b`: retorna la intersecció dels conjunts.

- `a <= b`: indica si `a` és subconjunt de `b`.

- `a < b`: indica si `a` és subconjunt estricte de `b`.

- `list(s)`: retorna una llista amb els elements de `s` en ordre arbitrari.

- `sorted(s)`: retorna una llista amb els elements de `s` en ordre creixent.



## Trobar totes les paraules úniques d'un fitxer

```python
s: set[str] = set()
w = scan(str)
while w is not None:
    s.add(w)
    w = scan(str)
for w in sorted(s):
    print(w)
```


## Conjunts per comprensió

```pycon
>>> {2**n for n in range(9)}
{32, 1, 2, 64, 4, 128, 256, 8, 16}
>>> {str(i) for i in {2,3,4,5,6} if i % 2 == 0}
{'4', '6', '2'}
>>> n = 20
>>> {(a, b, c) for a in range(1, n + 1) for b in range(a, n + 1) for c in range(b, n + 1) if a**2 + b**2 == c**2}
{(6, 8, 10), (3, 4, 5), (8, 15, 17), (9, 12, 15), (5, 12, 13), (12, 16, 20)}
```



# 10b · Diccionaris


Els diccionaris de Python permeten enmagatzemar valors associats a claus.


## Exemple

```pycon
>>> d: dict[str, str] = {'gat': 'cat', 'gos': 'dog', 'tortuga': 'turtle'}
>>> d
{'gat': 'cat', 'gos': 'dog', 'tortuga': 'turtle'}
>>> len(d)
3
>>> 'gos' in d
True
>>> 'llop' in d
False
>>> 'dog' in d
False
>>> d['gos']
'dog'
>>> d['gos'] = 'hound'
>>> d
{'gat': 'cat', 'gos': 'hound', 'tortuga': 'turtle'}
>>> d['llop'] = 'wolf'
>>> d
{'gat': 'cat', 'gos': 'hound', 'tortuga': 'turtle', 'llop': 'wolf'}
>>> d['guineu']
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 'guineu'
>>> list(d.keys())
['gat', 'gos', 'tortuga', 'llop']
>>> list(d.values())
['cat', 'hound', 'turtle', 'wolf']
>>> list(d.items())
[('gat', 'cat'), ('gos', 'hound'), ('tortuga', 'turtle'), ('llop', 'wolf')]
>>> for k in d: print(k, d[k])
gat cat
gos hound
tortuga turtle
llop wolf
>>> for k,v in d.items(): print(k, v)
gat cat
gos hound
tortuga turtle
llop wolf
```


## Comptar totes les paraules úniques d'un fitxer

```python
d: dict[str, int] = {}
w = scan(str)
while w is not None:
    if w not in d:
        d[w] = 1
    else:
        d[w] += 1
    w = scan(str)
for w in sorted(d):
    print(w, d[w])
```


```python
d: dict[str, int] = {}
w = scan(str)
while w is not None:
    d[w] =  d.get(w, 0) + 1   # valor per quan clau no hi és
    w = scan(str)
for w in sorted(d.keys()):
    print(w, d[w])
```



## Diccionaris per comprensió

```pycon
>>>  {n: n*n for n in range(1, 6)}
{1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
>>> {n: n*n for n in range(1, 6) if n*n % 2 == 0}
{2: 4, 4: 16}
>>> d = {1: 2, 2: 3, 3: 4}
>>> {v:k for k,v in d.items()}
{2: 1, 3: 2, 4: 3}
```

## Collatz

https://projecteuler.net/problem=14

```python
import yogi  # sinó, ens quedarem sense espai per la pila


def next(n: int) -> int:
    if n % 2 == 0:
        return n // 2  
    else:
        return 3 * n + 1

def update_lengths(lengths: dict[int, int], n: int) -> None:
    if n not in lengths:
        nxt = next(n)
        update_lengths(lengths, nxt)
        lengths[n] = 1 + lengths[nxt]

def solve(M: int) -> int:
    lengths = {1: 1}
    m = 1
    for i in range(2, M + 1):
        update_lengths(lengths, i)
        if lengths[i] > lengths[m]:
            m = i
    return m


print(solve(1000000))  # hauria d'escriure 837799
```

## Eficiència

Potser caldria trobar alguna manera de reflectir l'eficiència de diccionaris i conjunts.

⏰ Per exemple:

```python
import time

n = 10000000

L = [i for i in range(n)]
S = set(L)

t1 = time.time()
for x in L:
    if x == n:
        break
t2 = time.time()
print(t2 - t1)

t1 = time.time()
n in L
t2 = time.time()
print(t2 - t1)

t1 = time.time()
n in S
t2 = time.time()
print(t2 - t1)
```

Al meu ordinador dóna:

|temps|
|---|
|0.5582611560821533|
|0.1228291988372802|
|0.0000021457672111|


