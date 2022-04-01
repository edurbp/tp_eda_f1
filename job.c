//
// Created by edurbp on 3/27/22.
//

#include "job.h"

void EscreveFicheiro(Job* lists ){
    Job* aux = lists;
    FILE *fp;
    fp = fopen("joblists.txt", "w");
    while(aux != NULL){
        fprintf(fp, "%d\n", aux->cod);
        fprintf(fp, "%d\n", aux->t);
        for(int i=0; i<x; i++){
            fprintf(fp, "%s\n", aux->op[i]);
        }
        aux = aux->prox;
    }
    fclose(fp);
}

Job* CriaJob(int cod, int t, char op[x][y]){
    //aloca memoria
    Job *nova = (Job*) malloc(sizeof(Job));
    nova->cod = cod;
    nova->t = t;
    for(int i=0; i<x; i++){
        strcpy(nova->op[i],op[i]);
    }
    nova->prox = NULL;
    return nova;
}

Job ReadJob(int cod, int t, char op[x][y]){

}