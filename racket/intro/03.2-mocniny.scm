(require racket/trace)

; even? sud
; odd? - lichy
; remainder - zbytek po deleni

"B na N (normalni rekurze)"
(define (mocnina b n)
  (if (= n 0)
      1
      (* b (mocnina b (- n 1)))))

;(trace mocnina)
(mocnina 2 64)


"B na N pomoci TR (koncove rekurze)"
(define (tr-mocnina b n end)
  (if (= n 0)
      end
      (tr-mocnina b (- n 1) (* b end))))

; Mocnina koncovou rekurzi - helper
(tr-mocnina 2 3 1)

"B na N pomoci TR (koncove rekurze) - helper"
(define (mocnina-t b n)
  (tr-mocnina b n 1))

; Mocnina koncovou rekurzi - helper
(mocnina-t 2 3)


"na druhou"
(define (na-druhou a)
  (* a a))

; pouziti na
(na-druhou 2)


"na druhou a pote MODulo"
(define (na-druhou-mod a mod)
  (remainder (* a a) mod))

(na-druhou-mod 6 10)
; 6*6 = 36 | 36 mod 10 = 6



"na druhou s LOGaritmickou slozitosti"
; v kazdem kroku se zmensi pocet operaci na polovinu
(define (mocnina-log b n)
  (if (= n 0)
      1
      (if (even? n)
          (na-druhou (mocnina-log b (/ n 2)))
          (* b (mocnina-log b (- n 1))))))


(trace mocnina-log)
(mocnina-log 3 9)


; modularni aritmetika
; kouknem na hodiny 55 min + 20 min = 15 min (modulo 60)

"na druhou s LOGaritmickou slozitosti - v kazdem kroku MODulo "
(define (mocnina-log-mod b n mod)
    (if (= n 0)
      1
      (if (even? n)
          (na-druhou-mod (mocnina-log-mod b (/ n 2) mod) mod) ; pokud je sude -> (b^(n/2))^2
          (remainder (* b (mocnina-log-mod b (- n 1) mod)) mod)))) ; pokud je liche -> b * (b)^n-1

(trace mocnina-log-mod)
(mocnina-log-mod 3 9 100)

; https://www.wolframalpha.com/input?i=125031%5E7230179909825+mod+177
(mocnina-log-mod 125031 7230179909825 177); = 33


; https://www.wolframalpha.com/input?i=979653126%5E65432156463644423005210104161+mod+10000
(mocnina-log-mod 979653126 65432156463644423005210104161 10000); = 9376