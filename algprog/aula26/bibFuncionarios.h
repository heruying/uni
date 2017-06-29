#ifndef _STDIO_H_
#include <stdio.h>
#endif
#ifndef _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _STRING_H_
#include <string.h>
#endif

#ifndef BIBFUNCIONARIOS_H_
#define BIBFUNCIONARIOS_H_

struct tipo_funcionario {
    int codigo;
    char sexo;
    char nome[50];
    float salario;
    char cargo[50];
    int idade;
};

/*
Função que adiciona o funcionário passado por argumento ao fim do arquivo binário.
Retorna 0 se tudo funcionar
e -1 caso aja erro na abertura do arquivo.
*/
int appendFuncionario (struct tipo_funcionario funcionario);

/*
Encontra um funcionário no arquivo binário a partir de seu código,
e usa a uma instância de estrutura passada por referência
para retornar o funcionário.
Retorna -2 caso tenha problemas ao abrir o arquivo,
-1 caso não encontre o funcionário,
e 0 caso tudo ocorra bem.
*/
int achaFuncionario (int codigo, struct tipo_funcionario *funcionario);

/*
Atualiza o salário/cargo da instância da estutura passada por referência.
*/
void atualizaFuncionario (struct tipo_funcionario *funcionario);

/*
Procura o funcionário no arquivo binário e substitui seu registro pelo registro passado por argumento.
*/
int atualizaBinario (struct tipo_funcionario funcionario);

/*
Imprime na tela os dados do funcionário passado por argumento.
Retorna -1 caso tenha problemas na leitura,
0 caso tudo ocorra bem.
*/
void imprimeFuncionario(struct tipo_funcionario funcionario);
/*
Lê o código de um funcionário.
*/
int leCodigo();

/*
Lê os dados necessários para criar uma instância da estrutura funcionário.
*/
struct tipo_funcionario leFuncionario();

#endif
