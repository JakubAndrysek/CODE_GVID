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
;(define (tr-fibonaci x pom)
;  (if (<= x 0)
;      pom


;(tr-fibonaci 5 0)


;perrin numbers
(define (perr x)
  (if (= x 3)
      0
      (if (= x 0)
          1
          (if (<= x 2)
              2
              (+ (perr (- x 2)) (perr (- x 3)))))))

(perr 6)