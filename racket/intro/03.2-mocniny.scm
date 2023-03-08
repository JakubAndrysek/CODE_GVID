(require racket/trace)

; even? sud
; odd? - lichy
; remainder - zbytek po deleni

; b na n
(define (mocnina b n)
  (if (= n 0)
      1
      (* b (mocnina b (- n 1)))))

(mocnina 2 64)

;(define (tr-mocnina b n l)
;  (if (= n 0)
      


"na druhou"
(define (pow a)
  (* a a))

(pow 2)



"na druhou MOD"
(define (pow-mod a mod)
  (remainder (* a a) mod))

(pow-mod 4 2)



"Na druhou s LOGaritmickou slozitosti"
(define (log-pow b n)
  (if (= n 0)
      1
      (if (even? n)
          (pow (log-pow b (/ n 2)))
          (* b (log-pow b (- n 1))))))


;(trace log-pow)
(log-pow 2 3)



(define (expmod b n mod)
    (if (= n 0)
      1
      (if (even? n)
          (pow-mod (log-pow b (/ n 2)) mod)
          (* b (log-pow b (- n 1))))))

(expmod 125031 7230179909825 177)

; pekne cislo

; 4 ciferne
  

; modularni aritmetika
; kouknem na hodiny 55 min + 20 min = 15 min (modulo 60)