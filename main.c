
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "grafosListasADJ.h"
#include "listas.h"


int main()
{
    setlocale(LC_ALL, "Portuguese");
    Grafo g = NULL;
    g = inicializa(6, 0);
    printf("inicializou!\n");
    printf("g->v: %d\n", g->v);

    grafoInsere(g, ARESTA(0, 2));
    grafoInsere(g, ARESTA(0, 1));
    grafoInsere(g, ARESTA(2, 5));
    grafoInsere(g, ARESTA(2, 4));
    grafoInsere(g, ARESTA(2, 3));
    grafoInsere(g, ARESTA(3, 5));
    grafoInsere(g, ARESTA(3, 4));
    grafoInsere(g, ARESTA(1, 3));
    grafoInsere(g, ARESTA(4, 5));
    imprimirGrafo(g);
    DFS(g);
    DFS_origem(g, 3);
    BFS(g, 3);
    printf("Pertente (1,3) : %d\n", pertence(g, ARESTA(1, 3)));

    Grafo ordenado = NULL;
    ordenado = inicializa(6, 1);
    /*grafoInsere(ordenado,ARESTA(0,4));
    grafoInsere(ordenado,ARESTA(1,4));
    grafoInsere(ordenado,ARESTA(1,2));
    grafoInsere(ordenado,ARESTA(1,3));
    grafoInsere(ordenado,ARESTA(1,5));
    grafoInsere(ordenado,ARESTA(1,0));
    grafoInsere(ordenado,ARESTA(2,3));
    grafoInsere(ordenado,ARESTA(3,5));
    grafoInsere(ordenado,ARESTA(7,4));
    grafoInsere(ordenado,ARESTA(7,6));
    grafoInsere(ordenado,ARESTA(10,7));
    grafoInsere(ordenado,ARESTA(11,10));
    grafoInsere(ordenado,ARESTA(11,6));
    grafoInsere(ordenado,ARESTA(11,12));
    grafoInsere(ordenado,ARESTA(12,9));*/
    grafoInsere(ordenado, ARESTA(0, 2));
    grafoInsere(ordenado, ARESTA(1, 2));
    grafoInsere(ordenado, ARESTA(1, 0));
    grafoInsere(ordenado, ARESTA(2, 4));
    grafoInsere(ordenado, ARESTA(3, 1));
    grafoInsere(ordenado, ARESTA(3, 4));
    grafoInsere(ordenado, ARESTA(5, 2));
    imprimirGrafo(ordenado);
    printf("Ordenação Topológica: \n");
    Lista* ord = ordenacaoTopologica(ordenado);
    imprimir(ord);
    return 0;
}