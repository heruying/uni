;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname inClassExercises1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; soma-3: lista-de-3-números -> número
;; objetivo: somar 3 elementos de uma lista de 3 números
;;

(define (soma-3 lista)
  (+ (+ (first lista) (first (rest lista))) (first (rest (rest lista)))))


;;contém-simbolo?: lista-de-símbolos símbolo -> booleano
;; obj: vasculhar uma lista de símbolos à procura de um simbolo específico
;; exemplo: (cons 'x (cons 'y (cons 'z empty))) 'j = false
;; (cons 'x (cons 'y (cons 'z empty))) 'z = true


(define (contém-simbolo lista símbolo)
  (cond
    [(empty? lista) false]
    [(symbol=? símbolo (first lista)) true]
    [else (contém-simbolo (rest lista) símbolo)]
    ))


;; calcula-valor-de-estoque: lista-de-números -> número
;; objetivo calcular o valor total de uma lista de valores dos objetos em estoque na loja
;; exemplo: (calcula-valor-de-estoque (cons 5 (cons 9 (cons 20 (cons 6 empty))))) -> 40
;; (calcula-valor-de-estoque (cons 10 (cons 30 (cons 40 (cons 50 empty))))) -> 130
;; (calcula-valor-de-estoque (cons 4 (cons 3 (cons 2 (cons 1 empty))))) -> 10

(define (calcula-valor-de-estoque lista)
  (cond
    [(empty? lista) 0]
    [else (+ (first lista) (calcula-valor-de-estoque (rest lista)))]))

;; um-real?: lista-de-números -> booleano
;; objetivo: verificar se todos os valores da lista são menores que 1 real
;; (um-real? (cons 0.2 (cons 0.1 (cons 0.9 (cons 0.2 empty))))) -> true
;; (um-real? (cons 0.2 (cons 0.1 (cons 0.9 (cons 2 empty))))) -> false

(define (um-real? lista)
  (cond
    [(empty? lista) true]
    [(< (first lista) 1) (um-real? (rest lista))]
    [else false]))

;; abaixo-de-x?: lista-de-números número -> booleano
;; objetivo: ver se todos os valores de dada lista são menores do que dado valor x
;; exemplo: (abaixo-de-x? (cons 5 (cons 3 (cons 2 (cons 9 empty)))) 5) -> false
;; (abaixo-de-x? (cons 5 (cons 3 (cons 2 (cons 3 empty)))) 5) -> false
;; (abaixo-de-x? (cons 4 (cons 3 (cons 2 (cons 1 empty)))) 5) -> true

(define (abaixo-de-x? lista x)
  (cond
    [(empty? lista) true]
    [(< (first lista) x) (abaixo-de-x? (rest lista) x)]
    [else false]))

;; converte: lista -> número
;; objetivo: converter uma lista de números de um dígito em um número decimal
;; exemplo: (converte (cons 1 (cons 3 (cons 9 (cons 2 (cons 1 empty)))))) -> 12931
;; (converte (cons 2 (cons 9 (cons 2 (cons 5 (cons 7 empty)))))) -> 75292
;; (converte (cons 1 (cons 5 (cons 1 (cons 2 (cons 9 empty)))))) -> 92151
(define (converte lista)
  (cond
   [(empty? lista) 0]
   [else (+ (first lista) (* 10 (converte (rest lista))))]))