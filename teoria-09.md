
# 09a · Matrius

Les matrius són llistes de llistes.

## Exemple: matriu 3 ⨉ 4:

```pycon
M = [
        [2, 4, 1, 6],
        [1, 3, 4, 1],
        [2, 9, 9, -2],
]
```

Defininió de nous tipus:

```python
from typing import TypeAlias

Fila: TypeAlias = list[float]
Matriu: TypeAlias = list[Fila]
```

## Suma de matrius

```python
def suma(A: Matriu, B: Matriu) -> Matriu:
    n, m = len(A), len(A[0])
    C: Matriu = [[0 for j in range(n)] for i in range(n)] 
    for i in range(n):
        for j in range(m):
            C[i][j] = A[i][j] + B[i][j]
    return C
```

Amb llistes per comprensió:

```python
def suma(A: Matriu, B: Matriu) -> Matriu:
    n, m = len(A), len(A[0])
    return [[A[i][j] + B[i][j] for j in range(m)] for i in range(n)]
```

(no sembla més llegible...)

## Matriu simètrica?

```python
def es_simetrica(M: Matriu) -> bool:
    n = len(M)
    for i in range(n):
        for j in range(i + 1, n):
            if M[i][j] != M[j][i]:
                return False
    return True
```

Amb `all`: ???

```python
def es_simetrica(M: Matriu) -> bool:
    n = len(M)
    return all(M[i][j] == M[j][i] for i in range(n) for j in range(i + 1, n))
```


## Transposta

```python
def transposa(M: Matriu) -> None:
    """acció que transposa la matriu quadrada M"""
    n = len(A)
    for i in range(n):
        for j in range(i + 1, n):
            M[i][j], M[j][i] = M[j][i], M[i][j]
```

Exercici: fer-ho amb llistes per comprensió.


## Producte de matrius quadrades

```python
def producte(A: Matriu, B: Matriu) -> Matriu:
    n = len(A)
    C: Matriu = [[0 for j in range(n)] for i in range(n)] 
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C
```


```python
def producte(A: Matriu, B: Matriu) -> Matriu:
    n = len(A)
    return [
        [
            sum(A[i][k] * B[k][j] for k in range(n)) 
            for j in range(n) 
        ] 
        for i in range(n)
    ]
```



## Cerca en una matriu ordenada

Una matriu ordenada és una matriu on cada fila i cada columna està ordenada creixentment.

...


## Perills

Explicar què passa per sota. Ex:

```python 
[[0] * m] * n] ❌
[[0 for j in range(m)] for i in range(n)] ✅
```


# 09b · Estructures

Usarem *dataclasses*.

## Productes d'una botiga

```python
from dataclasses import dataclass

@dataclass
class Producte:
    """Estructura per desar informació dels productes de la nostra botiga."""
    nom: str
    preu: float
    estoc: int = 0
```

```pycon
>>> prod = Producte('Sabó', 2.33, 50)
>>> prod
Producte(nom='Sabó', preu=2.33, estoc=50)
>>> type(prod)
<class '__main__.Producte'>
>>> prod.preu
2.33
>>> prod.preu *= 2
>>> prod
Producte(nom='Sabó', preu=4.66, estoc=50)
>>> prod.estoc -= 1
>>> prod
Producte(nom='Sabó', preu=4.66, estoc=49)
```



## Empleats d'una empresa

```python
@dataclass
class Data:
    dia: int
    mes: int
    any: int

@dataclass
class Empleat:
    nom: str
    sou: float = 1500
    departament: str
    data_naixament: Optional[Data] = None

@dataclass
class Empresa:
    nom: str 
    empleats: list[Empleat]
```

```pycon
>>> e1 = Empleat(nom='Anna', departament='Direcció', data_naixament=Data(12, 11, 1999))
>>> e2 = Empleat(nom='Berta', sou=1900, departament='Comptabilitat')
>>> empresa = Empresa(nom='Betes i fils, SA', empleats=[e1, e2])
>>> for empleat in empresa.empleats: print(empleat.sou)
...
1500
1900
```

## Hores

```python
@dataclass
class Hora:
    hores: int
    minuts: int
    segons: int

def escriure_hora(h: Hora) -> None:
    print(f'{h.hores:02d}:{h.minuts:02d}:{h.segons:02d}')

def sumar_un_segon(h: Hora) -> None:
    h.segons += 1
    if h.segons == 60:
        h.segons = 0
        h.minuts += 1
        if h.minuts == 60:
            h.minuts = 0
            h.hores += 1
            if h.hores == 24:
                h.hores = 0
```

```pycon
>>> hora = Hora(11, 5, 59)
>>> escriure_hora(hora)
11:05:59
>>> sumar_un_segon(hora)
>>> escriure_hora(hora)
11:06:00
```

## Perills

```pycon
>>> h = Hora(10,10,10)
>>> h
Hora(hores=10, minuts=10, segons=10)
>>> h2 = h
>>> h
Hora(hores=10, minuts=10, segons=10)
>>> sumar_un_segon(h)
>>> h
Hora(hores=10, minuts=10, segons=11)
>>> h2
Hora(hores=10, minuts=10, segons=11)
```


## Ordenació amb `key`

```python
@dataclass
class Hora:
    hores: int
    minuts: int
    segons: int

def nombre_de_segons(h: Hora):
    return h.segons + h.minuts * 60 + h.hores * 60 * 60
```


```pycon
>>> L = [Hora(15,30,0), Hora(14,49,59), Hora(15,30,0), Hora(9,0,0)]
>>> sorted(L)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: '<' not supported between instances of 'Hora' and 'Hora'
>>> sorted(L, key=nombre_de_segons)
[Hora(hores=9, minuts=0, segons=0), Hora(hores=14, minuts=49, segons=59), Hora(hores=15, minuts=30, segons=0), Hora(hores=15, minuts=30, segons=0)]
```



## Ordenació amb `cmp_to_key`

P33147: Donada una llista de rectangles, cadascun definit amb la seva amplada i la seva alçada, ordener-la de la manera següent: Com a primer criteri, de petit a gran en funció de l’àrea. En cas d’empat, de gran a petit en funció del perímetre. En cas d’un altre empat, primer el rectangle amb menys amplada.

```python
from dataclasses import dataclass
from functools import cmp_to_key


@dataclass
class Rectangle:
    amplada: int
    alçada: int

# La funció de comparació, donats dos rectangles ha de retornar:
#   - un valor negatiu si el primer és inferior al segon
#   - zero si el primer és igual al segon
#   - un valor positiu si el primer és superior al segon


def comp(r1: Rectangle, r2: Rectangle) -> int:
    a1 = r1.amplada * r1.alçada
    a2 = r2.amplada * r2.alçada
    if a1 != a2:
        return a1 - a2

    p1 = r1.amplada + r1.alçada
    p2 = r2.amplada + r2.alçada
    if p1 != p2:
        return p2 - p1

    return r1.amplada - r2.amplada


L = [
    Rectangle(20, 1),
    Rectangle(2, 4),
    Rectangle(6, 6),
    Rectangle(4, 9),
    Rectangle(20, 1),
    Rectangle(9, 4),
]

print(sorted(L, key=cmp_to_key(comp)))
```
