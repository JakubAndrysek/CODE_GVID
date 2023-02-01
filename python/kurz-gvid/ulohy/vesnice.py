###
## Vytvoř funkci domek, která vykreslí obrázek domku se sedlovou
## střechou. Zeď bude tvořena vyplněným čtvercem a střecha vyplněným
## trojúhelníkem. Parametrem funkce bude šířka domku a barvy zdi a
## střechy.

###
## Pomocí funkce domek vykresli celou vesnici. Minimálně 20--50
## domků různých velikostí na náhodných místech na ploše.
## Použij modul random a funkci random.randint(min, max).

## Můžeš použít jakékoli funkce z modulu gvid_zelva.
from gvid_zelva import *

import random

def domek(sirka, stena="gray", strecha="red"):
    """
    Vykreslí domek zadané šířky o zadaných barvách.
    sirka - šířka domku (čtverce)
    stena - barva výplně přední zdi (implicitně šedá)
    strecha - barva výplně střechy (implicitně červená)
    """
    write("Podprogram domek není hotový. Sorry.")
    # TODO: dokonči mě



############
## TODO: Uprav a nakresli celou vesnici.

barvy = ("white", "gray", "brown", "red", "blue", "cyan", "yellow")

speed(5)

stena = barvy[random.randint(0, len(barvy)-1)]
strecha = barvy[random.randint(0, len(barvy)-1)]

domek(random.randint(50, 150), stena, strecha)

