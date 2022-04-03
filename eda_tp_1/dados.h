/**
 *  @file dados.h
 * @author Eduardo
 * @email a18589@alunos.ipca.pt
 * @date 2022
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef dados
#define dados

#define M 40

#pragma region structs
typedef struct Job {
    int cod;
    struct Operation * operation;
    struct Job * prox;
}Job;

typedef struct Operation {
    int cod;
    struct Maquina * maquina;
    struct Operation * prox;
}Operation;

typedef struct Maquina {
    int t;
    int cod;
    struct Maquina * prox;
}Maquina;
#pragma endregion

#pragma region functions
Maquina * criaMaquina(int t, int novoCod);
Job * criaJob(int novoCod);
Operation * criaOperation(int novoCod);

bool existeJob(Job * h, int cod);
Job * insereJob(Job * h, Job * novo);
bool existeOperation(Operation * operation, int cod);
Job * insereOperation(Job * jobList, Operation * operation);
bool existeMaquina(Maquina * maquina, int cod);
Operation * insereMaquina(Operation * operation, Maquina * maquina);

void escreveFicheiro(Job * list);
Job * leFicheiro();

#pragma endregion

#endif