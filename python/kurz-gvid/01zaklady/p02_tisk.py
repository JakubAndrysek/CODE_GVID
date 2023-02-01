##############################
## Tisk hodnot různých typů ##
##############################

## K tisku slouží funkce print
print("****************")
print('textový řetězec')

## Prázdný řádek se tiskne takto
print()

## Umí tisknout hodnoty konstant a matematických výrazů
print("****************")
print(5)
print(1+1)
print(5.1/2.4)

## Tiskne textové řetězce
## Ty mohou být uvozeny jednoduchými nebo dvojitými uvozovkami
print("****************")
print("Aš nazg durbatulûk, aš nazg gimbatul,")
print('aš nazg thrakatulûk, agh burzum-iši krimpatul.')
## Chci-li tisknout uvozovky, lze toho využít
print('Gandalf však stál pevně. "Nemůžeš projít," řekl.')

## Tiskne seznamy, n-tice i množiny
print("****************")
print([1, 2, 3]) # seznam
print((4, 5, 6)) # n-tice
print({7, 7, 8}) # množina
print({"jedna": "one", "dvě": "two", "tři": 3})  # slovník, mapa, asociativní pole

## Tiskne i obsahy proměnných
slovo = "slovo"
cele = 159
desetinne = 5.7864
pravda = True
seznam = [slovo, slovo, cele, desetinne, pravda]
ntice = (slovo, slovo, cele, desetinne, pravda)
mnozina = {slovo, cele, desetinne, slovo, pravda}
slovnik = {"jedna": "one", "dvě": "two", "tři": 3}

print("****************")
print(slovo)
print(cele)
print(desetinne)
print(pravda)
print(seznam)
print(ntice)
print(mnozina)
print(slovnik)

## Umí tisknout více hodnot najednou a lze je různě kombinovat
print("****************")
print("slovo =", slovo)
print("cele =", cele, "desetinne =", desetinne)
print("pravda je", pravda, "nepravda je", not pravda)
print("seznam prvku je", seznam, "\nntice je", ntice, "\nmnozina je", mnozina)
print("slovnik je", slovnik)
print('slovnik["jedna"] je', slovnik["jedna"],
      ', slovnik["dvě"] je', slovnik["dvě"],
      ', slovnik["tři"] je', slovnik["tři"])
