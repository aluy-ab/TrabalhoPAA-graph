#include <stdlib.h>
#include "filas.h"


int vaziaFila(Fila* f) {
    return (f->inicio == NULL);
}
Fila* cria_fila_vazia() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

//Enfileira um elemento
void enqueue(Fila* f, TipoItem x) {
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->info = x;
    aux->prox = NULL;
    if(vaziaFila(f)) {
        f->inicio = aux;
    } else {
        f->fim->prox = aux;
    }
    f->fim = aux;
}

//Desenfileira um elemento
TipoItem* dequeue(Fila* f) {
    if(!vaziaFila(f)) {
        TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
        struct no* aux = f->inicio;
        *x = f->inicio->info;
        if(f->inicio == f->fim) // so tem 1 elemento
            f->fim = NULL;
        f->inicio = f->inicio->prox;
        free(aux);
        return x;
    } else
        return NULL;
}

TipoItem* head(Fila* f){
    if(!vaziaFila(f)) {
        TipoItem* x = (TipoItem*) malloc(sizeof(TipoItem));
        *x = f->inicio->info;
        return x;
    } else
        return NULL;
}
