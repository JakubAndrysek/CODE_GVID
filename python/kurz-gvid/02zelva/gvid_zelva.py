###
## Modul gvid_zelva
##
## Pomocné operace pro práci s želví grafikou
##
## Umísti tento soubor do stejného adresáře jako svůj zdrojový soubor.
## Pak na začátku svého zdrojového souboru napiš
## from gvid_zelva import *
## Od toho místa můžeš používat všechny funkce želvy z modulu turtle
## zároveň s funkcemi z tohoto modulu.
##

from turtle import *

def hopniNa(x, y):
    """
    Skočí na absolutní souřadnice. Nezanechává stopu. Nemění úhel želvy.
    x, y -- nové souřadnice želvy.
    """
    penup()
    setpos(x, y)
    pendown()

def hopniRel(dx, dy):
    """
    Skočí relativně od aktuální pozice. Nezanechává stopu. Zachovává úhel želvy.
    dx, dy -- relativní posun od aktuálních souřadnic želvy.
    """
    penup()
    (x, y) = pos()
    setpos(x+dx, y+dy)
##    if dx != 0:
##        forward(dx)
##    if dy != 0:
##        left(90)
##        forward(dy)
##        right(90)
    pendown()


__zasobnik = []

def pamatuj():
    """
    Zapamatuje si aktuální úhel a pozici želvy.
    Pamatuje si i barvu pera a výplně.
    """
    (pc, bc) = color()
    __zasobnik.append((heading(), position(), pc, bc))

def vzpomen():
    """
    Nastaví posledně zapamatovanou pozici želvy.
    Zároveň nastavuje i zapamatovanou barvu pera a výplně.
    Pokud volání této funkce nepředchází akce pamatuj(),
    dojde k chybě.
    """
    penup()
    (uhel, pozice, pc, bc) = __zasobnik.pop()
    setheading(uhel)
    setpos(pozice)
    color(pc, bc)
    pendown()

