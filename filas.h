//#include "listas.h"
#define TipoItem int
//FILAS:
typedef struct {
    Lista* inicio;
    Lista* fim;
} Fila;

int vaziaFila(Fila* f);
Fila* cria_fila_vazia();

//Enfileira um elemento
void enqueue(Fila* f, TipoItem x);

//Desenfileira um elemento
TipoItem* dequeue(Fila* f) ;

TipoItem* head(Fila* f);
