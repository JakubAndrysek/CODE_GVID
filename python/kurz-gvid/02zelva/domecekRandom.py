###
## Vytvoř funkci domek, která vykreslí obrázek domku se sedlovou
## střechou. Zeď bude tvořena vyplněným čtvercem a střecha vyplněným
## trojúhelníkem. Parametrem funkce bude šířka domku a barvy zdi a
## střechy.

###
## Pomocí funkce domek vykresli celou vesnici. Minimálně 20--50
## domků různých velikostí na náhodných místech na ploše.
## Použij modul random a funkci random.randint(min, max).

from gvid_zelva import *

import random

def domek(a, stena="gray", strecha="red"):
    pamatuj()
    hopniRel(0, a)

    fillcolor(stena)
    i = 0
    begin_fill()
    while i < 4:
        forward(a)
        right(90)
        i = i + 1
    end_fill()

    fillcolor(strecha)
    left(90-30)
    begin_fill()
    forward(a)
    right(120)
    forward(a)
    end_fill()
    vzpomen()

barvy = ("white", "gray", "brown", "red", "blue", "cyan", "yellow")

speed(0)

for i in range(random.randrange(10, 30)):
    hopniNa(random.randrange(-500, 500), random.randrange(-500, 500))
    color1 = barvy[random.randrange(0, 9)]
    color2 = barvy[random.randrange(0, 9)]
    domek(random.randrange(5, 80), color1, color2)
    

