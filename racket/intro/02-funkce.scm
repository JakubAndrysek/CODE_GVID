; Speciální formy
; Jsou to speciální konstrukce zabudované do jazyka, které vypadají jako funkce,
; respektive seznamy, ale pomocí běžných prostředků jazyka Scheme by je napsat nešlo,
; protože dělají speciální věci.

; Speciální forma define
; ======================

; Pojmenované hodnoty
; -------------------
; Pomocí formy define lze pojmenovat primitivní výraz (hodnotu), abychom se na
; něj mohli dále odkazovat jménem.
(define Pi 3.1415982)

; Nyní můžeme použít hodnotu Pi
"Použití hodnoty Pi"
Pi

; Pojmenované výrazy
; ------------------
; Někdy je užitečné pojmenovat celý výraz, abychom jej nemuseli opakovaně opisovat
(define Soucet-cifer (+ 2 5 3 2 0 1 6))

; Výraz opět lze použít a to i opakovaně - pokaždé se znovu vyhodnotí
"Pojmenovaný výraz - součet cifer"
Soucet-cifer
(/ Soucet-cifer 7)

; Funkce
; ------
; Funkce jsou speciální seznamy vytvořené pomocí formy define.
; Funkce jsou pojmenované výrazy, které mají navíc parametry.

; Struktura konstrukce uživatelské funkce vypadá takto:
; (define
;   (jméno-funkce parametr1 parametr2 atd)
;   (výraz-reprezentující-výsledek-funkce)
;   )

; Jednotlivé parametry lze používat uvnitř výrazu, který je tělem funkce.

; Pozor! Funkce neobsahují nikde příkaz return ani nic podobného! Scheme je
; funkcionální jazyk, proto funkce reprezentuje výraz. Výsledkem funkce je
; tedy výsledek výrazu, který tvoří její tělo. Forma define vlastně slouží
; k pojmenování určitého výrazu tak, aby se dal používat opakovaně.

; Definice funkce na2
; Počítá druhou mocninu zadaného argumentu
(define (na2 x)
  (* x x))

; Volání funkcí
; -------------
; Nyní nestačí použít pouze jméno funkce, musí se volat jako seznam bez uvozovky
; na začátku. Pokud je takto vytvořena funkce bez parametrů, i ona se volá stejně --
; nestačí pak uvést jen jméno, musí být v závorkách.
; Provede se stejně, jako aplikace matematických operátorů, tedy v seznamu je nejprve
; jméno funkce a pak následují argumenty.
"Volání funkce na2"
(na2 124)

; na2(124)    ; Toto je chyba! Zde musí být závorka před jménem funkce!
; (na2 (124)) ; Toto je také chyba, protože parametrem teď není číslo, ale seznam.

; Parametrem funkce může být i operátor nebo jiná funkce
(define (proved2x operace argument)
  (operace (operace argument argument) argument))

"Volání funkce proved2x"
(proved2x + 2) ; (+ (+ 2 2) 2)
(proved2x * 2) ; (* (* 2 2) 2)
;(proved2x na2 2) ; (na2 (na2 2 2) 2) ; tohle teď nejde, protože operace na2 očekává jen jeden argument

; Predikáty
; ---------
; Jsou to funkce, které vrací logickou hodnotu.
; Obvykle se pojmenovávají s otazníkem na konci (ano ve Scheme to jde).
; Predikáty se používají v podmínkách (viz dále).
(define (kladne? x)
  (>= x 0))
(define (zaporne? x)
  (not (kladne? x)))

"Volání predikátu kladne?"
(kladne? 78)
(kladne? -4)

; Speciální forma if
; ==================
; Je to výraz, který vyhodnocuje tři podvýrazy. Pokud je první výraz -- predikát
; pravdivý, vrací výsledek druhého výrazu, jinak vrací výsledek třetího výrazu.
; Poslední výraz nelze standardně vynechat, protože by byl výsledek v některých
; případech nedefinovaný.
; Použití:
; (if predikát výraz-pro-true výraz-pro-false)

"Použití speciální formy if"
(if (kladne? 23)
    (+ 2 3)
    (- 2 3))

; Speciální forma cond
; ====================
; Narozdíl od formy if, dokáže tato forma vyhodnotit libovolné množství
; predikátů. Tvoří ji seznam dvojic predikát - výraz. Celá forma cond
; vrací výsledek výrazu, který je u prvního predikátu, jenž se vyhodnotí
; jako true. Posledním prvkem celého seznamu je dvojice else - výraz.
; Hodnota posledního výrazu je výsledkem celé konstrukce, když žádný
; z předchozích predikátů není pravdivý.
; Schéma zápisu formy cond
; (cond (predikát1 výraz1)
;       (predikát2 výraz2)
;       (predikát3 výraz3)
;       (else výrazN))

; Pozor! Opět nejde o příkaz, ale výraz, který má výslednou hodnotu shodnou
; s hodnotou jednoho z výrazů uvedených u predikátů.
"Použití speciální formy cond"
(define (pocet-cifer x)
  (cond ((zaporne? x) (pocet-cifer -x))
        ((zero? (quotient x 10)) 1)                        ; pozor na závorky
        (else (+ 1 (pocet-cifer (quotient x 10))))))

"Použití formy cond ve funkci pocet-cifer"
(pocet-cifer 0)
(pocet-cifer 2)
(pocet-cifer 20)
(pocet-cifer 178)

; Tato speciální forma se obvykle používá v rekurzivních funkcích, které mají
; více než jednu koncovou podmínku.

; Speciální forma begin
; =====================
; Funkcionální jazyk obvykle nepoužívá sekvenci příkazů, jako to dělají imperativní
; jazyky. Někdy se to ale hodí. Speciální forma begin umožňuje poskládat výrazy
; do sekvence a postupně je vyhodnocovat zleva doprava. Výsledkem formy begin je
; výsledek vyhodnocení posledního výrazu v sekvenci.
; Schéma zápisu formy begin
;(begin
;  (výraz-1)
;  (výraz-2)
;  (výraz-3))

; Rekurze
; -------
; Rekurzivní funkce používá ve svém těle sebe samu.
; Skládá se z primitivních případů (koncová podmínka rekurze) a rekurzivních případů
; (rekurzivních volání).
(define (faktorial x)
  (if (zero? x)
      1
      (* x (faktorial (- x 1)))))
"Volání funkce faktorial"
(faktorial 5)
(faktorial 1283)

; Nezapomínejte, že každé volání funkce způsobí vyhrazení prostoru na zásobníku.
; Scheme umí pracovat s obrovskými čísly, ale potřebuje pro ně paměť. Pokud bychom
; volali funkci faktorial s příliš velkými parametry, způsobí to vyčerpání paměti
; a může to způsobit zaseknutí nebo havárii operačního systému.
