###
## Slovník
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


#########
print("***************")
print("*** Slovník ***")
print("***************")
# Slovník je datová struktura tvořená posloupností dvojic (klíč, hodnota).
# Takové struktuře se někdy říká "asociativní pole", protože každá uložená
# hodnota je tzv. asociována s klíčem. Slovník jde "indexovat" pomocí klíčů.
# Pomocí klíče lze zpřístupnit uloženou hodnotu a přečíst ji nebo změnit.
# Slovník je optimalizovaný pro přístup k hodnotě přes klíč, naopak to neumí.

# Klíče slovníku mohou být pouze řetězce, celá a desetinná čísla a logické
# hodnoty (str, int, float, bool). Uložené hodnoty asociované s klíči mohou
# být libovolného typu, včetně jiných slovníků. Klíče nemohou být duplicitní,
# hodnoty ano.

# Slovníky jsou proměnlivé (mutable) uložené hodnoty je možné měnit.

# Slovník uchovává pořadí vložených párů (od verze Python 3.6, dřívější verze
# pořadí neuchovávaly).





print("\n\n\n** Vytváření slovníků **")
# Seznamy jsou objekty vyráběné jedním ze dvou konstruktorů: {} a dict().
d1 = {}
d2 = dict()
print("d1 = {} ==>", d1)
print("d2 = dict() ==>", d2)

# Do konstruktoru {} jde dosazovat přímo dvojice klíč:hodnota oddělené čárkami.
# Slovník se často zapisuje na více řádcích.
d3 = {
    "jedna" : "one",
    2 : "two",
    }
print("d3 = { 'jedna' : 'one', 2 : 'two'} ==>", d3)

# Do konstruktoru list() jde dosadit jiný slovník, případně jiný iterovatelný
# objekt, který ale musí obsahovat dvojice hodnot.
d4 = dict(d3)
print("d4 = dict(d3) ==>", d3)

# I tato konstrukce je možná.
d5 = dict({"čtyři" : 4})
print("d5 = dict({'čtyři' : 4}) ==>", d5)

# Na slovník jde převést seznam dvojic, za předpokladu, že první prvky dvojic
# jsou hodnoty typů, které mohou figurovat jako klíče (bool, int, float, str)
d6 = dict([("pět", 5), ("šest", 6)])
print("d6 = dict([('pět', 5), ('šest', 6)]) ==>", d6)



cekej(cekat)



print("\n\n\n** Vnořený slovník **")
# Hodnotou (ne klíčem) může být opět i slovník. 
original = {
    "osoba" : { "jméno" : "Donald", "příjmení" : "Kačer" },
    "druh" : "Anas platyrhynchos",
    "pohlaví" : "samec"
    }

print("original =", original)

# Metoda copy dělá stejně jako u seznamu mělkou kopii.
kopie = original.copy()

# Takto změním hodnotu jen u kopie.
kopie["druh"] = "Kachna domácí"

# U vnořeného slovníku se neudělala kopie, ale zkopíroval se odkaz, proto se
# tato změna projeví jak v kopii, tak i zpětně v originálu.
kopie["osoba"]["příjmení"] = "Duck"

print("original =", original)
print("kopie =", kopie)



cekej(cekat)



print("\n\n\n** Porovnávání slovníků **")
# Je to stejné jako u seznamů
a = { "hrnec" : "pot", "ucho" : "ear", "stůl" : "table"}
b = a
c = { "hrnec" : "Topf", "ucho" : "Ohr", "stůl" : "Tisch"}
print("a =", a)
print("b =", b)
print("c =", c)

## Slovníky odkazované proměnnými a a b obsahují prvky se stejnými hodnotami.
if a == b:
    print("a == b")

## Proměnné a a b odkazují na totožný objekt v paměti.
if a is b:
    print("a is b")

## Proměnné a a c jsou jiné slovníky (ačkoli mají stejné klíče).
if a != c:
    print("a != c")
    
## Proměnná a odkazuje na jiný slovník, než proměnná c.
if a is not c:
    print("a is not c")



cekej(cekat)



print("\n\n\n** Hledání ve slovníku **")
print("a =", a)

# Pomocí operátoru in jde rychle testovat přítomnost klíče ve slovníku.
print()
if "ucho" in a:
    print("ucho je ve slovníku")
    print("a['ucho'] ==>", a['ucho'])

# Vybírání hodnoty ze slovníku pomocí operátoru [] může způsobit výjimku,
# když se klíč ve slovníku nenachází.
print()
try:
    preklad = a['lampa']
except KeyError:
    print("preklad = a['lampa'] ==> KeyError")

# Metoda get vrací nalezenou hodnotu k zadanému klíči, nebo v případě neúspěchu
# vrátí None.
print()
preklad = a.get('lampa')
print("preklad = a.get('lampa') ==>", preklad)

# Pokud se použije druhý parametr, vrací v případě neúspěchu tuto hodnotu.
print()
preklad = a.get('lampa', 'neznámý klíč')
print("preklad = a.get('lampa', 'neznámý klíč') ==>", preklad)

# Testovat přítomnost hodnoty ve slovníku sice jde, ale musí se použít
# tzv. "pohledový objekt" vyrobený metodou values(). Je to pomalejší než
# testování klíče v předchozím příkladu.
print()
if "ear" in a.values():
    print("if 'ear' in a.values(): ==> ear je mezi hodnotami")



cekej(cekat)



print("\n\n\n** Přidávání do slovníku **")
print("a =", a)

# Přístupem pomocí operátoru [] jde do slovníku přidávat nový klíč a hodnotu.
print()
a['lampa'] = 'lamp'
print("a['lampa'] = 'lamp'")
print("a =", a)

# Pokud už klíč ve slovníku je, tento přístup přepíše původní hodnotu.
print()
a['ucho'] = 'handle'
print("a['ucho'] = 'handle'")
print("a =", a)

# Metoda setdefault vrací hodnotu ke klíči, pokud tam klíč je...
print()
slovo = a.setdefault('lampa', 'light')
print("slovo = a.setdefault('lampa', 'light') ==>", slovo)
print("a =", a)

# ... a vloží nový pár klíč:hodnota, pokud tam klíč ještě není.
print()
slovo = a.setdefault('světlo', 'light')
print("slovo = a.setdefault('světlo', 'light') ==>", slovo)
print("a =", a)

# Metoda update umí přidat do slovníku prvky z jiného slovníku, přičemž
# případné stejné klíče přepíše.
print()
b = {"ucho" : "ear", "oko" : "eye"}
print("b =", b)
b.update(a)
print("b.update(a)")
print("b =", b)



cekej(cekat)



print("\n\n\n** Odebírání ze slovníku **")
print("a =", a)
print()

# Metoda pop(klíč[, default]) odebere ze slovníku klíč a vrátí hodnotu k němu
# asociovanou. Pokud klíč ve slovníku není, vrací hodnotu uvedenou jako druhý
# nepovinný parametr. Pokud druhý parametr není uveden a klíč ve slovníku není,
# vyhazuje to výjimku KeyError.
slovo = a.pop('světlo', 'není tam')
print("slovo = a.pop('světlo', 'není tam') ==>", slovo)
slovo = a.pop('komín', 'není tam')
print("slovo = a.pop('komín', 'není tam') ==>", slovo)
print("a =", a)

# Metoda popitem() vrací posledně vloženou dvojici (zachovává pořadí LIFO).
# Pokud by byl slovník prázdný, vyhodí výjimku KeyError.
print()
dvojice = a.popitem()
print("dvojice = a.popitem() ==>", dvojice)
print("a =", a)

#del a['hrnec']


cekej(cekat)



print("\n\n\n** Pohledy na slovník **")
print("a =", a)

# Metody keys, values a items vrací tzv. pohledové objekty (view objects).
# Je to něco jako iterátor - dají se použít v cyklech a generátorových výrazech.
print()
print('a.keys() ==>', a.keys())
print('a.values() ==>', a.values())
print('a.items() ==>', a.items())

# Nejsou to seznamy. Chci-li z nich vyrobit seznam, pak například generátorovým
# výrazem - obvykle je to ale zbytečné plýtvání jak časem, tak prostorem.
klice = [x for x in a.keys()]
print('klíče:', klice)

hodnoty = [x for x in a.values()]
print('hodnoty:', hodnoty)

dvojice = [x for x in a.items()]
print('dvojice:', dvojice)



cekej(cekat)



print("\n\n\n** Průchody slovníkem **")
print("a =", a)

print("Počet záznamů ve slovníku: len(a) =", len(a))

# Cyklus for standardně prochází klíči slovníku v pořadí v jakém byly přidány.
print()
print("for klic in a:")
for klic in a:
    print(klic)

# Chci-li zároveň zpracovávat klíče i hodnoty, jde použít pohledový objekt
# získaný metodou items.
print()
print("for klic, hodnota in a.items():")
for klic, hodnota in a.items():
    print(f"a[{klic}] = {hodnota}")

# Podobně můžu procházet s pohledovým objektem získaným metodou keys, ale je to
# asi zbytečné.
print()
print("for klic in a.keys():")
for klic in a.keys():
    print(klic)

# Průchod v opačném pořadí jde do verze 3.7 udělat jen vytvořením nového
# seznamu. Od Pythonu 3.8 jde dělat i reversed(a).
# print()
# print("for klic in reversed(a):")
# for klic in reversed(a):
#     print(klic)

# Podobně můžu procházet s pohledovým objektem získaným metodou values, což
# dává větší smysl.
print()
print("for hodnota in a.values():")
for hodnota in a.values():
    print(hodnota)



cekej(cekat)



print("\n\n\n** Zipování dvou seznamů nebo n-tic do slovníku **")
k = (1, 2, 3, 4)
v = ('jedna', 'dvě', 'tři', 'čtyři')
print("k =", k)
print("v =", v)

# Pomocí zipovacího objektu jde složit nový slovník ze dvou seznamů nebo ntic.
c = {}
for klic, hodnota in zip(k, v):
    c[klic] = hodnota

print("""
c = {}
for klic, hodnota in zip(k, v):
    c[klic] = hodnota""")
print("c =", c)

# Toto jde převést do generátorového výrazu.
d = {x:y for x, y in zip(k, v)}
print()
print("d = {x:y for x, y in zip(k, v)}")
print("d =", d)



cekej(cekat)



print("\n\n\n** Inverzní slovník **")

# Přehozením pořadí seznamů jde udělat inverzní slovník.
d = {x:y for x, y in zip(v, k)}
print()
print("d = {x:y for x, y in zip(v, k)}")
print("d =", d)

# Výroba inverzního slovníku ze slovníku.
print()
print("a =", a)
b = {y:x for x, y in a.items()}
print("b = {y:x for x, y in a.items()}")
print("b =", b)
