# Ús del terminal

## Recordatori

Ens podem moure a través del terminal amb `cd` (change directory) i veure quins arxius i carpetes tenim amb `ls`.

```sh
cd <nom_directori>
ls
```

Per executar un arxiu de python amb nom `hello_world.py` podem escriure: (des del directori on tenim l'arxiu)

```sh
python hello_world.py
```

>
> Nota: Quan executem des de VS Code ens escriu automàticament una comanda equivalent, però diferent.
>

Per comprovar els tipus en un programa amb el mypy farem:

```sh
mypy hello_world.py
python -m mypy hello_world.py
```

## Redireccions

Per dirigir l'input o l'output d'un programa o d'un arxiu podem utilitzar els operadors `>`, `<`, `>>` i `<<`.

```sh
# donar l'entrada a un programa a partir d'un fitxer
python nombres_primers.py < input.txt

# redirigir la sortida d'un programa a un fitxer
python hello_world.py > output.txt

# donar l'entrada i redirigir la sortida 
python nombres_primers.py < input.txt > output.txt
```

* Quan posem un sol símbol ('>') el fitxer de destí es sobreescriurà si ja existeix.
* Quan posem dos símbols ('>>') afegirem la sortida al final del fitxer de destí.

## Comparar fitxers

Si volem comprovar si dos fitxers són iguals podem utilitzar les comandes `diff` o `cmp`. Imagineu que volem comparar el text entre `arxiu1.txt` i `arxiu2.txt`, fariem:

```sh
diff arxiu1.txt arxiu2.txt
cmp arxiu1.txt arxiu2.txt
```

## Com ens pot ajudar

Imagina que tenim un programa que llegeix una seqüència de nombres i en retorna una de nova. Si fos un problema del jutge, per comprovar que funciona faríem unes proves abans. Per no perdre el temps (i equivocar-nos segurament) podem utilitzar aquestes eines.

1. Posem l'entrada en un fitxer input.txt
2. Posem la sortida esperada en un fitxer output.txt
3. Executem al el nostre programa, amb l'entrada que tenim, tot guardant la sortida a test.txt

```sh
python programa.py < input.txt > test.txt
```

4. Comparem la nostra sortida amb la sortida esperada:

```sh
diff output.txt test.txt
```
