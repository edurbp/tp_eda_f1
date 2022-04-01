/**
*  @file Maquinas.h
 * @author Eduardo
 * @email a18589@alunos.ipca.pt
 * @date 2022
*/

#include "Maquinas.h"
#include <stdlib.h>
#include <string.h>

Maquina *CriaMaquina(int novoCod, char*novoNome) {
    //aloca memoria
    Maquina *nova = (Maquina*) malloc(sizeof(Maquina));
    nova->cod = novoCod;
    strcpy(nova->nome, novoNome);
    nova->prox = NULL;
    return nova;
}

/**
*	@brief Insere maquina na lista
*	@param [in] h		inicio da lista
*	@param [in] nova	nova maquina a inserir
*	@return		Inicio da Lista
*/
Maquina* InsereMaquina(Maquina* h, Maquina* nova) {
    if(nova == NULL)
        return h;
    if (h == NULL){
        h = nova;
        return (h);
    }
    else{
        Maquina* aux = h;
        Maquina* antAux = aux;
        while (aux != NULL && aux->cod < nova->cod){
            antAux = aux;
            aux = aux->prox;
        }
        if(aux == h) {
            nova->prox = h;
            h = nova;
            return h;
        }
        if (aux != NULL){
            nova->prox = aux;
            antAux->prox = nova;
        }
    }
    return h;
}