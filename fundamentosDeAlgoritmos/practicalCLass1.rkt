;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname exercicios1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; contrato: numero -> numero
;; objetivo: determinar a quantia devida de imposto em relação ao salário consumido

(define (impostoBaseadoEmSalário salario)
  (cond
    [(<= salario 240) 0]
    [(<= salario 480) (* salario 0.15)]
    [else (* salario 0.28)]))

(check-expect (impostoBaseadoEmSalário 240) 0)
(check-expect (impostoBaseadoEmSalário 480) 72)
(check-expect (impostoBaseadoEmSalário 900) 252)

;; contrato: numero -> numero
;; objetivo: calcular o salario liquido de um trabalhador a partir da quantidade de horas trabalhadas

(define (salarioBruto horasTrabalhadas)
  (* horasTrabalhadas 15))
(define (salarioLiquido horasTrabalhadas)
  (- (salarioBruto horasTrabalhadas) (impostoBaseadoEmSalário (salarioBruto horasTrabalhadas))))

(check-expect (salarioBruto 60) 900)
(check-expect (salarioLiquido 60) 648)

;; contrato: símbolo -> símbolo
;; objetivo: comparar os símbolos inseridos e retornar um símbolo correspondente a relação entre os símbolos inseridos 

(define (testa-cores p1 p2 c1 c2)
  (cond
    [(or (symbol=? c1 p1) (symbol=? c2 p2)) (cond
                        [(and (symbol=? c1 p1) (symbol=? c2 p2)) 'Exato!]
                        [else 'UmaPosiçãoCorreta])]
    [(or (symbol=? c1 p2) (symbol=? c2 p1)) 'UmaCorCorreta]
    [else 'TudoErrado!]))

(check-expect (testa-cores 'a 'b 'c 'd) 'TudoErrado!)
(check-expect (testa-cores 'a 'b 'b 'a) 'UmaCorCorreta)
(check-expect (testa-cores 'a 'b 'a 'd) 'UmaPosiçãoCorreta)
(check-expect (testa-cores 'a 'b 'a 'b) 'Exato!)