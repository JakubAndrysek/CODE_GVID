;;;;;
;;;;;  Towers of Hanoi TeachPack
;;;;;  Vilem Vychodil, David Skoupil
;;;;;
;;;;;  DO NOT MODIFY THIS FILE
;;;;;  USE Language/Teachpack to add use this file; Towers of Hanoi

#cs#cs(module hanoi mzscheme
        
        (require (lib "graphics.ss" "graphics")
                 (lib "class.ss") 
                 (lib "mred.ss" "mred")
                 )
        (provide init-window
                 init-towers
                 clear-window
                 move
                 fast-move)
        
        ;;;;;  Simple Canvas Library --------------------------------------------
        
        ;;;; undefined procedure
        (define undefined-f (lambda arg (error "Use init-graphics first.")))
        
        ;; procedure symbol definitions
        (define graphics-move-to undefined-f)
        (define graphics-line-to undefined-f)
        (define graphics-line undefined-f)
        (define graphics-polyline undefined-f)
        (define graphics-rectangle undefined-f)
        (define graphics-done undefined-f)
        (define graphics-clear undefined-f)
        (define graphics-click undefined-f)
        (define graphics-cross undefined-f)
        
        ;; color definition
        (define BLACK (make-rgb 0 0 0))
        (define BLUE (make-rgb 0 0 0.5))
        (define GREEN (make-rgb 0 0.5 0))
        (define CYAN (make-rgb 0 0.5 0.5))
        (define RED (make-rgb 0.5 0 0))
        (define MAGENTA (make-rgb 0.5 0 0.5))
        (define YELLOW (make-rgb 0.5 0.5 0))
        (define GRAY (make-rgb 0.5 0.5 0.5))
        (define WHITE (make-rgb 1 1 1))
        
        ;; intialization of graphics interface
        (define (graphics-init width height minx miny maxx maxy . init-border)
          (let* ((viewport #f)
                 ; border
                 (border (if (null? init-border) 16 (car init-border)))
                 ; cross size
                 (cross-size 4)
                 ; cross color
                 (cross-color (make-rgb 0.75 0.2 0.2))
                 ; default color
                 (default-color (make-rgb 0 0 0))
                 ; get specified color or default color 
                 (get-color (lambda (color)
                              (cond ((null? color) default-color)
                                    ((symbol? (car color))
                                     (if (send the-color-database find-color (symbol->string (car color)))
                                         (send the-color-database find-color (symbol->string (car color)))
                                         default-color))
                                    ((string? (car color))
                                     (if (send the-color-database find-color (car color))
                                         (send the-color-database find-color (car color))
                                         default-color))
                                    (else (car color)))))
                 ; window transformation
                 (model->viewport (lambda (x w min max)
                                    (+ (* w (/ (- x min) (- max min))) border)))
                 ; window transformation
                 (size->viewport (lambda (x w min max)
                                   (* w (/ x (- max min)))))
                 ; first position
                 (last-pos (make-posn 
                            (model->viewport 0 width minx maxx)
                            (model->viewport 0 height maxy miny)))
                 ; general drawing procedure
                 (draw (lambda (x y line? color)
                         (let ((real-last-pos last-pos))
                           (begin
                             (set! last-pos
                                   (make-posn (model->viewport x width minx maxx)
                                              (model->viewport y height maxy miny)))
                             (if line? ((draw-line viewport)
                                        real-last-pos last-pos (get-color color))))))))
            (begin
              (open-graphics)
              
              ; window initialization
              (set! viewport 
                    (open-viewport "DrScheme Canvas"
                                   (+ width (* 2 border)) (+ height (* 2 border))))
              
              ; clear window
              (set! graphics-clear
                    (lambda ()
                      ((clear-viewport viewport))))
              
              ; wait for mouse click
              (set! graphics-click 
                    (lambda () (get-mouse-click viewport)))
              
              ; close graphics
              (set! graphics-done
                    (lambda () 
                      (begin 
                        (close-viewport viewport)
                        (close-graphics)
                        (set! graphics-move-to undefined-f)
                        (set! graphics-line-to undefined-f)
                        (set! graphics-line undefined-f)
                        (set! graphics-polyline undefined-f)
                        (set! graphics-done undefined-f)
                        (set! graphics-clear undefined-f))))
              
              ; draw line from -- to
              (set! graphics-line (lambda (x1 y1 x2 y2 . color)
                                    (begin
                                      (draw x1 y1 #f color)
                                      (draw x2 y2 #t color))))
              
              ; draw cross representing current point
              (set! graphics-cross 
                    (lambda ()
                      (define (simple-draw x y x1 y1 inc-x inc-y)
                        ((draw-line viewport) 
                         (make-posn (+ x1 x) (+ y1 y))
                         (make-posn (+ inc-x x) (+ inc-y y))
                         cross-color))
                      (let ((x (posn-x last-pos))
                            (y (posn-y last-pos)))
                        (simple-draw x y 0 1 0 (+ 1 cross-size))
                        (simple-draw x y 1 0 (+ 1 cross-size) 0)
                        (simple-draw x y 0 -1 0 (- -1 cross-size))
                        (simple-draw x y -1 0 (- -1 cross-size) 0))))
              
              ; draw line, arguments are dotted pairs of coordinates
              (set! graphics-polyline 
                    (lambda args
                      (let* ((len (length args))
                             (last (if (and (> len 0)
                                            (not (pair? 
                                                  (list-ref args (- len 1)))))
                                       (list (list-ref args (- len 1)))
                                       ())))
                        (if (and (not (null? args))
                                 (or (not (null? last))
                                     (not (null? (cdr args)))))
                            (begin
                              (draw (caar args) (cdar args) #f last)
                              (for-each (lambda (pos)
                                          (draw (car pos) 
                                                (cdr pos) #t last))
                                        (cdr args)))))))
              
              ; move-to, line-to -- turtle
              (set! graphics-move-to (lambda (x y . color) (draw x y #f color)))
              (set! graphics-line-to (lambda (x y . color) (draw x y #t color)))
              
              ; draw rectangle
              (set! graphics-rectangle
                    (lambda (x y rw rh solid? . color)
                      (let ((x0 (model->viewport x width minx maxx))
                            (y0 (model->viewport y height maxy miny))
                            (w0 (model->viewport (+ x rw) width minx maxx))
                            (h0 (model->viewport (+ y rh) height maxy miny)))
                        ((if solid?
                             (draw-solid-rectangle viewport)
                             (draw-rectangle viewport))
                         (make-posn (min x0 w0) (min y0 h0))
                         (abs (- x0 w0))
                         (abs (- y0 h0))
                         (get-color color)))))
              
              )))
        
        ;; Tower of Hanoi library ----------------------------------------------
        
        (define move #f)
        (define fast-move #f)
        
        (define (init-window n)
          (graphics-init 640 160 0 1 3 (+ n 1)))
        
        (define (clear-window)
          (graphics-clear))
        
        (define (init-towers n)
          (define (range n)
            (if (<= n 0)
                ()
                (cons n (range (- n 1)))))
          (let ((needle (vector (range n) () ())))
            (begin
              (define (move-disk from to)
                (define (safe-car n)
                  (let ((lst (vector-ref needle n)))
                    (if (null? lst)
                        -10
                        (car lst))))
                (define (pop n)
                  (vector-set! needle n
                               (cdr (vector-ref needle n))))
                (define (push n val)
                  (vector-set! needle n
                               (cons val (vector-ref needle n))))
                (let ((moved (safe-car from))
                      (top (safe-car to)))
                  (if (> moved top)
                      (begin
                        (pop from)
                        (push to moved)
                        #t)
                      #f)))
              (define (completed? n)
                (and
                 (= 0 (length (vector-ref needle 0)))
                 (= n (apply max
                             (map (lambda (i)
                                    (length (vector-ref needle i)))
                                  '(0 1 2)))))))
            (define (initialize-towers)   
              (for-each (lambda (x) (set-disk 0 x x (brick-color x))) (range n))
              (for-each (lambda (x) 
                          (remove-disk 1 (- x 1) x)
                          (remove-disk 2 (- x 1) x)
                          (range n))
                        (range n)))
            (define disk-width 0.016)
            (define (brick-color x)
              (make-rgb 0.5 0 (+ 0.3 (* (/ 0.5 n) x))))
            (define (remove-disk slot h size)
              (set-disk slot (+ h 1) size WHITE)
              (graphics-rectangle (+ (- 0.5 disk-width) slot) 
                                  (+ h 1)
                                  (* 2 disk-width)
                                  1 
                                  #t BLACK))
            (define (set-disk slot h size color)
              (graphics-rectangle (+ 0.5 slot (- (* (+ 1 (- n size)) (/ 0.4 n))))
                                  h
                                  (* 2 (* (+ 1 (- n size)) (/ 0.4 n)))
                                  1 
                                  #t color)
              (if (not (equal? color WHITE))
                  (graphics-rectangle (+ 0.5 slot (- (* (+ 1 (- n size)) (/ 0.4 n))))
                                      h
                                      (* 2 (* (+ 1 (- n size)) (/ 0.4 n)))
                                      1 
                                      #f BLACK)))
            (define (display-disks from to)
              (remove-disk from
                           (length (vector-ref needle from))
                           (car (vector-ref needle to)))
              (set-disk to 
                        (length (vector-ref needle to))
                        (car (vector-ref needle to)) 
                        (brick-color (car (vector-ref needle to)))))
            
            (set! move (lambda (from to)
                         (if (or (< from 1) (< to 1) (> from 3) (> to 3)) #f  
                             (let ((rval #f) 
                                   (from (- from 1)) (to (- to 1))) 
                               (begin 
                                 (set! rval (move-disk from to))
                                 (if rval (display-disks from to))
                                 (sleep 1)
                                 rval)))))
            
             (set! fast-move (lambda (from to)
                         (if (or (< from 1) (< to 1) (> from 3) (> to 3)) #f  
                             (let ((rval #f) 
                                   (from (- from 1)) (to (- to 1))) 
                               (begin 
                                 (set! rval (move-disk from to))
                                 (if rval (display-disks from to))
                                 rval)))))
            
            (initialize-towers)))
        
        )
   