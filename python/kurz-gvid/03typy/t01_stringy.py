###
## Textové řetězce
###

print("*** Textové řetězce -- stringy ***")
## Textový řetězec -- string je posloupnost znaků.
## Používá se pro uchovávání a zpracovávání textů.

## Stringy se tvoří jako text uzavřený v uvozovkách.
## Mohou být buďto "dvojité" nebo 'jednoduché'. Není
## v tom rozdíl, ale musí být na obou stranách stejné.
## Využívá se to v případech, kdy je třeba mít uvozovky
## součástí stringu. Uvnitř dvojitých mohou být používány
## jednoduché uvozovky a naopak.
## Stringy v Pythonu 3 jsou automaticky v unicode.

konik = "Příliš žluťoučký kůň úpěl: 'ÍÍHÁHÁÁ'."
print("konik =", konik)

## Stringy jsou neměnné (immutable), proto každá
## operace, která "mění" string, ve skutečnosti
## vytváří string nový.

## Poznámka: Pokud chcete tvořit efektivní programy,
## snažte se úpravám stringů vyhýbat. Každá změna
## vede k vytváření nového stringu, což zabírá paměť
## a dost to zdržuje.

## Stringy jde sčítat. Vznikne nový string.
spam = "spam "
egg = "egg "

print("Sčítání stringů:")
print("spam + egg =", spam + egg)

## Stringy jde násobit číslem. Význam je opakování stringu.
print("Násobení stringů:")
print("3*spam + 2*egg =", 3*spam + 2*egg)

## Python nemá speciální typ pro ukládání jednoho znaku.
## Jeden znak je prostě string o délce 1

## Počet znaků ve stringu vrací funkce len
print("String konik je dlouhý", len(konik), "znaků.")

########
print("Indexování -- řezy")
## Jednotlivé znaky ve stringu jde indexovat pomocí hranatých
## závorek. První znak má vždy index 0.
print("První znak řetězce '" + spam + "' je '" + spam[0] + "'.")

## Tohle by mělo být rychlejší, protože tady se nové stringy netvoří.
print("Druhý znak řetězce '", spam, "' je '", spam[1], "'.", sep="")


## Jde vybírat i podřetězec pomocí rozsahového řezu.
print("Řezy")
print("konik[17:20] = '", konik[17:20], "'", sep="")
print("konik[:17] = '", konik[:17], "'", sep="")
print("konik[17:] = '", konik[17:], "'", sep="")

## Escape sekvence
print("Escape sekvence")
## Jsou to sekvence znaků začínající opačným lomítkem.
## Mají význam nějakého znaku, který nejde vůbec, nebo
## obtížně napsat. Samotný znak opačného lomítka se musí
## běžně psát jako escape sekvence \\. Zde jsou příklady:
print("\\a -- alert, bell, zvonek: \a -- vydá zvuk na některých terminálech")
print("\\n -- konec\nřádku")
print("\\t\t--\ttabulátor")
print("\\xnn -- hexa kód znaku, např. \\xF5 = \xF5")

## Raw stringy
print("Raw stringy")
## Syrový řetězec má před první uvozovkou písmeno r nebo R.
## Takový řetězec ignoruje escape sekvence, tudíž lze psát
## opačná lomítka samostatně bez obav z jejich interpretace.
print(r"\\a -- alert, bell, zvonek: \a -- vydá zvuk na některých terminálech")
print(r"\\n -- konec\nřádku")
print(R"\\t\t--\ttabulátor")
print(R"\\xnn -- hexa kód znaku, např. \\xF5 = \xF5")

print("Formátované řetězce")
## Použitím metody format nad řetězcem, lze do něj doplňovat hodnoty
## proměnných a výrazů za běhu programu. Výsledkem je opět nový
## string. Je to velice užitečné a často používané. V pythonu 2
## se syntaxe podobá formátovacím řetězcům známým z jazyka C.
## Python 3 zavádí odlišnou syntaxi, která je asi názornější
## pro pojídače koláčů, ale je o trochu více ukecaná...
## Více viz https://pyformat.info/
print("{0}{1}{0}".format("abra", "kad"))



print("Stringy v podmínkách")
## Řetězce jde v Pythonu porovnávat pomocí porovnávacích
## operátorů. Stringy se porovnávají tzv. lexikograficky,
## tedy slovníkově (podle stejných pravidel, jakými se
## řadí slova ve slovnících).

if "Aaron" < "Abel":
    print("Správné pořadí: Aaron, Abel")
else:
    print("Chybné pořadí: Abel, Aaron")

## Pozor! Toto porovnávání nefunguje podle českých pravidel.
## Chcete-li pracovat správně s češtinou, je potřeba
## použít modul locale, zapnout lokalizaci funkcí setlocale
## a porovnávat pomocí funkce strcoll.
## Viz http://python.wraith.cz/tech-locale-python.php

if "Ďas" < "Dobrovolný":
    print("Správné pořadí: Ďas, Dobrovolný")
    # Tohle je opravdu podle českých pravidel správně!
else:
    print("Chybné pořadí: Dobrovolný, Ďas")
    

## Pomocí operátoru in (not in) lze testovat, zda se
## ve stringu nachází znak nebo podřetězec.

if "kůň" in konik:
    print("Proměnná konik obsahuje podřetězec 'kůň'")
else:
    print("Proměnná konik neobsahuje podřetězec 'kůň'")

print("Víceřádkové stringy")
## Tyto stringy s trojitými uvozovkami slouží pro zápis
## delších textů.
## Pokud se takový řetězec umístí hned pod hlavičku funkce,
## pokládá se za tzv. docstring, tedy dokumentační komentář,
## který pak jde zobrazovat pomocí funkce help.
multistring = """Toto je příklad
víceřádkového stringu.
konce řádků není třeba zapisovat
pomocí escape sekvencí.
Escape sekvence jako \n přesto
fungují.
"""
print(multistring)



## Nad stringy lze provádět množství dalších operací.
## Jejich seznam lze získat v terminálu příkazem help.
## Nápověda je poměrně dlouhá, proto si odkomentuj jen
## to, co potřebuješ.
##help(str) # zobrazí všechny funkce proveditelné nad stringem
##help(str.capitalize) # nápověda pro funkci capitalize
##help(str.title)
##help(str.isdigit)
##help(str.islower)
##help(str.isupper)
##help(str.isalpha)
##help(str.isdigit)
##help(str.lower)
##help(str.upper)
##help(len)
##help(min)
##help(max)

print(konik.capitalize())
print(konik.upper())
print(konik.title())


