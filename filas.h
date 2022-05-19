#ifndef FILAS_H_
#define FILAS_H_

#include "listas.h"
//FILAS:

typedef struct noFila{
    struct no* inicio;
    struct no* fim;
} Fila;

int vaziaFila(Fila* f);
Fila* cria_fila_vazia();

//Enfileira um elemento
void enqueue(Fila* f, TipoItem x);

//Desenfileira um elemento
TipoItem* dequeue(Fila* f) ;

TipoItem* head(Fila* f);

#endif // FILAS_H_
