###################
## Želví grafika ##
###################

# Natáhne funkce z knihovny turtle
# Takto jde kreslit s jednou želvou
from turtle import *

pos = position()     # Pamatuj pozici jako n-tici, souřadnice pak jsou pos[0] a pos[1]
uhel = heading()     # Pamatuj si aktuální úhel
barva = color()      # Pamatuj si barvu (pera, výplně) jako n-tici
tloustka = pensize() # Pamatuj si aktuální tloušťku pera

speed(1)         # Nastav nejnižší rychlost

forward(100)     # Jdi 100 kroků dopředu
left(90)         # Otoč se doleva o 90 stupňů
forward(100)     # Jdi 100 kroků dopředu

setpos(0, 0)     # Jdi na souřadnice 0,0
setheading(-90)  # Nastav směr na -90 stupňů

speed(5)         # Nastav střední rychlost

forward(250)     # Jdi 250 kroků dopředu
right(90)        # Otoč se doprava o 90 stupňů
forward(100)     # Jdi 100 kroků dopředu
setpos(0, 0)     # Jdi na souřadnice 0,0

penup()          # Zvedni kreslící pero
setpos(100, 150) # Jdi na pozici 100, 150
pendown()        # Polož kreslící pero
color("blue")    # Nastav barvu pera (želvy)
circle(20)       # Nakresli kolečko o průměru 20

penup()          # Zvedni kreslící pero
backward(150)    # Jdi 150 bodů dozadu

speed(10)        # Nastav vysokou rychlost

pendown()           # Polož kreslící pero
pencolor("blue")    # Nastav barvu pera
fillcolor("yellow") # Nastav barvu výplně
pensize(5)          # Nastav tloušťku pera
begin_fill()        # Zde začíná výplň
circle(30,steps=6)  # Kresli šestiúhelník s poloměrem 30
end_fill()          # Zde končí výplň - uzavřená oblast se vyplní barvou

left(180)           # Čelém vzad!
pensize(25)         # Nastav tloušťku pera
color("green", "magenta") # Nastav barvu pera i výplně
begin_fill()        # Zde začíná výplň
circle(50, 180)     # Nakresli kruhový oblouk s poloměrem 50 a úhlem 180 stupňů
end_fill()          # Zde končí výplň - uzavřená oblast se vyplní barvou
color("magenta", "green")    # Nastav barvu pera i výplně
begin_fill()        # Zde začíná výplň
circle(50, 180)     # Nakresli kruhový oblouk s poloměrem 50 a úhlem 180 stupňů
end_fill()          # Zde končí výplň - uzavřená oblast se vyplní barvou

speed(0)         # Nastav nejvyšší rychlost

penup()                   # Zvedni kreslící pero
setpos(pos)               # Návrat na výchozí pozici
setheading(uhel)          # Návrat k původnímu natočení
color(barva[0], barva[1]) # Návrat k původním barvám pera a výplně 
pensize(tloustka)         # Návrat k původní tloušťce pera
pendown()                 # Polož kreslící pero

# Vykresli čtverec
for _ in range(4):
    forward(50)
    left(90)


