; Tečkové páry
; ============
; Jsou základní datovou strukturou pro tvorbu složitějších struktur.
; Tečkový pár je dvojice jakýchkoli hodnot. Pomocí tečkových párů se
; obecně tvoří abstraktní datové struktury, například komplexní čísla
; či souřadnice, u složitějších struktur s více datovými položkami bude
; jedním z prvků opět tečkový pár. Protože prvkem páru může být i jiný
; pár, dají se pomocí nich vytvořit všechny další datové struktury
; jako jsou seznamy, stromy, obecné grafy atd.
 
; Tečkový pár se konstruuje se pomocí kulatých závorek a tečky.
; Protože výraz začínající závorkou by se interpret pokusil vyhodnotit,
; je potřeba před ní zapsat uvozovku (tzv. kvotování).
"Konstrukce tečkového páru pomocí zápisu s uvozovkou"
'(1 . 2)

; Druhou možností je použití konstruktoru cons
"Konstrukce tečkového páru pomocí funkce cons"
(cons 1 2)

; Tečkový pár lze i pojmenovat
(define dvojice (cons 1 2))

; Práce s tečkovými páry
; Výběr první hodnoty - pomocí funkce car
"Výběr prvního prvku z tečkového páru"
(car dvojice)

; Výběr druhé hodnoty - pomocí funkce cdr
"Výběr druhého prvku z tečkového páru"
(cdr dvojice)

; Pomocí tečkových párů lze vytvářet i složitější konstrukce
(define strom (cons (cons 1 2) (cons 3 4)))

; Funkce car a cdr lze kombinovat.
; Při výběru lze používat zkratky
"Výběr prvků ze stromu"
strom
(car strom)
(cdr strom)

(car (car strom))
(caar strom)

(cdr (car strom))
(cdar strom)

(car (cdr strom))
(cadr strom)

(cdr (cdr strom))
(cddr strom)

; Seznamy
; =======
; Seznam je rekurzivní struktura. Je buďto prázdný nebo obsahuje hlavičku a zbytek, což
; je také seznam.

; Seznamy se konstruují pomocí tečkových párů, kdy první prvek páru je vždy hlavička
; druhý prvek páru je vždy zbytek seznamu. Poslední prvek seznamu je vždy prázdný
; seznam, který se konstruuje buďto prázdnými závorkami () nebo pomocí výrazu null.

; Protože se v jazyce Scheme se seznamy pracuje často, není třeba seznamy vytvářet
; explicitním specifikováním jednotlivých tečkových párů, ale stačí všechny prvky
; seznamu zapsat za sebe do kulatých závorek. V tom případě se na konci už neuvádí
; prázdný seznam.

; Různé způsoby definování seznamů. Všechny jsou ekvivalentní.
(define la '(1 . (2 . (3 . (4 . (5 . ()))))))    ; jak je vidět, je to lineární spojový seznam
(define lb (cons 1 (cons 2 (cons 3 (cons 4 (cons 5 null))))))
(define lc '(1 2 3 4 5))
(define ld (list 1 2 3 4 5))

"Seznamy vytvořené různými způsoby"
la
lb
lc
ld

; Tento seznam se od předchozích liší tím, že obsahuje prvky různých typů
; Všimni si, že stačí kvotovat na začátku výrazu, podvýrazy už se nekvotují.
(define le '(1 2 (3 . 4) (5 6.0 7/2) 8 9 10 a "b c"))
"Také seznam, ale obsahující hodnoty různých typů"
le

; Přístup k jednotlivým prvkům seznamu
; ------------------------------------
; Dělá se opět pomocí funkcí car a cdr.
; Funkce car vrací hlavičku, tedy první prvek seznamu.
; Funkce cdr vrací zbytek seznamu, tedy seznam!
"Hlavička seznamu"
(car la)
"Zbytek seznamu"
(cdr la)

; Tyto funkce nelze použít nad prázdným seznamem, protože prázdný seznam
; není tečkovým párem.
;(car ())
;(car ())

; Pro přístup k dalším prvkům seznamu lze použít kombinace obou funkcí nebo
; zkratkové funkce.
"Druhý prvek seznamu"
(car (cdr la))
(cadr la)
"Třetí prvek seznamu"
(car (cdr (cdr la)))
(caddr la)
"Seznam od třetího prvku dále"
(cdr (cdr la))
(cddr la)

; Přidání prvku na začátek seznamu
; Dělá se pomocí funkce cons.
"Přidání prvku na začátek seznamu"
(cons 6 la)

; Pozor! Takto nejde přidávat na konec seznamu, protože by vznikl
; tečkový pár, jehož první prvek je seznam a druhý je hodnota 6. 
; Taková struktura ovšem není seznamem!
"Toto není seznam"
(cons la 6)

; Predikáty pro testování seznamů a jejich prvků
; ----------------------------------------------
; V podmínkách lze používat tyto predikáty
; (null? s) -- vrací true, když je seznam s prázdný
; (list? s) -- vrací true, když je argument s seznamem
; (pair? p) -- vrací true, když je argument p tečkovým párem
"Predikáty pro testování seznamů"
(null? la)
(list? la)
(pair? la)

