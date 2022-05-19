#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "listas.h"

enum cor {branco,cinza,preto};
typedef enum cor cor;

typedef struct {
    int v;
    int w;
} Aresta;
// cria uma aresta (v,w)

//estrutura de matriz adjacencia.
struct grafo {
    Lista **vetor;
    int v;//quantidade de vértices maximo
    int ordenado;
};

typedef struct grafo * Grafo;

//cria uma aresta
Aresta ARESTA(int v,int w);


//inicializa um grafo com |V| vertices
Grafo inicializa(int V,int ordenado);


//Insere a aresta e no grafo g
void grafoInsere(Grafo g, Aresta e);
//Remove a aresta e do grafo g
void grafoRemove(Grafo g, Aresta e);
//Preenche o vetor com as arestas de g
//Retorna |E|, quantidade de arestas
int grafoArestas(Aresta a[], Grafo g);
//imprime um grafo G = (V,E);
void imprimirGrafo(Grafo g);


int pertence(Grafo g, Aresta e);

//(d) Implemente a busca em profundidade a partir de um vertice de origem s, tal que imprima a
//arvore de busca obtida.

int timestamp = 0;//variável global de timeStamp;

void DFS_visit(Grafo g,Lista *v,cor c[],int pi[],int d[],int f[],int indice);


void printVet(int vet[],int n);


void showArvore(Grafo g,int d[]);

void DFS(Grafo g);

void DFS_origem(Grafo g,int vertice);





/*(e) Implemente a busca em largura a partir de um vertice de origem s, tal que imprima a arvore de
busca obtida.*/




void BFS(Grafo g,int vertice);


//ORDENAÇÃO TOPOLÓGICA:

void DFS_visit_OT(Grafo g,Lista *v,cor c[],int pi[],int d[],int f[],int indice,Lista**l);


Lista* DFS_OT(Grafo g);


Lista* ordenacaoTopologica(Grafo g);
