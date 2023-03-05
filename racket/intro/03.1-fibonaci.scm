(require racket/trace)
; Fibonaci
; zadani

; 0 = 0
; 1 = 1
; Fib

; Fibonaci normalni rekurze
; kontrola 
(define (fibonaci x)
  (if (<= x 0)
      0
      (if (<= x 1)
          1
          (+ (fibonaci (- x 2)) (fibonaci (- x 1))))))
      
(fibonaci 10)

;(trace fibonaci)
;(fibonaci 10)



; Fibonaci koncova rekurze
(define (tr-fibonaci x left right)
  (if (<= x 0)
      0
      (if (<= x 1)
          right
          (tr-fibonaci (- x 1) right (+ left right)))))

(tr-fibonaci 10 0 1)


; Fibonaci helper
(define (fibonaci-t x)
  (tr-fibonaci x 0 1))

"Fibonaci 1234"
(fibonaci-t 1234)
;Vysledek = 347746739180370201052517440604335969788684934927843710657352239304121649686845967975636459392453053377493026875020744760145842401792378749321113719919618588095724485583919541019961884523908359133457357334538791778480910430756107407761555218113998374287548487



;Perrinovy cisla
(define (perr x)
  (if (= x 0)
      3
      (if (= x 1)
          0
          (if (<= x 2)
              2
              (+ (perr (- x 2)) (perr (- x 3)))))))
"Perrin"
(perr 8)


; Perrinovy cisla - koncova rekurze
(define (perr-tr x a b c)
   (if (= x 0)
       a
       (perr-tr (- x 1) b c (+ a b))))
       

;(require racket/trace)
;(trace perr-tr)
;(perr-tr 8 3 0 2)

(define (perrin-t x)
  (perr-tr x 3 0 2))

(perrin-t 8)
