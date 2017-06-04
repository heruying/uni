;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname extraClass) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(define-struct quantidade-de-carros (passeio-em-estoque passeio-vendido utilitario-em-estoque utilitario-vendido caminhão-em-estoque caminhão-vendido))

;; passeio-em-estoque - numero
;; passeio-vendido - numero
;; utilitario-em-estoque - numero
;; utilitario-vendido - numero
;; caminhão-em-estoque - numero
;; caminhão-vendido - numero

(define-struct passeio (cor subtipo airbag))

;; Cor — símbolo (exemplos: 'roxo, 'branco, 'azul)
;; Subtipo de veículo — símbolo (exemplos: 'hatch, 'sedan)
;; Airbag — booleano

(define-struct utilitario (cor assentos tração-nas-4-rodas))

;; Cor — símbolo (exemplos: 'roxo, 'branco, 'azul)
;; Assentos — número 
;; Tração-nas-4-rodas — booleano

(define-struct caminhão   (cor carga-máxima volume-máximo))

;; Cor — símbolo (exemplos: 'roxo, 'branco, 'azul)
;; Carga-máxima — número
;; Volume-máximo — número

(define Suie (make-passeio 'roxo 'hatch true))
(define King (make-utilitario 'roxo 4 false))
(define Zue  (make-caminhão 'branco 1000 2000))
(define Quantidades (make-quantidade-de-carros 2080 100 1500 700 300 200))  
;; contrato: instância do tipo passeio/utilitario/caminhão -> instância com 2 símbolos
;; objetivo: a partir de um dado do tipo carro, a função retorna a cor do carro

(define-struct cor-e-tipo-carro (cor tipo))

(define (retorna-cor-e-tipo carro)
  (cond
    [(passeio? carro) (make-cor-e-tipo-carro (passeio-cor carro) 'passeio)]
    [(caminhão? carro) (make-cor-e-tipo-carro (caminhão-cor carro) 'caminhão)]
    [(utilitario? carro) (make-cor-e-tipo-carro (utilitario-cor carro) 'utilitario)]
    )
  )
;; contrato: adaptando-utilitario: utilitario -> utilitario
;; objetivo: caso um utilitario usado como parâmetro tenha tração nas 4 rodas,
;; remove um assento e muda sua cor para azul
;; exemplo: utilitario ('roxo 4 true) -> utilitario ('azul 3 true)

(define (adaptando-utilitario utilitario)
  (if (utilitario-tração-nas-4-rodas utilitario)
      (make-utilitario 'azul (- (utilitario-assentos utilitario) 1) true)
      utilitario))

;; contrato: instância do tipo passeio/utilitario/caminhão -> booleano ou numero
;; objetivo: caso a instância inserida seja do tipo passeio e subtipo sedan, determina se contém ou não airbag
;; caso seja utilitario, determina se possui ou não tração nas quatro rodas
;; caso seja caminhão, mostra o volume total de carga suportada
;; exemplo: utilitario ('cinza 'sedan true) -> true
;; caminhão ('vermelho 4000 2000) -> 2000

(define (correção-carros carro)

  (cond
    [(and (passeio? carro ) (symbol=? 'sedan (passeio-subtipo carro))) (passeio-airbag carro)]
    [(utilitario? carro) (utilitario-tração-nas-4-rodas carro)]
    [(caminhão? carro) (caminhão-volume-máximo carro)]))


;; atualiza-quantidade: instância do tipo quantidade-de-carros e número -> instância do tipo quantidade-de-carros
;; objetivo: atualizar a quantidade de carros de passeio vendidos
;; exemplo: (make-quantidade-de-carros 2080 20 1500 300 300 280) 20 -> (make-quantidade-de-carros 2060 40 1500 300 300 280)


(define (atualiza-quantidade quantidade-original vendidos-no-dia)
  (make-quantidade-de-carros 
     (- (quantidade-de-carros-passeio-em-estoque quantidade-original) vendidos-no-dia)
     (+ (quantidade-de-carros-passeio-vendido quantidade-original) vendidos-no-dia)
     (quantidade-de-carros-utilitario-em-estoque quantidade-original)
     (quantidade-de-carros-utilitario-vendido quantidade-original)
     (quantidade-de-carros-caminhão-em-estoque quantidade-original)
     (quantidade-de-carros-caminhão-vendido quantidade-original)))

;; caminhão-suporta: caminhão, numero, numero -> booleano
;; objetivo: verificar se um caminhão tem suporte para carregar uma carga com peso x e tamanho y
;; exemplo: (make-caminhão 'rosa 2000 3000) 300 700 -> true 

(define (caminhão-suporta caminhão peso-carga volume-carga)
  (cond
    [(and (>= (caminhão-carga-máxima caminhão) peso-carga) (>= (caminhão-volume-máximo caminhão) volume-carga)) true]
    [else false]))

(caminhão-suporta Zue 99 1700)

;; alterar-estocagem: quantidade-de-carros, numero, numero, carro -> quantidade-de-carros
;; objetivo: atualizar as quantidades em estoque e visualizar as quantidades em estoque dos veículos produzidos pela montadora
;; caso queira somente visualizar as quantidades, insira qualquer valor em numero e carro.
;; (make-quantidade-de-carros 2080 20 1500 300 300 280) 2 20 (make-caminhão 'branco 1000 2000) -> (make-quantidade-de-carros 2080 20 1500 300 280 300)
;;

(define (alterar-estocagem original opção valor carro)
  (cond
     [(= opção 1)
      (cond
        [(utilitario? carro) (make-quantidade-de-carros (quantidade-de-carros-passeio-em-estoque original) (quantidade-de-carros-passeio-vendido original) (+ (quantidade-de-carros-utilitario-em-estoque original) valor) (quantidade-de-carros-utilitario-vendido original) (quantidade-de-carros-caminhão-em-estoque original) (quantidade-de-carros-caminhão-vendido original))]
        [(caminhão? carro) (make-quantidade-de-carros (quantidade-de-carros-passeio-em-estoque original) (quantidade-de-carros-passeio-vendido original) (quantidade-de-carros-utilitario-em-estoque original) (quantidade-de-carros-utilitario-vendido original) (+ (quantidade-de-carros-caminhão-em-estoque original) valor) (quantidade-de-carros-caminhão-vendido original))]
        [(passeio? carro) (make-quantidade-de-carros (+ (quantidade-de-carros-passeio-em-estoque original) valor) (quantidade-de-carros-passeio-vendido original) (quantidade-de-carros-utilitario-em-estoque original) (quantidade-de-carros-utilitario-vendido original) (quantidade-de-carros-caminhão-em-estoque original) (quantidade-de-carros-caminhão-vendido original))])]
     [(= opção 2)
      (cond
        [(utilitario? carro) (make-quantidade-de-carros (quantidade-de-carros-passeio-em-estoque original) (quantidade-de-carros-passeio-vendido original) (- (quantidade-de-carros-utilitario-em-estoque original) valor) (+ (quantidade-de-carros-utilitario-vendido original) valor) (quantidade-de-carros-caminhão-em-estoque original) (quantidade-de-carros-caminhão-vendido original))]
        [(caminhão? carro) (make-quantidade-de-carros (quantidade-de-carros-passeio-em-estoque original) (quantidade-de-carros-passeio-vendido original) (quantidade-de-carros-utilitario-em-estoque original) (quantidade-de-carros-utilitario-vendido original) (- (quantidade-de-carros-caminhão-em-estoque original) valor) (+ (quantidade-de-carros-caminhão-vendido original) valor))]
        [(passeio? carro) (make-quantidade-de-carros (- (quantidade-de-carros-passeio-em-estoque original) valor) (+ (quantidade-de-carros-passeio-vendido original) valor) (quantidade-de-carros-utilitario-em-estoque original) (quantidade-de-carros-utilitario-vendido original) (quantidade-de-carros-caminhão-em-estoque original) (quantidade-de-carros-caminhão-vendido original))])]
     [(= opção 3)
      (format "Quantidade atual em estoque: ~a. Quantidade vendida: ~a." (+ (+ (quantidade-de-carros-passeio-em-estoque original) (quantidade-de-carros-utilitario-em-estoque original)) (quantidade-de-carros-caminhão-em-estoque original)) (+ (+ (quantidade-de-carros-passeio-vendido original) (quantidade-de-carros-utilitario-vendido original)) (quantidade-de-carros-caminhão-vendido original)))]))

(alterar-estocagem Quantidades 2 20 Zue)

;; conta-passeio-vendido: quantidade-de-carros -> numero
;; demonstra quantos % do total de carros vendidos representam carros de passeio
;; exemplo: (make-quantidade-de-carros 100 200 400 700 200 100) -> 20

(define (conta-passeio-vendido quantidades)
  (*
   (/
    (quantidade-de-carros-passeio-vendido quantidades)
    (+
     (+
      (quantidade-de-carros-passeio-vendido quantidades)
      (quantidade-de-carros-utilitario-vendido quantidades))
     (quantidade-de-carros-caminhão-vendido quantidades)))
    100))

(conta-passeio-vendido Quantidades)