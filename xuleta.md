# Xuleta de Python d'AP1

## Escriptura amb `print`

Els paràmetres donats es separen amb el paràmetre `sep` (un espai de per defecte) i al final s'afageix el paràmetre `end` (un salt de línia per defecte).

```python
print(10, 'XY', 30, sep=';', end='.')
```

escriu `10;XY;30.` (sense salt de línia).

## Lectura amb `yogi`

- `read()`: retorna l'element següent de l'entrada (error si no hi és).
- `scan()`: retorna l'element següent de l'entrada o `None` si no hi és.
- `tokens()`: en un bucle `for`, retorna l'element següent de l'entrada o para el bucle quan n'ho n'hi ha més.

```python 
from yogi import read

a = read(int)
b = read(int)
print(a + b)
```

```python 
from yogi import scan

s = 0
x = scan(int)
while x is not None:
    s += x
    x = scan(int)
print(s)
```

```python 
from yogi import tokens

s = 0
for x in tokens():
    s += x
print(s)
```

Els tipus llegibles són `int`, `float` i `str`.

Per acabar l'entrada al terminal cal picar <kbd>Control</kbd> + <kbd>D</kbd> en Linux o Mac OS i <kbd>Control</kbd> + <kbd>Z</kbd> en Windows.

## Format de textos amb `f-strings`

```pycon
>>> nom, cognom = 'James', 'Bond'
>>> f'Em dic {cognom}, {nom} {cognom}.'
'Em dic Bond, James Bond.'
```

```pycon
>>> x = 123.419
>>> f'{x:.2f}'  # dos dígits darrera la coma decimal
'123.42'
>>> f'{x:08.2f}' # dos dígits darrera la coma decimal, 8 caràcters en total, zeros a l'esquerra
'00123.42'
>>> f'{x: 8.2f}' # dos dígits darrera la coma decimal, 8 caràcters en total, espais a l'esquerra
'  123.42'
>>>
```


```pycon
>>> s = 'Python'
>>> f'{s:>20}'
'              Python'
>>> f'{s:<20}'
'Python              '
>>> f'{s:^20}'
'       Python       '
>>> f'{s:#>20}'
'##############Python'
```

```pycon
>>> n = 123
>>> f'{n:>20}'
'                 123'
>>> f'{n:<20}'
'123                 '
>>> f'{n:0>20}'
'00000000000000000123'
```

## Operadors 

|operador|significat|
|----|----|
| `+` | suma, concatenació |
| `-` | resta, canvi de signe |
| `*` | producte |
| `/` | divisió real |
| `**` | potència |
| `//` | divisió entera |
| `#` | rest de la divisió entera (mòdul) |
| `==` | igual |
| `!=` | diferent |
| `<` | menor estricte |
| `>` | major estricte |
| `<=` | menor o igual |
| `>=` | major o igual |
| `is` | equivalència d'objectes |
| `and` | conjunció lògica |
| `or` | disjunció lògica |
| `not` | negació lògica |
| `in` | dins de llista/text/conjunt/diccionari |
| `not in` | negació del `in` |

## range

```pycon
>>> list(range(10))
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> list(range(5, 10))
[5, 6, 7, 8, 9]
>>> list(range(5, 10, 2))
[5, 7, 9]
````

## Funcions

Definició de funcions:

```python 
def màxim(a: int, b: int) -> int:
    """Retorna el màxim de dos enters."""
    ...
```

Crida de funcions:

```pycon
màxim(màxim(x, y), z)
```

Funcions predefinides:

|funció|exemples|
|---|---|
|`abs`| `abs(-12)`|
|`round`| `round(123.987, 2)`|
|`max`| `max(12, 21)`, `max([1, 4, 2])`|
|`min`| `min(12, 21)`, `min([1, 4, 2])`|
|`len`|`len([1, 4, 2])`|
|`sum`|`sum([1, 4, 2])`|
|`all`|`all([True, True, True])`|
|`any`|`any([True, True, True])`|

...

reversed
sorted


## Conversions

```pycon
>>> int(3.9)
3
>>> int(3.1)
3
>>> float(21)
21.0
>>> str(123)
'123'
>>> int('123')
123
>>> float('123')
123.0
```

## Llistes


```pycon
>>> llista = [50, 24, 50, 12]
>>> llista
[50, 24, 50, 12]
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
