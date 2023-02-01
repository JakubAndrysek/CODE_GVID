###
## Seznam
###

## Návod: Pomocí debuggeru (např. programem Thonny) projdi jednotlivé řádky,
##        přečti si komentáře okolo a podívej se na výsledky.

cekat = True

import sys

def cekej(mamCekat):
    """
    Pokud je parametr mamCekat roven True, počká na stisk klávesy Enter, jinak
    nic nedělá a pokračuje ve vykonávání skriptu.
    Pokud uživatel stiskne q nebo Q, provede ukončení skriptu.
    """
    if mamCekat:
        if input("\n\n\nPro pokračování stiskni Enter, pro konec Q.\n") in ("q", "Q"):
            sys.exit("Skript ukončen na přání uživatele.")


print("**************")
print("*** Seznam ***")
print("**************")
## Seznam je proměnná tvořená posloupností hodnot s jasně daným pořadím.
## Seznam se tvoří pomocí hranatých závorek.
## Seznam v Pythonu nahrazuje pole (pro skutečná pole je třeba použít numpy).
## Prvky seznamu mohou být libovolné hodnoty, včetně jiných seznamů.
## Seznamy jsou na rozdíl od n-tic proměnlivé (mutable), prvky i seznam samotný
## je tedy možné měnit.





print("\n\n\n** Vytváření seznamů **")
## Seznamy jsou objekty vyráběné jedním ze dvou konstruktorů: [] a list().
s1 = []
s2 = list()
print("s1 = []:", s1)
print("s2 = list():", s2)

## Do konstruktoru [] jde dosadit přímo prvky seznamu. 
s1 = ["Jedna", "dvě", "Surio", "Mario", "Martinez", "Juarez", "jde"]
print("s1 = ['Jedna', 'dvě', ...]:", s1)

## Do konstruktoru list() jde dosadit jiný iterovatelný objekt jako n-tici,
## jiný seznam, slovník, iterátor.
s2 = list(s1)
print("s2 = list(s1):", s2)



cekej(cekat)



print("\n\n\n** Proměnná je odkaz na skutečný seznam **")
## Proměnná seznam je vlastně jen odkazem na skutečný seznam uložený v paměti.
seznam = [1, "ahoj", print, ["vnořený", "seznam"]]

## Proměnná x nyní neobsahuje kopii, ale odkazuje na původní seznam.
x = seznam

## Proměnná y je fyzickou kopií původního seznamu
y = seznam.copy()

print("Proměnná seznam odkazuje na seznam:", seznam)
print("Proměnná x odkazuje na seznam:", x)
print("Proměnná y odkazuje na seznam:", y)



cekej(cekat)



print("\n\n\n** Porovnávání seznamů **")
## Seznamy odkazované proměnnými x a seznam obsahují prvky se stejnými hodnotami.
if x == seznam:
    print("x == seznam")

## Proměnné x a seznam odkazují na totožný objekt v paměti.
if x is seznam:
    print("x is seznam")

## V proměnné y je kopie seznamu, proto mají stejné prvky.
if y == seznam:
    print("y == seznam")
    
## Proměnná y odkazuje na jiný objekt než seznam.
if y is not seznam:
    print("y is not seznam")



cekej(cekat)



print("\n\n\n** list.copy() dělá mělkou kopii **")
## Operace copy dělá mělkou kopii! To znamená, že vnořený seznam zůstane sdílený.
## Tohle změní prvek jenom v původním seznamu
seznam[1] = "AHOJ"
## Vnitřní seznam je sdílený, takže se změna projeví i v proměnné y!
seznam[3][0] = "VNOŘENÝ"
print("seznam =", seznam)
print("x =", x)
print("y =", y)



cekej(cekat)



print("\n\n\n** Operace append **")
## Prázdný seznam je buď [] nebo použitím konstruktoru list()
s = list()
print("list():", s)

## Operace append přidává prvek na konec seznamu.
s.append("ahoj")
print("append('ahoj'):", s)



cekej(cekat)



print("\n\n\n** N-tice -> seznam **")
## Do seznamu jde vkládat i prvky jiných struktur, třeba n-tic.
ntice = (1, 2, 3)

## Vyrobí nový seznam a nakopíruje tam prvky z n-tice.
s = list(ntice)

## Přidá n-tici jako další prvek seznamu.
s.append(ntice)

## Přidá na konec seznamu prvky z n-tice
s.extend(ntice)
print("list(ntice)+append(ntice)+extend(ntice):", s)



cekej(cekat)



print("\n\n\n** Operace insert **")

## Vloží nový prvek do seznamu na index 2
s.insert(2, "vloženo")
print("insert(2,'vloženo'):", s)

## Neplést s úpravou prvku na stejné pozici
s[2] = "jiný prvek"
print("s[2] = 'jiný prvek':", s)



cekej(cekat)



print("\n\n\n** Operace pop, remove **")

print("s:", s)

## Odstraní prvek z poslední pozice a vrátí jeho hodnotu.
prvek = s.pop()
print("prvek = s.pop()")
print("prvek:", prvek)
print("s:", s)

## Odstraní prvek ze zadané pozice a vrátí jeho hodnotu.
prvek = s.pop(2)
print("prvek = s.pop(2)")
print("prvek:", prvek)
print("s:", s)

## Najde a odstraní první výskyt hodnoty zadaného prvku.
s.remove(2)
print("s.remove(2):", s)

## Operace remove vyhazuje výjimku ValueError, když hledaný prvek není v seznamu.
try:
    s.remove(5)
except ValueError:
    print("s.remove(5): Odchycena výjimka ValueError. Hodnota 5 se v seznamu nenachází.")



cekej(cekat)



print("\n\n\n** Hledání prvků v seznamu: in a index **")
## Pomocí operátoru in jde otestovat, zda je prvek v seznamu.
prvek = 1
if prvek in s:
    ## Operace index vrátí index prvního výskytu prvku
    i = s.index(prvek)
    print(f"První výskyt prvku {prvek} se v seznamu {s} nachází na indexu {i}.")

## Metoda count vrací počet výskytů prvku v seznamu.
pocet = s.count(prvek)
print("s.count(prvek):", pocet)

## Jde hledat i v části seznamu.
i = s.index(prvek, 1)
print(f"První výskyt prvku {prvek} se v seznamu {s} od indexu 1 nachází na indexu {i}.")



cekej(cekat)



print("\n\n\n** Řazení seznamu: sort **")
## Řadit nejde seznamy obsahující prvky, co nejdou porovnávat.
print("s:", s)
print("s.sort():")
try:
    s.sort()
except TypeError:
    print("TypeError: '<' not supported between instances of 'tuple' and 'int'")

## Zkusíme seřadit seznam náhodných čísel.
import random
s = random.sample(range(0, 100), 7)
print("s:", s)
s.sort()
print("s.sort():", s)

## Jde řadit i v opačném pořadí
s.sort(reverse=True)
print("s.sort(reverse=True):", s)



cekej(cekat)



print("\n\n\n** Otočení seznamu: reverse **")
## Pořadí prvků seznamu jde otočit (na místě) operací reverse (bez řazení).
s = random.sample(range(0, 100), 7)
print("s:", s)
s.reverse()
print("s.reverse():", s)

## Poznámka: Metoda reverse mění seznam. Funkce reversed používaná v cyklech
## seznam nezmění, jenom jím prochází v opačném pořadí.



cekej(cekat)



print("\n\n\n** Indexování seznamu **")
s = random.sample(range(0, 100), 10)
print("s:", s)
## Funkce len vrací počet prvků seznamu.
print("len(s):", len(s))
## Vrátí první prvek seznamu.
print("s[0]:", s[0])
## Vrátí prvek seznamu na indexu 2, tj. 3. prvek seznamu.
print("s[2]:", s[2])
## Vrátí poslední prvek seznamu.
print("s[-1]:", s[-1])
print("s[len(s)-1]:", s[len(s)-1])
## Vrátí předposlední prvek seznamu.
print("s[-2]:", s[-2])



cekej(cekat)



print("\n\n\n** Řezy seznamu **")
s = random.sample(range(0, 100), 10)
print("s:", s)
## Vrátí podseznam v mezích indexů <2, 7) -- interval je zprava otevřený!
print("s[2:7]:", s[2:7])
## Vrátí podseznam v mezích indexů <2, 7) s krokem 2, tj. každý druhý prvek.
print("s[2:7:2]:", s[2:7:2])
## Vrátí otočený podseznam v mezích indexů <6, 1) s krokem 2, tj. každý druhý prvek.
print("s[6:1:-2]:", s[6:1:-2])
## Vrátí celý seznam.
print("s[:]:", s[:])
## Vrátí každý druhý prvek celého seznamu, ale v opačném pořadí, od posledního prvku.
print("s[::-2]:", s[::-2])
## Vrátí podseznam od indexu 2 až do konce seznamu.
print("s[2:]:", s[2:])
## Vrátí podseznam v mezích indexů <0, 2) -- interval je zprava otevřený!
print("s[:2]:", s[:2])
## Vrátí podseznam obsahující poslední dva prvky seznamu.
print("s[-2:]:", s[-2:])
## Vrátí podseznam neobsahující poslední dva prvky seznamu.
print("s[:-2]:", s[:-2])



cekej(cekat)



print("\n\n\n** Průchody seznamem pomocí cyklu for **")
s = random.sample(range(0, 100), 7)
print("s:", s)
## Funkce len vrací počet prvků seznamu.
print("len(s):", len(s))
print("Průchod v původním pořadí:")
for prvek in s:
    print(prvek)
    
print("Průchod v opačném pořadí pomocí iterátoru reversed(s):")
for prvek in reversed(s):
    print(prvek)

print("Průchod každým druhým prvkem využitím řezu s[::2]:")
for prvek in s[::2]:
    print(prvek)

print("Průchod každým druhým prvkem v opačném pořadí využitím řezu s[::-2]:")
for prvek in s[::-2]:
    print(prvek)

print("Průchod pomocí iterátoru enumerate(s) vrací zároveň pořadí od nuly:")
for index, prvek in enumerate(s):
    print(f"Na indexu {index} je prvek {prvek}.")

print("Průchod pomocí iterátoru enumerate(s, 1) vrací zároveň pořadí od jedničky:")
for poradi, prvek in enumerate(s, 1):
    print(f"{poradi}. prvek: {prvek}")



cekej(cekat)



print("\n\n\n** Generátorové výrazy **")
## Jsou to speciální výrazy sloužící pro výrobu seznamů (nebo i n-tic).
## Nahrazují použití cyklu a metody append.

## základní syntaxe:     list(operace(x) for x in iterátor)
## s vybírací podmínkou: list(operace(x) for x in iterátor if test(x))

cisla = [x for x in range(21)]
suda = [x for x in range(21) if x % 2 == 0]
dvojnasobkysudych = [2*x for x in range(21) if x % 2 == 0]
print("[x for x in range(21)]:", cisla)
print("[x for x in range(21) if x % 2 == 0]:", suda)
print("[2*x for x in range(21) if x % 2 == 0]:", dvojnasobkysudych)

## Poznámka k n-ticím: (x for x in range(21)) tohle nevyrobí n-tici, ale
## iterátor. N-tice se vyrábí takto ((x for x in range(21))) nebo takto
## tuple(x for x in range(21)).



cekej(cekat)



print("\n\n\n** Generování seznamu cyklem **")
## Následující cyklus odpovídá tomuto výrazu: [2*x for x in range(21) if x % 2 == 0]
s = []
for x in range(21):
    if x % 2 == 0:
        s.append(2*x)

print("s:", s)
if s == dvojnasobkysudych:
    print("Seznamy s a dvojnasobkysudych mají stejné prvky.")


