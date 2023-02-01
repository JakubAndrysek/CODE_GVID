######################
## Výrazy, proměnné ##
######################


######################
print("*** Tisk ***")
## Tisk se provádí pomocí příkazu print
print("Ahoj! Odpověď je 42.")

######################
print("*** Proměnné ***")
## Proměnná je pojmenovaný kus paměti.
## V Pythonu je proměnná obecný kontejner pro ukládání hodnot různých typů.
## Proměnná se vytvoří svým prvním použitím pro zápis.
## Nesmí se hned napoprvé použít ke čtení.
x = 1+1 # tohle je ok
print("x je", x)
y = x*2 # tohle je taky ok
print("y je", y)
#y = z/2 # Tohle je chyba! Zkus to odkomentovat a spustit.
x = "slovo" # V Pythonu je to ok. Typ je svázán s hodnotou, ne s proměnnou.
print("x je", x)
print("y je", y)

# Poznámka: V jiných programovacích jazycích se proměnné používají jinak.
# Obvyklé je, že proměnnou je třeba nejprve vyrobit -- deklarovat a až pak
# používat. Zároveň je potřeba říct, hodnoty jakého typu do proměnné půjdou
# ukládat. Pokud např. vyrobíme proměnnou pro celá čísla, už do ni nejde
# uložit text, jako jsme to udělali v předchozím příkladu.

######################
print("*** Výrazy ***")
## Výraz je tvořen operátory a operandy.
## Výraz lze spočítat a reprezentuje výslednou hodnotu.
## Výsledek výrazu lze dále použít, např. uložit do proměnné.
## Výraz se ale nemůže objevit vlevo od přiřazovacího operátoru =.
x = 1 + 2
x = x + 1 # nejprve se spočítá výraz vpravo a výsledek se uloží do x
y = 3
print(x,"na", y, "je", x**y) # výraz se spočítá a vytiskne, ale x ani y se teď nemění

print("Matematické operátory")
print(x,"+", y, "je", x+y)
print(x,"-", y, "je", x-y)
print(x,"*", y, "je", x*y)
print(x,"/", y, "je", x/y)        # desetinné dělení
print(x,"//", y, "je", x//y)      # celočíselné dělení
print(x,"modulo", y, "je", x%y)   # zbytek po celočíselném dělení
print(x,"na", y, "je", x**y)      # mocnina


######################
## Matematické funkce
print("*** Matematické funkce ***")
import math # Je potřeba použít knihovnu math

print("Matematické funkce a konstanty")
print("Ludolfovo číslo Pi je ", math.pi)
print("Eulerovo číslo E je ", math.e)

print()
print("Goniometrické funkce počítají v radiánech.")
x = 90
print("radians(", x, ") je", math.radians(x))
y = math.radians(x)
print("degrees(", y, ") je", math.degrees(y))
x = math.pi / 3
print("sin(", x, ") je", math.sin(x))
y = math.sin(x)
print("asin(", y, ") je", math.asin(y))
print("cos(", x, ") je", math.cos(x))
y = math.cos(x)
print("acos(", y, ") je", math.acos(y))
print("tan(", x, ") je", math.tan(x))
y = math.tan(x)
print("atan(", y, ") je", math.atan(y))

print()
x = 2
print("Odmocnina sqrt(", x, ") je", math.sqrt(x))
print("Přirozený logaritmus log(", x, ") je", math.log(x))
print("Desítkový logaritmus log10(", x, ") je", math.log10(x))
print("Dvojkový logaritmus log2(", x, ") je", math.log2(x))
print("E na x: exp(", x, ") je", math.exp(x))



















