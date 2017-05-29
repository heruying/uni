;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname practicalClass2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; estrutura: candidato
;; esta estrutura é composta por: símbolo, símbolo, número, número
;; o primeiro símbolo representa o nome do candidato, o segundo representa o partido, o primeiro número corresponde ao número do
;; candidato, e o segundo número representa sua quantidade de votos
(define-struct candidato (nome partido numero votos))

(define João-Nicolas (make-candidato 'João-Nicolas 'PSTUdoB 3 1))
(define Thomas-George (make-candidato 'Thomas-George 'IDA 7 21))
(define Hortêncio-da-Costa (make-candidato 'Hortêncio-da-Costa 'PCC 20 19))

;; saca-votos: lista, número -> número
;; objetivo: conta a quantidade de votos que um candidato X angariou na urna
;; exemplo: (saca-votos (cons 7 (cons 3 (cons 0 (cons 20 (cons 0 (cons 3 empty)))))) 3) -> 2
;; exemplo: (saca-votos (cons 3 (cons 7 (cons 20 (cons 3 (cons 7 (cons 7 (cons 20 (cons 3 (cons 20 (cons 0 (cons 3 (cons 3 (cons 0 (cons 7 (cons 20 empty))))))))))))))) 0) -> 2

(define (saca-votos urna numero)
  (cond
    [(empty? urna) 0]
    [(= (first urna) numero) (+ 1 (saca-votos (rest urna) numero))]
    [else (saca-votos (rest urna) numero)]))

;; une-urnas: lista, lista -> lista
;; objetivo: unir os votos de duas urnas diferentes
;; exemplo: (une-urnas (cons 7 (cons 3 (cons 0 empty))) (cons 3 (cons 3 (cons 20 empty)))) -> (cons 7 (cons 3 (cons 0 (cons 3 (cons 3 (cons 20 '()))))))
;; exemplo: (une-urnas (cons 3 (cons 3 (cons 0 empty))) (cons 20 empty)) -> (cons 3 (cons 3 (cons 0 (cons 20 empty))))


(define (une-urnas urnaA urnaB)
  (cond
    [(not (empty? urnaA)) (cons (first urnaA) (une-urnas (rest urnaA) urnaB))]
    [(not (empty? urnaB)) (une-urnas (rest urnaA) urnaB)]
    [else empty]))


;; atualiza-votos: candidato, candidato, candidato, lista
;; objetivo: atualizar a quantidade de votos dos candidatos a partir da contagem de uma urna (lista)
;; 
 
(define (atualiza-votos lista-de-candidatos lista-de-urnas)
  (cond
    [(empty? lista-de-candidatos) empty]
    [else (cons (make-candidato (candidato-nome (first lista-de-candidatos)) (candidato-partido (first lista-de-candidatos)) (candidato-numero (first lista-de-candidatos)) (+ (candidato-votos (first lista-de-candidatos)) (saca-votos (une-urnas (first lista-de-urnas) (rest lista-de-urnas)) (candidato-numero (first lista-de-candidatos))))) (atualiza-votos (rest lista-de-candidatos) lista-de-urnas))]))

(atualiza-votos (cons João-Nicolas (cons Thomas-George empty)) (cons (cons 3 (cons 7 (cons 0 empty))) (cons 3 (cons 3 (cons 7 (cons 3 (cons 7 empty)))))))


;; percentual-de-votos:: numero, lista -> numero
;; objetivo: descobrir a porcentagem de um candidato em relação ao total de votos válidos
;;

(define (conta-validos urnas)
  (cond
    [(empty? urnas) 0]
    [(= (first urnas) 0) (conta-validos (rest urnas))]
    [else (+ 1 (conta-validos (rest urnas)))]))


(define (percentual-de-votos numero urnas)
  (/
   (saca-votos (une-urnas (first urnas) (rest urnas)) numero)
   (/
    (conta-validos (une-urnas (first urnas) (rest urnas)))
    100)))

(une-urnas (cons (cons 9 empty) (cons 7 empty)) (cons (cons 2 empty) empty))