; Kreslení fraktálů

; Teachpack turtle - modul pro želví grafiku.
; V adresáři teachpack musí být soubor turtle.scm.
(require "teachpack/turtle.scm")

; Seznam operací, které modul turtle poskytuje
; --------------------------------------------
;(init-playground size); Inicializuje kreslící plochu o rozměru N.
;(erase-playground)    ; Vymaže kreslící plochu.
;(close-playground)    ; Zavře kreslící plochu.
;
;(set-turtle x y uhel) ; Postaví želvu na souřadnice x, y a otočí ji pod úhlem
;(turtle-x)            ; Vrací x souřadnici želvy.
;(turtle-y)            ; Vrací y souřadnici želvy.
;(turtle-angle)        ; Vrací úhel natočení želvy.
;(playground-size)     ; Vrací velikost kreslící plochy.
;
;(forward delka barva) ; Želva ujde vzdálenost delka a za sebou kreslí čáru
;                      ; danou barvou. Barva není povinný parametr. Implicitně
;                      ; kreslí černou čáru.
;(backward delka)      ; Želva kreslí pozpátku. Barva není povinná.
;(jump-forward delka)  ; Želva skočí dopředu, ale nic nenakreslí.
;(jump-backward delka) ; Želvy ninja umí skákat i dozadu.
;(left uhel)           ; Otočí želvu na místě o daný úhel doleva.
;(right uhel)          ; Otočí želvu na místě o daný úhel doprava.
;(remember)            ; Uloží aktuální pozici a úhel želvy do zásobníku.
;(return)              ; Vybere ze zásobníku poslední pozici a úhel želvy a položí
;                      ; ji na ni.
;(make-rgb r g b)      ; Vyrobí barvu po RGB složkách (desetinná čísla <0, 1>).


(define (rand-between a b)
  (+ a (random-real (- b a))))

(define (rand+- a b)
  (if (zero? b)
      a
      (+ (- a b) (random-real (* 2 b)))))

; L systemy
(define (plevel n size)
  (if (> n 0)
      (begin
        (remember)
        (forward size)
        (left 20);(left (rand+- 20 10))
        (plevel (- n 1) (* size 0.5))
        (right 40); (right (rand+- 40 10))
        (plevel (- n 1) (* size 0.5))
        (return))
      0))


(define (trava )

(init-playground 500)
(set-turtle 0 -450 0)
(plevel 10 450)
;(set-turtle 0 -450 0)
;(plevel 5 450 40)
;(set-turtle 0 -450 0)
;(plevel 5 450 40)
