###
## N-tice a seznamy
###

## Návod: Pomocí debuggeru (např. programem Thonny) projdi jednotlivé řádky,
##        přečti si komentáře okolo a podívej se na výsledky.

#########
print("*** N-tice ***")
## N-tice je proměnná tvořená posloupností hodnot s jasně daným pořadím.
## N-tice se tvoří pomocí kulatých závorek.
## N-tice se v mnohém podobá stringu, jen prvkem n-tice může
## být libovolný typ hodnoty, nejen znaky.

ntice = (1, "ahoj", print, ("vnořená", "n-tice"))


## Proměnná ntice je vlastně jen odkazem na skutečnou n-tici uloženou v paměti.

x = ntice

## Proměnná x nyní neobsahuje kopii, ale odkazuje na původní n-tici.

print(ntice)
print(x)

## N-tice se liší od seznamu (viz dále) tím, že je neměnná (immutable).
## To znamená, že po vytvoření už ji nelze měnit (narozdíl od seznamu).

## Prázdná n-tice je tvořená pouze závorkami. Jednoprvková n-tice musí
## mít za prvním prvkem čárku, jinak by ji Python mohl zaměnit za
## aritmetický výraz.

prazdna = ()
jednoprvkova = (784, )
print("Prázdná n-tice:", prazdna)
print("Jednoprvková n-tice:", jednoprvkova)





print("** Operace s n-ticemi **")
## Prvky n-tice lze indexovat, tj. vybírat podle pořadí. První prvek
## má vždy index 0.

print("První prvek ntice[0] je ", ntice[0])
print("Druhý prvek ntice[1] je ", ntice[1])

## Počet prvků n-tice lze zjistit pomocí funkce len
print("Ntice x obsahuje", len(x), "prvků.")

## S n-ticí lze zacházet podobně jako s textovým řetězcem.
## Sčítání n-tic vyrobí novou n-tici složenou z prvků původních n-tic.
treti = x + jednoprvkova
print("treti = x + jednoprvkova:", treti)

## Podobně vyrobí novou n-tici i násobení *
ctyrprvkova = 4*jednoprvkova
print("ctyrprvkova = 4*jednoprvkova:", ctyrprvkova)

## N-tice lze porovnávat pomocí běžných porovnávacích operátorů.
## Porovnávají se lexikograficky, podobně jako řetězce.
if jednoprvkova < ntice:
    print("jednoprvkova je lexikograficky před ntice")
else:
    print("jednoprvkova je lexikograficky za ntice")

## Pomocí operátoru in lze testovat členství prvků v n-tici.
if "ahoj" in x:
    print("V n-tici x se nachází prvek 'ahoj'.")
else:
    print("V n-tici x se nenachází prvek 'ahoj'.")

## Pomocí cyklu for lze iterovat (procházet) přes prvky n-tice
print("N-tice x vypsaná po prvcích:")
for prvek in x:
    print(prvek)

## Finta: Při přiřazení do n-tice proměnných lze nastavit více proměnných
## v jediném kroku. Poznámka: nově tvořené proměnné se mohou vyskytovat
## výhradně na levé straně přiřazovacího operátoru.   
(a, b, c) = (1, 2, 3)
print("(a, b, c) = (1, 2, 3):")
print("a =", a, "b =", b, "c =", c)

## N-tice jde využít i v případě, že chci z funkce získat více výstupních
## hodnot. Pomocí return lze totiž vrátit i hodnotu typu n-tice.
def vektor(bod1, bod2):
    return (bod2[0]-bod1[0], bod2[1]-bod1[1])

k = (1, 2)
l = (3, 3)
v = vektor(k, l)
print("Body ", k, "a", l, "tvoří vektor", v)

############
## N-tice je vlastně objektem třídy tuple. Nápovědu ke všem operacím,
## které lze s n-ticí provádět naleznete pomocí příkazu help.

## Pro běžné použití jsou definovány metody .count a .index. Metody
## začínající podtržítkem jsou skryté.
print("V proměnné ntice se hodnota 1 vyskytuje", ntice.count(1), "krát.")
print("V proměnné ntice leží hodnota 'ahoj' na indexu", ntice.index("ahoj"))


## Pro zobrazení nápovědy k ntici použij funkci help
##help(tuple)
