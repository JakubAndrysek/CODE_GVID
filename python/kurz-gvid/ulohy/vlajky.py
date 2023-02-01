###
## Česká vlajka
## Zadání: Vytvoř podprogram, který nakreslí českou vlajku
##         zadané šířky od aktuální pozice ve vodorovné
##         orientaci. Modrý klín zasahuje do poloviny
##         šířky vlajky. Vlajka má poměr stran 2:3.
## Bonus: Vytvoř podprogram tak, aby nakreslil vlajku
##        relativně od aktuální pozice a bral ohled
##        i na aktuální úhel natočení želvy.

###
## Vlajka EU
## Zadání: Vytvoř podprogram, který nakreslí vlajku EU
##         zadané šířky od aktuální pozice ve vodorovné
##         orientaci. Vlajku tvoří 12 žlutých hvězd v kruhu
##         na azurové (modré) vlajce. Vlajka má poměr stran
##         2:3.
##         Uprav si podprogram hvezda tak, aby nekreslil
##         kružnici a použij jej pro kreslení hvězd.
##         Hvězdy po obvodu kruhu nesmí být natáčeny,
##         musí mít stále stejnou orientaci.
## Bonus: Vytvoř podprogram tak, aby nakreslil vlajku
##        relativně od aktuální pozice a bral ohled
##        i na aktuální úhel natočení želvy.

## Poznámky k řešení: Kruh hvězd lze generovat cyklem.
##   1. možnost: Želva se vrátí do středu, otočí se,
##               skočí na kruh a kreslí hvězdu.
##   2. možnost: Funkce circle má skrytý parametr pro
##               kreslení kruhového oblouku. Jeho hodnota
##               má význam relativního úhlu od aktuální
##               pozice. Např. circle(100, 180) vykreslí
##               180stupňový oblouk, tedy pouze polovinu
##               kružnice. Želva musí být natočena kolmo
##               ke středu kružnice.
##               Detailní popis v konzoli:
##               import turtle
##               help(turtle.circle)


###
## Vlajka USA
## Zadání: Vytvoř podprogram, který nakreslí vlajku USA
##         zadané šířky od aktuální pozice ve vodorovné
##         orientaci.
##         Vlajka má poměr stran 10:19. Má 6 bílých a
##         7 červených pruhů. Má 50 bílých hvězd na
##         tmavě modrém pozadí. Poměry jednotlivých
##         prvků najdeš na wikipedii (heslo: vlajka USA).
## Bonus: Vytvoř podprogram tak, aby nakreslil vlajku
##        relativně od aktuální pozice a bral ohled
##        i na aktuální úhel natočení želvy.

## Poznámky k řešení:  Použij podprogram pro kreslení
##   jednoho obdélníku. Bílé pruhy pak kresli cyklem do
##   červeného pole. Pole s hvězdami kresli až nakonec.
##   Inspiruj se kódem, který už máš z úlohy s puntíky.


##from turtle import *

## Můžeš používat všechny funkce z modulu gvid_zelva
from gvid_zelva import *

import math


def hvezda(polomer, kruh=True):
  """
  Vykreslí pěticípou hvězdu uprostřed kružnice zadaného poloměru.
  Želva na začátku stojí uprostřed hvězdy a míří doprava od horního
  vrcholu.
  polomer -- poloměr kružnice opsané pěticípé hvězdě
  """
  # pamatuj si výchozí pozici a natočení
  pos = position()
  uhel = heading()

  # nejdříve kružnice
  if kruh:
    hopniRel(0, -polomer)
    circle(polomer)
    hopniRel(0, 2*polomer)
  else:
    hopniRel(0, polomer)
  right(90)

  # výpočet jedné strany pěticípé hvězdy
  # poznámka: řekněte učiteli matematiky, ať to s vámi odvodí ;-)
  strana = polomer*math.sin(math.radians(72))-polomer*math.cos(math.radians(72))*math.tan(math.radians(36))

  # hvězda kreslená od horního vrcholu
  right(36/2)
  begin_fill()
  for _ in range(5):
    forward(strana)
    right(180-108)  # tupý úhel je 108 stupňů
    forward(strana)
    left(180-36)    # ostrý úhel je 36 stupňů
  end_fill()

  # nakonec se vracím na původní pozici ve středu hvězdy
  penup()
  setpos(pos)
  setheading(uhel)
  pendown()

def obdelnik(sirka, vyska, smer):
  """
  Vykreslí obdélník od aktuální pozice zadaným směrem
  """
  setheading(smer)
  for _ in range(2):
    forward(sirka)
    left(90)
    forward(vyska)
    left(90)


def ceska(sirka):
  """
  Vykreslí českou vlajku ve vodorovné orientaci od aktuální pozice.
  sirka -- šířka vlajky
  """
  ## TODO: Dokonči českou vlajku

  vyska = 2*sirka/3
  smer = heading()

  pensize(3)
  fillcolor("white")
  pencolor("black")
  begin_fill()
  obdelnik(sirka, vyska, smer)
  end_fill()
  write("Podprogram ceska není hotový. Sorry.")

def eu(sirka):
  """
  Vykreslí vlajku Evropské unie o zadané šířce.
  """
  ## TODO: Dokonči vlajku EU

  vyska = 2*sirka/3
  smer = heading()
  pos = position()

  pensize(3)
  color("black", "blue")
  begin_fill()
  obdelnik(sirka, vyska, smer)
  end_fill()
  write("Podprogram eu není hotový. Sorry.")




def usa(sirka):
  """
  Vykreslí vlajku USA o zadané šířce.
  """
  ## TODO: Dokonči vlajku USA

  smer = heading()

  pensize(3)
  b = sirka
  a = b/1.9
  color("black", "red")
  begin_fill()
  obdelnik(b, a, smer)
  end_fill()
  write("Podprogram usa není hotový. Sorry.")


######################
# Poznámka: Následující kód je jenom ukázka. Můžeš to smazat nebo
# zakomentovat (v IDLE alt+3) a dopsat si zde svůj vlastní.

speed(0)       # želva na steroidech

# tohle odkomentovat pro rychlé kreslení
#tracer(0, 0)   # vypne refresh okna, takže z želvy je Flash Gordon




hopniRel(300, 300)

hideturtle()
for barva in ("blue", "red", "green", "yellow"):
  color(barva)
  hvezda(100)
  left(36/2)


setheading(0)
hopniRel(-400, -600)
for vlajka in (ceska, eu, usa):
  vlajka(500)
  penup()
  left(90)
  circle(250, 20)
  right(90)
  pendown()

showturtle()

update() # Má význam, když je spuštěný tracer
