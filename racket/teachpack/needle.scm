;;;;;
;;;;;  Buffons needle TeachPack
;;;;;  David Skoupil
;;;;;
;;;;;  DO NOT MODIFY THIS FILE
;;;;;  USE Language/Teachpack to add use this file

#cs#cs(module needle mzscheme
        
        (require (lib "graphics.ss" "graphics")
                 (lib "class.ss") 
                 (lib "mred.ss" "mred")
                 )
        (provide initialize
                 drop-once
                 erase
                 )
        
        
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
        
        ;; Turtle library ----------------------------------------------
        
        
        ;; degrees to radians conversion
        (define pi (* 4 (atan 1)))
        (define (deg2rad deg) (* (/ deg 180) pi))
        (define (rad2deg rad) (* (/ rad pi) 180))
        
        ;; polar to carteesian coordinates conversion
        (define (polar-x angle mag) (* mag (cos (deg2rad angle))))
        (define (polar-y angle mag) (* mag (sin (deg2rad angle))))
        
        ;; initialization
        (define init-playground #f)
        (define erase-playground graphics-clear)
        
        ;; turtle movement procedures definition - low level
        (define line-to #f)
        (define move-to #f)
        
        ;; turtle movement procedures definition - high level
        (define forward #f)
        (define backward #f)
        (define jump-forward #f)
        (define jump-backward #f)
        (define left #f)
        (define right #f)
        (define remember #f)
        (define return #f)
        
        ;; turtle direct control and accessors
        (define set-turtle #f)
        (define turtle-x #f)
        (define turtle-y #f)
        (define turtle-angle #f)
        (define playground-size #f)
        
        ;; turtle graphics implementation
        (letrec ((last-x 0) (last-y 0) (last-angle 90) (p-size 0) (stack '())
                            (turtle-draw
                             (lambda (proc angle mag color)
                               (let* ((new-angle (+ last-angle angle))
                                      (new-x (+ last-x (polar-x new-angle mag)))
                                      (new-y (+ last-y (polar-y new-angle mag))))
                                 (apply proc 
                                        (append (list new-x new-y) color))
                                 (set! last-x new-x)
                                 (set! last-y new-y)
                                 (set! last-angle new-angle)))))
          (set! line-to 
                (lambda (angle mag . color) 
                  (turtle-draw graphics-line-to angle mag color)))
          (set! move-to 
                (lambda (angle mag . color) 
                  (turtle-draw graphics-move-to angle mag color)))
          (set! forward
                (lambda (mag . color) 
                  (turtle-draw graphics-line-to 0 mag color)))
          (set! backward
                (lambda (mag . color) 
                  (turtle-draw graphics-line-to 0 (- mag) color)))
          (set! jump-forward
                (lambda (mag) 
                  (turtle-draw graphics-move-to 0 mag '())))
          (set! jump-backward
                (lambda (mag) 
                  (turtle-draw graphics-move-to 0 (- mag) '())))
          (set! left
                (lambda (angle) 
                  (turtle-draw graphics-move-to angle 0 '())))
          (set! right
                (lambda (angle) 
                  (turtle-draw graphics-move-to (- angle) 0 '())))
          (set! init-playground
                (lambda (size . display-size)
                  (set! p-size size)
                  (if (null? display-size)
                      (graphics-init 600 600 (- size) (- size) size size 0)
                      (graphics-init (car display-size) (cadr display-size) (- size) (- size) size size 0))))
          (set! set-turtle
                (lambda (x y angle)
                  (set! last-x x)
                  (set! last-y y)
                  (set! last-angle (+ (modulo (- (inexact->exact (round angle))) 360) 90))
                  (graphics-move-to last-x last-y)))
          (set! remember
                (lambda ()
                  (set! stack 
                        (cons (list (turtle-x) 
                                    (turtle-y)
                                    (turtle-angle))
                              stack))))
          (set! return
                (lambda ()
                  (if (not (null? stack))
                      (let ((pos (car stack)))
                        (set-turtle (car pos) (cadr pos) (caddr pos))
                        (set! stack (cdr stack))))))
          (set! turtle-x
                (lambda ()
                  last-x))
          (set! turtle-y 
                (lambda ()
                  last-y))
          (set! turtle-angle
                (lambda ()
                  (modulo (round (- (- last-angle 90))) 360)))
          (set! playground-size
                (lambda () 
                  p-size)))
        
        (define (random-number a b)
          (let ((x (random 1000000)))
            (+ a (* x (/ (- b a) 1000000)))))
        
        (define (deg->rad angle)
          (* (/ angle 360) 2 pi))
        
        (define (initialize)
          (init-playground 1.5)
          (set-turtle -1.5 -0.5 90)
          (forward 3)
          (set-turtle -1.5 0.5 90)
          (forward 3))
        
        (define drop-once #f)
        (define (erase)
          (erase-playground))
        
        (let ((last-set #f)
              (last-x #f)
              (last-y #f)
              (last-angle #f))
          (set! drop-once
                (lambda ()
                  (if last-set 
                      (begin
                        (set-turtle -1.5 -0.5 90)
                        (forward 3)
                        (set-turtle -1.5 0.5 90)
                        (forward 3)
                        (set-turtle last-x last-y last-angle)
                        (forward 1 "LightGray")))              
                  (let ((x (random-number -0.5 0.5))
                        (y (random-number -0.5 0.5))
                        (angle (random-number 0 360)))
                    (set-turtle x y angle)
                    (set! last-x x)
                    (set! last-y y)
                    (set! last-angle angle)
                    (set! last-set #t)
                    (forward 1 "DarkRed")
                    (sleep 0.02)
                    (or (> (turtle-y) 0.5)
                        (< (turtle-y) -0.5))))))
        )