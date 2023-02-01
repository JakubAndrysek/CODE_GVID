###
## Puntíky
## Zadání: Vytvoř a otestuj podprogram, který vykreslí vzor puntíků.
##   Musí jít zadat počet řádků a sloupců, dále poloměr a barva puntíků.
##   Okraje puntíků budou od sebe vzdáleny jeden průměr.
## Ukázka vzoru 3x5:
## *   *   *   *   *
##
## *   *   *   *   *
##
## *   *   *   *   *
## Bonus: Posuň sudé řádky o polovinu vzdálenosti mezi puntíky.
## Ukázka vzoru 3x5:
## *   *   *   *   *
##
##   *   *   *   *   *
##
## *   *   *   *   *
###

##from turtle import *

## Můžeš použít jakékoli podprogramy z modulu gvid_zelva.
from gvid_zelva import *


## Nápověda: Vytvoř si podprogram nebo podprogramy, které můžeš
## opakovaně použít v podprogramech vzorek1 a vzorek2.


def vzorek1(radku, sloupcu, polomer, barva="black"):
  """
  Vykreslí vzorek bez posunutí řádků
  radku, sloupcu -- počet řádků a sloupců ve vzoru
  polomer -- poloměr jednoho puntíku
  barva -- barva pera a výplně jednoho puntíku
  """
  # TODO: dokonči mě
  color(barva)
  write("Podprogram vzorek1 není hotový. Sorry.")

def vzorek2(radku, sloupcu, polomer, barva="black"):
  """
  Vykreslí vzorek s posunutím sudých řádků o půl vzdálenosti mezi puntíky.
  radku, sloupcu -- počet řádků a sloupců ve vzoru
  polomer -- poloměr jednoho puntíku
  barva -- barva pera a výplně jednoho puntíku
  """
  # TODO: dokonči mě
  color(barva)
  write("Podprogram vzorek2 není hotový. Sorry.")


speed(0)

hopniNa(-200, 0)
vzorek1(4, 5, 20, "red")

hopniNa(200, 0)
vzorek2(4, 5, 20, "blue")

