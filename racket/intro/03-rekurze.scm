; Rekurze
; -------
; Rekurzivní funkce používá ve svém těle sebe samu.
; Skládá se z primitivních případů (koncová podmínka rekurze) a rekurzivních případů
; (rekurzivních volání).
(define (faktorial x)
  (if (<= x 0)
      1
      (* x (faktorial (- x 1)))))
"Volání funkce faktorial"
(faktorial 7)
;(faktorial 700) ; tohle se ještě spočítá

; Nezapomínej, že každé volání funkce způsobí vyhrazení prostoru na zásobníku.
; Scheme umí pracovat s obrovskými čísly, ale potřebuje pro ně paměť. Pokud bychom
; volali funkci faktorial s příliš velkými parametry, způsobí to vyčerpání paměti
; a může to způsobit zaseknutí nebo havárii operačního systému.

; Ladění
; ------
; 1. Použij místo tlačítka Run tlačítko Debug. 
; 2. Teď tlačítkem Step krokuj postup výpočtu programu.
;    - v okně Stack můžeš sledovat stav zásobníku při volání funkcí
; 3. Zarážka - Go
;    - přejeď myší přes kteroukoli závorku s výrazem a objeví se na ní puntík
;    - pravým tlačítkem myši teď nastav pauzu (breakpoint) na tuto závorku
;    - tlačítkem Go spusť výpočet
;    - výpočet se zastaví na nejbližší zarážce, kterou máš nastavenu
; 4. Stop
;    - až tě přestane ladění bavit, zastav jej tlačítkem Stop

; Zkus si teď tímto postupem krokovat výpočet funkce faktorial.

; Trasování
; ---------
; Trasování slouží ke sledování průběhu výpočtu zejména u rekurzivních funkcí.
; Nejprve natáhneme knihovnu pro trasování funkcí.
(require racket/trace)

; Teď lze používat funkci trace. Řekneme jí, že chceme sledovat funkci faktorial.
(trace faktorial)

; Teď sleduj, co to udělá na výstupu.
"Trasování funkce faktorial"
(faktorial 7)


; Koncová rekurze
; ---------------
; Funkce faktorial je pomalá a nebezpečná, protože může vypotřebovat paměť počítače.
; Faktoriál se dá počítat i cyklem. Je to efektivnější, protože se nespotřebovává
; zásobník. Ve funkcionálním jazyce se ale cykly dělají pomocí rekurze!
; Koncová rekurze jde snadno převést na cyklus, proto interpret jazyka Scheme nemusí
; zbytečně alokovat prostor na zásobníku. Místo toho na zásobníku přepisuje hodnoty
; parametrů. Funguje tedy prakticky jako cyklus.

; Koncová rekurze je taková, která má rekurzivní volání, jako posledí operaci, která
; se ve funkci provádí. Funkce faktorial taková není, protože zde je poslední operací
; násobení, ne rekurzivní volání. Funkce faktorial ale jde přepsat na koncově rekurzivní
; verzi. Finta spočívá v přidání pomocného parametru, který bude sloužit pro ukládání
; mezivýsledků. Do této pomocné proměnné pak při volání musíme uložit vhodnou počáteční
; hodnotu

(define (tr-faktorial x pom)
  (if (<= x 0)
      pom
      (tr-faktorial (- x 1) (* x pom))))

; V tomto případě bude v pomocné proměnné uložena hodnota, která se vrací v primitivním
; případě, tedy 1
"Volání funkce tr-faktorial"
(tr-faktorial 7 1)

; Aby uživatel omylem nezadal jinou počáteční hodnotu, lze jednoduše vyrobit
; pomocnou obalovací funkci, která to zařídí.
(define (faktorial-t x)
  (tr-faktorial x 1))

; Zároveň teď budeme trasovat funkci tr-faktorial pro srovnání s původní funkcí faktorial.
"Volání funkce faktorial-t"
(trace tr-faktorial)
(faktorial-t 7)
