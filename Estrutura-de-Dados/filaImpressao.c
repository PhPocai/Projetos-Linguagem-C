/*Considere um conjunto de 3 impressoras (vetor de 3 elementos).

Implemente as filas de impressão de cada uma das impressoras:

- enviar documento para impressão (dizer qual a impressora e a identificação do documento): enfileira o documento na impressora

- imprimir (dizer qual impressora): desenfileira documento

- cancelar impressão (dizer qual impressora e qual documento): retira documento da fila daquela impressora*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct fila{
    char documento[15];
    struct fila *prox;
}FILA;

typedef struct impressoras {
    int idf;
    FILA *inicio, *fim;
} IMPRESSORA;

void enviaImpressao(IMPRESSORA *f , char *doc){
    if(f->idf == 0){
        f->inicio = NULL;
        f->fim = NULL;
    }
    FILA *novo = (FILA*) malloc(sizeof(FILA));
    strcpy(novo->documento,doc);
    novo->prox = NULL;

    if(f->fim == NULL){
        f->inicio = novo;
        f->fim = novo;
    }else{
        (f->fim)->prox = novo;
         f->fim = novo;
    }
    f->idf ++;
}
void imprime(IMPRESSORA *f){
    if(f->inicio == NULL){
        printf("Fila de impressao vazia.\n");
        return;
    }
    FILA *removido = f->inicio;
    printf("Imprimindo '%s'.\n", removido->documento);
    f->inicio = removido->prox;
    if (f->inicio == NULL){
            f->fim = NULL;
    }
    free(removido);
    f->idf--;
}
void cancelaImpressao(IMPRESSORA *f , char *doc){
    FILA *atual = f->inicio;
    FILA *ant = NULL;
    while(atual != NULL){
    if(strcmp (atual->documento, doc) == 0){
        if(ant == NULL){
            f->inicio = atual->prox;
        }else{
            ant->prox = atual->prox;
        }
        if(atual->prox == NULL){
            f->fim = ant;
        }
        free(atual);
        f->idf--;
        return;
        }
        ant = atual;
    atual = atual->prox;
    }
}
void mostraImpressoras(int nimpressora, IMPRESSORA *f){
    FILA *aux = f->inicio;
    printf("\nImpressora %d:\n", nimpressora);
    while (aux != NULL) {
        printf("%s", aux->documento);
        aux = aux->prox;
        if (aux != NULL)
            printf(" - ");
    }
    printf("\n");

}

void esvaziaFila(IMPRESSORA *f){
    FILA *p = f->inicio;
    FILA *tmp;
    while (p != NULL){
        tmp = p;
        p = p->prox;
        free(tmp);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->idf = 0;
}

int main(){
    IMPRESSORA imp [3] = {0};
    enviaImpressao(&imp[1], "prova.pdf");
    enviaImpressao(&imp[1], "foto.png");
    enviaImpressao(&imp[2], "relatorio.xlsx");
    enviaImpressao(&imp[0], "prova.pdf");

    mostraImpressoras(0, &imp[0]);
    mostraImpressoras(1, &imp[1]);
    mostraImpressoras(2, &imp[2]);

    imprime(&imp[0]);
    mostraImpressoras(0, &imp[0]);

    cancelaImpressao(&imp[1], "foto.png");
    mostraImpressoras(1, &imp[1]);

    return 0;
}
