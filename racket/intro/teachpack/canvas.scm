;;;;;
;;;;;  Simple Canvas Library TeachPack
;;;;;  Vilem Vychodil, David Skoupil
;;;;;
;;;;;  DO NOT MODIFY THIS FILE
;;;;;  USE Language/Teachpack to add use this file

#cs#cs(module canvas mzscheme
        
        (require (lib "graphics.ss" "graphics")
                 (lib "class.ss") 
                 (lib "mred.ss" "mred")
                 )
        
        (provide 
         graphics-init
         graphics-move-to
         graphics-line-to
         graphics-line
         graphics-polyline
         graphics-rectangle
         graphics-done
         graphics-clear
         graphics-click
         graphics-cross
         
         BLACK
         BLUE
         GREEN
         CYAN 
         RED
         MAGENTA
         YELLOW
         GRAY 
         WHITE
         )
        
        ;; undefined procedure
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
                 (border (if (null? init-border) 0 (car init-border)))
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
                    (lambda () 
                      (let ((posn (mouse-click-posn (get-mouse-click viewport))))
                        (cons (posn-x posn) (posn-y posn)))))
              
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
        )