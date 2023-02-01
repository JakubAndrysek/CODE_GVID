###
## Želva šachistkou
## Zadání: Vytvoř podprogram pro kreslení šachovnice 8x8 políček.
##   Parametrem bude šířka jednoho políčka. V šachovnici se budou
##   střídat políčka dvou barev.
###

from gvid_zelva import *

def policko(delka, barva):
  """Vykreslí jedno políčko šachovnice zadané délky a barvy."""
  # TODO: dokonči mě
  write("Podprogram policko ještě není hotový. Sorry.")


def sachovnice(delka, cerna="black", bila="white"):
  """
  Vykreslí šachovnici od zadané pozice směrem doprava nahoru.
  delka -- rozměr jednoho políčka
  cerna, bila -- skutečné barvy černého a bílého políčka (mohou mít i jiné barvy)
              -- implicitní hodnoty jsou "black" a "white"
  """
  # TODO: dokonči mě
  write("Podprogram sachovnice ještě není hotový. Sorry.")


# zrychlení 1 - pomalu, 10 - rychle, 0 - turboželva
speed(0)

#tracer(1, 250)
#tracer(1, 50)
#tracer(0, 0)

# tloušťka čáry
pensize(3)

delka = 50

# posun výchozí pozice, aby se šachovnice kreslila uprostřed
penup()
setpos(-4*delka, -4*delka)
pendown()

sachovnice(delka, "blue", "yellow")


update() # to kvůli podprogramu tracer

