/**
*  @file main.c
 * @author Eduardo
 * @email a18589@alunos.ipca.pt
 * @date 2022
*/

#include "dados.h"

int main() {
    Job* h = NULL;
    h = leFicheiro();

    if(h == NULL){
        h = criaJob(1);
        return h;
    }

    Maquina* m1 = criaMaquina(4, 1);
    Maquina* m2 = criaMaquina(4, 2);
    Maquina* m3 = criaMaquina(5, 3);
    Maquina* m4 = criaMaquina(5, 4);

    Operation* operation1 = criaOperation(1);
    Operation* operation2 = criaOperation(2);
    Operation* operation3 = criaOperation(3);
    Operation* operation4 = criaOperation(4);

    operation1 = insereMaquina(operation1, m1);
    operation2 = insereMaquina(operation2, m2);
    operation3 = insereMaquina(operation3, m3);
    operation4 = insereMaquina(operation4, m4);

    h = insereOperation(h, operation1);
    h = insereOperation(h, operation2);
    h = insereOperation(h, operation3);
    h = insereOperation(h, operation4);

    escreveFicheiro(h);
}
