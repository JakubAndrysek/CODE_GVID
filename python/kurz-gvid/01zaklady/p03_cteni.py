####################
## Pro čtení vstupu od uživatele slouží funkce input
## Umí zobrazit výzvu a přečíst text.

vstup = input("Zadej prosím nějaký text: ")
print("Zadal jsi '", vstup, "'", sep="") # sep je oddělovač parametrů, standardně je to jedna mezera

####################
## Pokud je potřeba přečíst celé číslo, je třeba vstupní text
## převést na číslo pomocí funkce int()

vstup = int(input("Zadej celé číslo: "))
print("Zadal jsi", vstup, "druhá mocnina je", vstup*vstup)

####################
## Desetinné číslo se z textu získá funkcí float()
vstup = float(input("Zadej desetinné číslo: "))
print("Zadal jsi", vstup, "druhá mocnina je", vstup*vstup)



#################################
## Pro zájemce o víc informací ##
#################################
## Pokud uživatel zadá hodnotu chybně, Python zahlásí chybu, výjimku.
## Tyto výjimky jde testovat zabránit tak havárii programu.

try:
    vstup = int(input("Zadej celé číslo: "))
    print("Zadal jsi", vstup, "druhá mocnina je", vstup*vstup)
except ValueError:
    vstup = 0
    print("Nezadal jsi celé číslo, trhni si nohou!")
    print("Proměnnou vstup jsem nastavil na hodnotu", vstup)

#################################
## Pro zájemce o víc informací ##
#################################
## Nad textem jde provádět různé úpravy
## upper(), lower(), strip() atd.
vstup = input("Zadej text s malými a velkými písmeny").upper()
print("Tvůj zpracovaný text:", vstup)

#################################
## Pro zájemce o víc informací ##
#################################
## Zadat logickou hodnotu True a False pomocí funkce bool() nejde, protože
## jakýkoli řetězec kromě prázdného se převede na True. 
ok = False
while not ok:
    vstup = input("Zadej logickou hodnotu [Ano, Ne]:").strip().lower()
    ok = vstup in ("ano", "ne") # ntice
    if ok:
        vstup = {"ano": True, "ne": False}[vstup] # tohle je slovník (map)
    else:
        print("Nezadal jsi logickou hodnotu. Zkus to znovu.")

print("Zadal jsi logickou hodnotu", vstup)
