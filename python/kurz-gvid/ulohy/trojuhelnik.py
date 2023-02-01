###
## Napiš podprogram, který vykreslí rovnostranný
## trojúhelník o straně zadané délky.

###
## Napiš podprogram, který vykreslí rovnoramenný
## trojúhelník o podstavě zadané délky a ramenech
## zadané délky. Upozorni uživatele, když trojúhelník
## nepůjde vykreslit.


from turtle import *
import math

def zadejDelku(zprava):
    """
    Vypíše zadanou zprávu a čeká vstup hodnoty.
    Nutí uživatele zadávat hodnotu tak dlouho, dokud nezadá
    správně nenulovou kladnou délku.
    """
    ok = False
    hodnota = 0.0
    while not ok:
        try:
            hodnota = float(input(zprava))
            ok = hodnota > 0.0
            if not ok:
                print("Musíš zadat kladné číslo. Zkus to znovu")
            else:
                return hodnota
        except ValueError:
            print("Vstup není číslo. Zkus to znovu.")

def kresliRovnostranny(strana):
    """
    Vykreslí rovnostranný trojúhelník se stranou zadané délky.
    Kreslí od aktuální pozice a orientace želvy.
    """
    write("Podprogram kresliRovnostranny není hotový. Sorry.")
    # TODO: dokonči podprogram

def kresliRovnoramenny(podstava, strana):
    """
    Vykreslí rovnoramenný trojúhelník s podstavou a stranami
    zadané délky. Pokud trojúhelník nejde vykreslit, nic
    nevykreslí a želva zůstane stát na původní pozici.
    Kreslí od aktuální pozice a orientace želvy.
    """
    write("Podprogram kresliRovnoramenny není hotový. Sorry.")
    # TODO: dokonči podprogram



## Tohle je specialita. Funkce vyšších řádů neprobíráme.
## Funkce může mít za parametr jinou funkci.
## Parametr param je seznam parametrů pro funkci funkce.
def rotuj(kolikrat, funkce, param):
    """
    Zopakuje zadanou funkci pro kreslení želvou kolikrát.
    """
    uhel = 360/kolikrat
    for i in range(kolikrat):
        funkce(*param)  # specialita
        left(uhel)



##########
## Tady volej své funkce. Následující kód si můžeš jakkoli upravit.

strana = zadejDelku("Zadej délku:")

speed(8) # Nastavuje rychlejší vykreslování

rotuj(5, kresliRovnostranny, (strana, ))

#rotuj(17, kresliRovnoramenny, (strana/2, strana))
