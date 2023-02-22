; Budeme používat jazyk Scheme (Racket).
; (Hlavně proto, že pro výuku používám teachpacky pro Scheme, ne pro Racket)
; 1. Jak zapnout jazyk Scheme:
;  a) zvol jazyk Language - Choose language... - Other languages - Pretty Big
;  b) stiskni tlačítko Run -> v běhovém okně se objeví nápis Language: Pretty Big

; 2. Programy nyní zapisuj do editačního okna. Nezapomeň na začátku založit nový
;    soubor: File - Save Definitions As...
;    Pro programy v jazyku Scheme se používají koncovky souborů .scm, .ss, .rkt

; Základy jazyka
; Scheme je funkcionální jazyk vycházející z jazyka LISP. Koncept funkcionálního
; programování je odlišný od imperativního programování. Základem tohoto konceptu
; jsou výrazy, funkce a rekurze. Funkcionální programování neznamená pouze to,
; že se zde používají funkce. V jazyce C lze používat funkce, ale funkcionální
; jazyk to není!
; Novější verze jazyka Scheme se nazývá Racket.

; REPL - read-eval-print loop
; Je to interpretovaný jazyk. Funguje na principu REPL, program se tedy vykonává
; tak, že se každý řádek přečte, vyhodnotí a rovnou se vytiskne výsledek. To se
; opakuje až do konce vstupu (při práci v interaktivním okně) nebo zdrojového
; souboru (máme-li program zapsán jako skript v souboru).

; Výrazy
; Každý program ve Scheme JE výrazem. Je-li na řádku výraz, po spuštění se
; vyhodnotí a jeho výsledek se zapíše na výstup. Existují různé druhy výrazů:

; Primitivní výrazy
;   - nelze je již zjednodušit,
;   - jsou samy výsledkem
;   - představují hodnoty jednoduchých typů
;   Existují 2 druhy primitivních výrazů:
;   1. čísla
;      - vyhodnocují se na svou hodnotu
;   2. symboly
;      - vyhodnocují se na svou aktuální vazbu (co představují)
;      - některé mají implicitní vazbu - typicky operátory (např. symboly +, -)
;      - některým vazbu přidělíme speciální formou define - typicky identifikátory
;        (jména funkcí, pojmenované výrazy)
;      - většina symbolů žádnou vazbu nemá

; Jsi-li v prostředí DrRacket, je vhodná chvíle stisknout tlačítko Run.

"Toto jsou příklady primitivních výrazů"
158     ; celé číslo -- lze pracovat i s obrovskými celými čísly, třeba o 1000 cifrách
127/100 ; zlomek -- ano, Scheme umí pracovat s racionálními čísly!
1.27    ; desetinné číslo
"Ahoj"  ; textový řetězec
true    ; logická hodnota true -- v některých interpretech nemusí fungovat
#t      ; logická hodnota true - funguje všude
false   ; logická hodnota true -- v některých interpretech nemusí fungovat
#f      ; logická hodnota true - funguje všude
'a      ; symbol - uvozovka (quote) zabrání vyhodnocení symbolu
'symbol ;
; a     ; => a: undefined; cannot reference an identifier before its definition

; Seznamy
; Seznam je jedním z nejdůležitějších typů výrazů v jazyce Scheme.
; - Je to jediný prostředek pro kombinaci primitivních výrazů v jazyce Scheme/Racket.
; - Seznam se tvoří pomocí kulatých závorek.
; - Prvky seznamu se oddělují mezerami.
; - Prvky seznamu mohou být výrazy různých typů.
; - Seznam může obsahovat prvky různých typů, jak primitivní výrazy, tak i seznamy.
; - Seznam může být prázdný ().
; - Má-li být seznam použit jako hodnota, musí se před něj napsat uvozovka.

"Příklady výrazů -- seznamů"
'()                ; prázdný seznam
'(1)               ; jednoprvkový seznam
'(())              ; taky jednoprvkový seznam
'(1 (1) () "ahoj") ; 4 prvkový seznam

; Vyhodnocované seznamy
; - Pokud se před seznamem nenapíše uvozovka, dojde k jeho vyhodnocení.
; - Očekává se, že prvním prvkem seznamu je název funkce a další prvky jsou
;   jejími argumenty. Pokud tomu tak není, dojde k chybě.
; - Funkcemi jsou i různé matematické operátory, jako +, -, *, / atd.
; - Matematické výrazy se proto zapisují v tzv. preorder notaci, tedy nejdříve
;   operátor, pak jeho operandy.
; - Matematické operátory mohou mít i více než dva operandy
"Součet, rozdíl, násobení"
(+ 1 2)          ; 1 + 2
(- 1 2 3 4 -5)   ; 1 - 2 - 3 - 4 - -5
(* 2 3 -1)       ; 2 * 3 * -1
; Reálné dělení se snaží zachovat co nejpřesnější výsledek
; Pokud to jde, je výsledek celočíselný, když to nejde, zkusí racionální zlomek
; a teprve v nezbytných případech přepne na desetinná čísla.
"Reálné dělení"
(/ 12 3 2)       ; (12 / 3) / 2
(/ 10 2 2)       ; (10 / 2) / 2
(/ 10 2.0)       ; 10 / 2.0
"Celočíselné dělení"
(quotient 17 3)   ; 17 / 3  celočíselné dělení

"Modulo - zbytek po celočíselném dělení"
(remainder 17 3) ; 17 mod 3 -- zbytek po dělení
(remainder -17 3) ; -17 mod 3 -- zbytek po dělení
(remainder 17 -3) ; 17 mod -3 -- zbytek po

; Výrazy s podvýrazy
; Operandy mohou být i složitějšími výrazy.
"Příklad výrazu s podvýrazy"
; (5 + 1/3)*(5 - (-11 + 6)) / (3 + (2 / 3))
(/ (* (+ 5 1/3) (- 5 (+ -11 6))) (+ 3 (/ 2 3))) ; výsledek je 14 + 6/11
; Pozor! Zde se nesmí používat nadbytečné závorky!
;(+ 1 (2) 3)     ; tohle je chyba - (2) je seznam, ne číslo
(/
 (* 7 (+ 1 5.8))
 (* 4 (- 2.51 2.34)))

(/
 (+ 5 14/3 (- 2 (- 3 (- 6 4/3))))
 (* (- 1 2/3) (- 2 6)))
; Čistý výraz
; - Nevykonává žádné přiřazovací operace.
; - Nevykonává žádné vedlejší efekty (tisk, grafický výstup apod.)
; => Hodnota výrazu nezávisí na pořadí vyhodnocení podvýrazů.
; => výraz lze vyhodnocovat paralelně

; Referenční transparentnost
; - V daném kontextu je nahrazení podvýrazu jeho hodnotou úplně
;   nezávislé na výrazu, ve kterém se to děje.
; (+ 2 3) ===> 5
; (* (+ 2 3) (+ 2 3) ===> (* 5 5) ===> 25

; Redukce výrazů
; - postupné nahrazování složitějších výrazů jednoduššími ekvivalenty
; - hodnota výrazu -> nejjednodušší ekvivalentní forma výrazu ->
;   -> normální (kanonická) forma

; Reprezentace výrazu stromem => větve lze zpracovávat paralelně

; (* (+ (* 2 a) 1)
;    (+ (* 2 a) b))
;           ||
;           \/
;           *
;        /    \
;      +       +
;     / \     / \
;    *   1   *   b
;   / \     / \
;  2   a   2   a

; Výpočet programu = redukce programu na normální formu
