; Hanojské věže
; Hanojské věže jsou starou Vietnamskou úlohou s těmito pravidly.
; - Existují tři věže (trny) tvořené disky s různým průměrem.
; - Lze položit menší disk na větší disk.
; - Nelze pololožit větší disk na menší disk.
; - V jednom kroku lze vzít z libovolné věže jediný disk a položit jej na
;   jinou věž, na jejímž vrcholu není menší disk než přesouvaný.
; - Na začátku tvoří všechny disky první věž.
; - Úkolem je přesunout všechny disky z první věže na třetí věž za pomoci
;   druhé věže.

; Odhadněte, jakou časovou složitst tato úloha má.
; Nápověda: Podle legendy stavějí tyto věže mniši v jednom Vietnamském klášteře.
; Až se jim povede přesunout věž vysokou 64 disků, nastane konec světa.



; Řešení v jazyce Scheme
; 1. V aktuálním adresáři musí být adresář teachpack se souborem hanoi.scm
;    - to je pomocný modul pro kreslení Hanojských věží

; 2. Pokud máš zapnut jazyk Pretty Big, je třeba tento teachpack natáhnout
;    pomocí procedury require
(require "teachpack/hanoi.scm" )

; 3. Modul poskytuje tyto procedury
;(init-window 4)  ; Inicializuje okno pro tři věže s N disky.
;(init-towers 4)  ; Inicializuje tři věže s N disky. Věže mají čísla 1, 2, 3.
;(move 1 3)       ; Přesune horní disk z věže 1 na věž 3
;(move 1 2)       ; Přesune horní disk z věže 1 na věž 2
;(fast-move 3 2)  ; Dělá totéž, co move, ale rychle, takže to lze použít pro
;                 ; řešení úlohy s větším počtem disků.
;(move 1 2)       ; Tento tah není možný, proto funkce vrací false. V předchozích
;                 ; případech vracela true.

(define (hanoi n a b c)
  ; n > 0
  (if (> n 0)
      (begin        
        (hanoi (- n 1) a c b) ;skp
        (move a c)
        (hanoi (- n 1) b a k)
        ;hanoi psk
        )
      "konec")
    )
  )


(define (run-hanoi n)
  (begin
    (init-window n)
    (init-towers n)

    (hanoi n 1 2 3)))

(run-hanoi 4)


