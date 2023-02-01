#################
## Podprogramy ##
#################

import math

#################
## Procedura
## Procedura je podprogram s významem příkazu.
## Slouží k pojmenování nějaké části programu, která se pak může použít
## opakovaně.
def hello():                 # Tohle je hlavička.
  """
  Tohle je komentář, tzv. docstring.
  Má za úkol dokumentovat, co podprogram dělá.
  Není povinný, ale je užitečný.
  """
  print("Hello world!")     # Tohle je tělo podprogramu.
  print("How do you do?")   # Odsazení je povinné!
  print("I am fine.")

# Kde odsazení příkazů skončí, končí tělo funkce.

def oddel():
  """Vytiskne oddělovací řádek."""
  print("****************")

## Volání procedur
oddel()
hello()
oddel()
help(hello)  # zobrazí docstring
help(oddel)  # lze použít i v příkazové konzoli

#################
## Podprogram s parametry
## Parametry podprogramu jsou proměnné, které mohou modifikovat činnost
## podprogramu.
def oddelit(znak, pocet):
  """Vytiskne znak pocet-krát na jeden řádek."""
  for i in range(pocet):
    print(znak, end="") # pozn.: end="" zabrání posunu na další řádek
  print()

oddelit("#", 70)

#################
## Funkce
## Funkce je popdprogram s významem výrazu.
## Slouží k pojmenování nějakého výpočtu s jasným výsledkem, který
## může být uložen do proměnné. Opět se dá použít opakovaně.

def minimum(a, b):
  """Vrátí menší ze dvou zadaných hodnot"""
  if a < b:
    return a
  else:
    return b

def pythagoras(a, b):
  """Vrátí délku přepony pravoúhlého trojúhelníka."""
  return math.sqrt(a*a + b*b)

print("Minimum z 5 a 74 je", minimum(5, 74))
print("Přepona trojúhelníku s odvěsnami dlouhými 3 a 7.5 je", pythagoras(3,7.5))
