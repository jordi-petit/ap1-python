
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
    C: Matriu = [[0] * n] * m
    for i in range(n):
        for j in range(m):
            C[i][j] = A[i][j] + B[i][j]
    return C
```

Els bucles es poden fer al revés.


## Matriu simètrica?

```python
def es_simetrica(M: Matriu) -> bool:
    n = len(A)
    for i in range(n):
        for j in range(i + 1, n):
            if M[i][j] != M[j][i]:
                return False
    return True
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

## Producte de matrius quadrades

```python
def producte(A: Matriu, B: Matriu) -> Matriu:
    n = len(A)
    C: Matriu = [[0] * n] * m
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C
```


## Cerca en una matriu ordenada

Una matriu ordenada és una matriu on cada fila i cada columna està ordenada creixentment.

...


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
    sou: float
    departament: str
    data_naixament: Optional[Data] = None

@dataclass
class Empresa:
    nom: str 
    empleats: list[Empleat]
```

```pycon
>>> e1 = Empleat(nom='Anna', sou=2300, departament='Direcció', data_naixament=Data(12, 11, 1999))
>>> e2 = Empleat(nom='Berta', sou=1900, departament='Comptabilitat')
>>> empresa = Empresa(nom='Betes i fils, SA', empleats=[e1, e2])
>>> for empleat in empresa.empleats: print(empleat.sou)
...
2300
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

No he trobat cap manera _senzilla_ de clonar.
