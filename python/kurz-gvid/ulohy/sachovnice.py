###
## Želva šachistkou
## Zadání: Vytvoř podprogram pro kreslení šachovnice 8x8 políček.
##   Parametrem bude šířka jednoho políčka. V šachovnici se budou
##   střídat políčka dvou barev.
###

from gvid_zelva import *

def policko(delka, barva, barvaTextu, index=0):
  """Vykreslí jedno políčko šachovnice zadané délky a barvy."""

  # vykreslení políčka
  pencolor(barva)
  fillcolor(barva)
  begin_fill()
  for i in range(4):
    forward(delka)
    left(90)
  end_fill()

  # vykreslení čísla políčka
  if index > 0:
    hopniRel(delka/2, delka/4)
    pencolor(barvaTextu)
    write(index, align="center", font=("Arial", 22, "bold"))
    hopniRel(-delka/2, -delka/4)
    pencolor(barva)



def radek(delka, barvy, index=0):
  """Vykreslí jeden řádek šachovnice."""
  pamatuj()
  for i in range(8):
    # vykreslení jednoho políčka stridej barvy i podle indexu
    policko(delka,  barvy[(i+index)%2], barvy[(i+index+1)%2], index*8+i+1)
    hopniRel(delka, 0)
  vzpomen()

def ohranicSahovnice(delka, barvy):
  """Ohraničí šachovnici."""
  # ohraničení šachovnice
  pencolor(barvy[0])
  for i in range(4):
    forward(delka*8)
    left(90)


def sachovnice(delka, barvy):
  """
  Vykreslí šachovnici od zadané pozice směrem doprava nahoru.
  delka -- rozměr jednoho políčka
  cerna, bila -- skutečné barvy černého a bílého políčka (mohou mít i jiné barvy)
              -- implicitní hodnoty jsou "black" a "white"
  """
  pamatuj()
  for i in range(8):
    radek(delka, barvy, i)
    hopniRel(0, delka)
  vzpomen()
  ohranicSahovnice(delka, barvy)


# zrychlení 1 - pomalu, 10 - rychle, 0 - turboželva
speed(100)

# tracer(1, 550)
# tracer(1, 50)
#tracer(0, 0)

# tloušťka čáry
pensize(3)

delka = 50

# posun výchozí pozice, aby se šachovnice kreslila uprostřed
penup()
setpos(-4*delka, -4*delka)
pendown()

barvy = ["blue", "yellow"]

sachovnice(delka, barvy)


update() # to kvůli podprogramu tracer

# počkáme na kliknutí myši
exitonclick()

