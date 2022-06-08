
# 05 · Seqüències

# Recorreguts

## Mitjana d'una seqüència de reals

### Amb longitud al principi

```python
n = read(int)
s = 0.0
for _ in range(n):
    x = read(float)
    s += x
print(s / n)
```

### Amb finalitzador (negatiu) al final

```python
s = 0.0
n = 0
x = read(float)
while x >= 0:
    s += x
    n = n + 1
    x = read(float)
print(s / n)
```

### Fins que s'acabin   

```python
s = 0.0
n = 0
x = scan(float)     # yogi!
while x is not None:
    s += x
    n = n + 1
    x = scan(float)
print(s / n)
```

Explicar <kbd>control</kbd><kbd>D</kbd>.


## Màxim d'una seqüència no buida de reals

### Amb longitud al principi

```python
n = read(int)
m = read(float)
for _ in range(n - 1):
    x = read(float)
    m = max(m, x)
print(m)
```

### Amb finalitzador (negatiu) al final

```python
m = read(float)
x = read(float)
while x >= 0:
    m = max(m, x)
    x = read(float)
print(m)
```

### Fins que s'acabin   

```python
m = read(float)    
x = scan(float)    
while x is not None:
    m = max(m, x)
    x = scan(float)
print(m)
```

## Comptar quantes paraules "casa" hi ha en un fitxer de text

```python
c = 0
x = scan(str)    
while x is not None:
    if x == 'casa':
        c = c + 1
    x = scan(str)
print(c)
```

# Cerques

## Trobar si hi ha la paraula "casa" en un fitxer de text

Correcte però lent:

```python
c = 0
x = scan(str)    
while x is not None:
    if x == 'casa':
        c = c + 1
    x = scan(str)
print(c > 0)
```

Parar de llegir quan es troba la primera "casa":

```python
trobat = False
x = scan(str)    
while not trobat and x is not None:
    if x == 'casa':
        trobat = True
    else:
        x = scan(str)
print(trobat)
```

Amb un funció ja ni cal el booleà:

```python
def conté(paraula: str) -> Bool:
    """indica si l'entrada conté paraula"""
    x = scan(str)    
    while x is not None:
        if x == 'casa':
            return True
    return False
```

## Recorreguts i cerques

# Finestres

### Comptar nombre de paraules consecutides repetides

```python
r = 0
a = scan(str)
if a is not None:
    b = scan(str)
    while b is not None:
        if a == b:
            r = r + 1
        a, b = b, scan(str)
print(r)
```


### Comptar nombre de pics

(Suposem que hi ha almenys dos elements.)

```python
p = 0
a, b, c = read(float), read(float), scan(float)
while c is not None:
    if a < b > c:
        p = p + 1
    a, b, c = b, c, scan(float)
print(p)
```

# Altres exemples

### Longest repeated subsequence

We want to calculate the length of the longest
sequence of repetitions of the first string.

```python
first = read(str)
length = 1  # Length of the current subsequence
longest = 1 # Length of the longest subsequence
current = scan(str)
while current is not None:
    if first != current:
        length = 0
    else:
        length = length + 1
        longest = max(longest, length)
    current = scan(str)
print(longest)
```