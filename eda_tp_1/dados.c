/**
 *  @file dados.c
 * @author Eduardo
 * @email a18589@alunos.ipca.pt
 * @date 2022
 */
#include "dados.h"

/**
 * @brief cria maquina nova
 * */
Maquina * criaMaquina(int t, int novoCod) {
    Maquina * nova = (Maquina * ) malloc(sizeof(Maquina));
    nova -> cod = novoCod;
    nova -> t = t;
    nova -> prox = NULL;
    return nova;
}

/**
 * @brief cria Job novo
 * */
Job * criaJob(int novoCod) {
    Job * novo = (Job * ) malloc(sizeof(Job));
    novo -> cod = novoCod;
    novo -> operation = NULL;
    novo -> prox = NULL;
    return novo;
}

/**
 * @brief cria Operation nova
 * */
Operation * criaOperation(int novoCod) {
    Operation * nova = (Operation * ) malloc(sizeof(Operation));
    nova -> cod = novoCod;
    nova -> maquina = NULL;
    nova -> prox = NULL;
    return nova;
}

/**
 * @brief Verifica se job existe. Se existir devolve Bool!
 * @return	True/False
 */
bool existeJob(Job * h, int cod) {
    if (h == NULL)
        return false;
    Job * aux = h;
    while (aux != NULL) {
        if (aux -> cod == cod)
            return true;
        aux = aux -> prox;
    }
    return false;
}

/**
 * @brief Insere um novo Job no início da estrutura
 * @return	Inicio da Lista
 */
Job * insereJob(Job * h, Job * novo) {
    if (novo == NULL)
        return h; //Verificar se apontadores são válidos

    if (existeJob(h, novo -> cod))
        return h; //se existir não insere

    if (h == NULL) {
        h = novo;
    } else {
        novo -> prox = h; //aponta para onde "h" está a apontar
        h = novo;
    }
    return h;
}

/**
 * @brief Verifica se operation existe. Se existir devolve Bool!
 */
bool existeOperation(Operation * operation, int cod) {
    if (operation == NULL)
        return false;
    Operation * aux = operation;
    while (aux != NULL) {
        if (aux -> cod == cod)
            return true;
        aux = aux -> prox;
    }
    return false;
}

/**
 * @brief Insere uma operation dentro de um job
 * @return Estrutura job onde foi inserida a operation
 */
Job * insereOperation(Job * jobList, Operation * operation) {
    if (jobList == NULL)
        return NULL;
    if (operation == NULL)
        return NULL;
    if (jobList -> operation == NULL) {
        jobList -> operation = operation;
    } else {
        if (existeOperation(jobList -> operation, operation -> cod) == true) {
            return jobList;
        } else {
            operation -> prox = jobList -> operation;
            jobList -> operation = operation;
        }
    }
    return jobList;
}

/**
 * @brief Verifica se maquina existe. Se existir devolve Bool!
 * @return	True/False
 */
bool existeMaquina(Maquina * maquina, int cod) {
    if (maquina == NULL)
        return false;
    Maquina * aux = maquina;
    while (aux != NULL) {
        if (aux -> cod == cod)
            return true;
        aux = aux -> prox;
    }
    return false;
}

/**
 * @brief Insere uma maquina
 */
Operation * insereMaquina(Operation * operation, Maquina * maquina) {
    if (operation == NULL)
        return NULL;
    if (maquina == NULL)
        return NULL;
    if (operation -> maquina == NULL) {
        operation -> maquina = maquina;
    } else {
        if (existeMaquina(operation -> maquina, maquina -> cod) == 1) {
            return operation;
        } else {
            maquina -> prox = operation -> maquina;
            operation -> maquina = maquina;
        }
    }
    return operation;
}

/**
 * @brief Funçao que escreve no ficheiro
 */
void escreveFicheiro(Job * list) {
    Job* aux = list;
    FILE * fp;
    fp = fopen("joblists", "w");
    /*if(aux == NULL){
        printf("empty");
    }*/
    while (aux) {
        while (aux -> operation) {
            while (aux -> operation -> maquina) {
                fprintf(fp, "%d,%d,%d,%d",
                        aux -> cod, aux -> operation -> cod,
                        aux -> operation -> maquina -> t,
                        aux -> operation -> maquina -> cod);
                aux -> operation -> maquina = aux -> operation -> maquina -> prox;
            }
            aux -> operation = aux -> operation -> prox;
            return;
        }
        aux = (Job *) aux->operation->prox; //(Job *) Sugerido pelo IDE
    }
    fclose(fp);
}

/**
 * @brief Funçao que le o ficheiro
 */
Job * leFicheiro() {
    FILE * fp;
    int jobCod, operationCod, t, maquinaCod;
    Job * job = NULL;
    Job * aux = NULL;

    fp = fopen("joblists", "r");
    if (fp) {
        do {
            if (job == NULL) {
                fscanf(fp, "%d,%d,%d,%d", &jobCod, &operationCod, &t,& maquinaCod);
                job = criaJob(jobCod);
                job -> operation = criaOperation(operationCod);
                job -> operation -> maquina = criaMaquina(t, maquinaCod);
            } else {
                fscanf(fp, "%d,%d,%d,%d", &jobCod, &operationCod, &t, &maquinaCod);
                aux = criaJob(jobCod);
                aux -> operation = criaOperation(operationCod);
                aux -> operation -> maquina = criaMaquina(t, maquinaCod);
                job = insereJob(job, aux);
                job = insereOperation(job, aux -> operation);
                job -> operation = insereMaquina(job -> operation, aux -> operation -> maquina);
            }
            if (feof(fp)) {
                break;
            }
        } while (true);
        fclose(fp);
    }
    return job;
}