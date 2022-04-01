/**
*  @file Maquinas.h
 * @author Eduardo
 * @email a18589@alunos.ipca.pt
 * @date 2022
*/

#ifndef UNTITLED_MAQUINAS_H
#define UNTITLED_MAQUINAS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//struct maquina
#define M 40
typedef struct Maquina {
    int cod;
    char nome[M];
    struct Maquina* prox;
}Maquina;

//cria nova maquina
Maquina* CriaMaquina(int novoCod, char* novoNome);
Maquina* InsereMaquina(Maquina* h, Maquina* nova);

#define MAQUINA
#endif //UNTITLED_MAQUINAS_H
