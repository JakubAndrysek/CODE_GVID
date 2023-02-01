###
## Kreslení terče
## Zadání: Vytvoř podprogram, který vykreslí terč zadaného poloměru
##   a počtem mezikruží. Mezikruží se budou vykreslovat střídavě
##   dvěma barvami.
###

##from turtle import *

## Můžeš použít jakékoli funkce z modulu gvid_zelva
from gvid_zelva import *

def terc(polomer, pocet, vnejsiBarva = "black", vnitrniBarva = "white"):
  """
  Vykreslí terč o zadaném poloměru se středem v aktuální pozici.
  polomer -- poloměr terče
  pocet -- počet okruží
  vnejsiBarva -- barva vnějšího kruhu
  vnitrniBarva -- barva prvního vnitřního kruhu, barvy se střídají
  """
  pensize(3)
  write("Podprogram terc ještě není hotový. Sorry.")
  # TODO: dokonči mě
  


speed(10)
terc(300, 6, "blue", "white")
