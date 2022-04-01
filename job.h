/**
*  @file Maquinas.h
 * @author Eduardo
 * @email a18589@alunos.ipca.pt
 * @date 2022
*/

#ifndef UNTITLED_JOB_H
#define UNTITLED_JOB_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Job{
    int cod;
    struct Job* prox;
}Job;

void EscreveFicheiro(Job* lists );
Job* CriaJob(int cod, char op);

#endif //UNTITLED_JOB_H
