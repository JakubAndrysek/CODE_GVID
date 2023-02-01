############
## Řídící příkazy ##
############

x = 5
y = 9

############
print("*** Podmínka if ***")
## Příkaz if dovoluje vytvořit dvě větve programu.
## Nejprve vyhodnotí podmínku. Pokud je pravdivá,
## půjde výpočet jednou větví, pokud není pravdivá,
## půjde výpočet druhou větví, která je uvozena
## klíčovým slovem else:.
## Větev else není povinná.
if x <= y:  # za podmínkou je dvojtečka
    print("hodnota", x, "je menší nebo rovna", y)   # první větev
else:        # else je odsazeno stejně, jako odpovídající if
    print("hodnota", x, "je větší než", y)              # druhá else

############
print("*** Cyklus while ***")
## Cyklus while slouží pro opakování příkazů,
## dokud není splněna podmínka. Podmínka se
## vyhodnocuje vždy na začátku cyklu.

limit = -1
while limit < 0:          # podmínka se vyhodnotí jednou v každé iteraci
    limit = float(input("Zadej kladné číslo: "))
    if limit < 0:
        print("Zadané číslo není kladné. Zkus to znovu.")

i = 0
while i < limit:          # podmínka se vyhodnotí jednou v každé iteraci
    print("tisknu", i)
    i = i + 1



############
print("*** Cyklus for ***")
## Cyklus for slouží pro předem známý počet opakování.
## Obsahuje proměnnou, která mění v každé iteraci svou hodnotu.
## Této proměnné se říká čítač, počítadlo nebo obecně iterátor (viz dále).
## V Pythonu se s tímto cyklem často používá funkce range.
print("for citac in range(5):")
for citac in range(5):  # bude 5 iterací, citac půjde od nuly
    print(citac, ",  ", sep="", end="")
print()

print("for citac in range(5, 15):")
for citac in range(5, 15):  # citac půjde od 5 do 14, bude se měnit o 1
    print(citac, ",  ", sep="", end="")
print()

print("for citac in range(1, 10, 3):")
for citac in range(1, 10, 3): # citac půjde od 1 do maximálně 9, bude se měnit o 3
    print(citac, ",  ", sep="", end="")
print()

## Cyklus for v Pythonu slouží také k procházení seznamů, n-tic, množin a slovníků.

## Průchod n-ticí
print("N-tice")
for prvek in ("Jóžin", "Bažiny", 15, "Brno"):
    print(prvek, "  ", sep="", end="")
print()

## Průchod seznamem
print("Seznam")
for prvek in ["Vlk", "U zdi", 32, "Nový York"]:
    print(prvek, "  ", sep="", end="")
print()

## Průchod množinou
print("Množina")
for prvek in {"Vlk", "U zdi", 32, "Nový York"}:
    print(prvek, "  ", sep="", end="")
print()

## Průchod slovníkem po klíčích
slovnik = {"jedna": "one", "dvě": "two", "tři": 3}
print("Slovník: klíče")
for klic in slovnik:
    print(klic, "  ", sep="", end="")
print()

## Průchod slovníkem po klíčích a odpovídajících hodnotách
print("Slovník: klíč -> prvek")
for klic, prvek in slovnik.items():
    print("Klíči ", klic, " odpovídá prvek ", prvek, ".", sep="")
print()

    
