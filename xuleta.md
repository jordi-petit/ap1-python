# Xuleta de Python d'AP1

## Escriptura

S'escriu amb `print()`. Els paràmetres donats es separen amb el paràmetre `sep` (un espai de per defecte) i al final s'afageix el paràmetre `end` (un salt de línia per defecte).

```python
print(10, 20, 30, sep=';', end='.')
```

escriu `10;20;30.` (sense salt de línia).

## Lectura

S'usen aquestes funcions del mòdul `yogi`:

- `read()`: retorna el següent element de l'entrada (error si no hi és).
- `scan()`: retorna el següent element de l'entrada o `None` si no hi és.
- `tokens()`: en un bucle `for`, retorna el següent element de l'entrada o para el bucle quan n'ho n'hi ha més.

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

Per acabar l'entrada al terminal cal picar <kbd>Control</kbd> + <kbd>D</kbd> en Linux o Mac OS i <kbd>Control</kbd> + <kbd>Z</kbd> en Windows.

## Format de textos

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