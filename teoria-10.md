
# 10a · Conjunts

Els conjunts de Python permeten enmagatzemar conjunts finits d'elements. L'ordre i les repeticions no importen.

## Exemple

```pycon
>>> a = {'Anna', 'Berta', 'Carla'}
>>> a
{'Carla', 'Berta', 'Anna'}
>>> type(a)
<class 'set'>
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

## Operacions bàsiques

- `s = {x1, x2, ...}`: crea un conjunt amb elements `x1`, `x2`, ...

- `s = set(L)`: crea un conjunt amb els elements de la llista `L`.

- `len(s)`: retorna el cardinal del conjunt `s`. 

- `s.add(x)`:  afegir l'element `x` al conjunt `s`.

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
s: set[int] = set()
w = scan(str)
while w is not None:
    s.add(w)
    w = scan(str)
for w in sorted(s):
    print(w)
```



# 10b · Diccionaris


Els conjunts de Python permeten enmagatzemar valors associats a claus de forma eficient.


## Exemple

```pycon
>>> d = {'gat': 'cat', 'gos': 'dog', 'tortuga': 'turtle'}
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
for w in sorted(d.keys()):
    print(w, d[w])
```