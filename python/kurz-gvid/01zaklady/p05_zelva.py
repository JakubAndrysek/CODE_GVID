###################
## Želví grafika ##
###################

# Natáhne funkce z knihovny turtle
# Takto jde kreslit s jednou želvou
from turtle import *

zasobnik = []

def remember():
    zasobnik.append((heading(), position()))

def recall():
    (uhel, pozice) = zasobnik.pop()
    setheading(uhel)
    setpos(pozice)

shape("turtle")
speed(2)         # Nastaví rychlost od 1 (nejpomalejší) do 10 (rychlé). Nula znamená nejrychlejší.
pensize(3)       # Nastaví tloušťku čáry

forward(100)     # Jdi 100 kroků dopředu
left(90)         # Otoč se doleva o 90 stupňů
remember()
forward(100)     # Jdi 100 kroků dopředu

setpos(0, 0)     # Jdi na souřadnice 0,0
setheading(-90)  # Nastav směr na -90 stupňů

forward(250)     # Jdi 250 kroků dopředu
right(90)        # Otoč se doprava o 90 stupňů
forward(100)     # Jdi 100 kroků dopředu

#setpos(0, 0)     # Jdi na souřadnice 0,0
recall()

penup()          # Zvedni kreslící pero
setpos(100, 150) # Jdi na pozici 100, 150
pendown()        # Polož kreslící pero
color("blue")    # Nastav barvu pera (želvy)
circle(20)       # Nakresli kolečko o průměru 20

penup()          # Zvedni kreslící pero
backward(200)    # Jdi 200 bodů dozadu
