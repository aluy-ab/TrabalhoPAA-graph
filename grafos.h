#ifndef GRAFOS_H_
#define GRAFOS_H_


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "listas.h"
#include "filas.h"

enum cor {branco,cinza,preto};
typedef enum cor cor;



typedef struct {
    int v;
    int w;
    int peso;
} Aresta;
// cria uma aresta (v,w)

//estrutura de matriz adjacencia.
struct grafo {
    Lista **vetor;
    int v;//quantidade de vértices maximo
    int orientado;
};

typedef struct grafo * Grafo;

//cria uma aresta
Aresta ARESTA(int v,int w, int peso);


//inicializa um grafo com |V| vertices
Grafo inicializa(int V,int ordenado);


//Insere a aresta e no grafo g
void grafoInsere(Grafo g, Aresta e);
//Remove a aresta e do grafo g
void grafoRemove(Grafo g, Aresta e) ;
//Preenche o vetor com as arestas de g
//Retorna |E|, quantidade de arestas
int grafoArestas(Aresta a[], Grafo g);
//imprime um grafo G = (V,E);
void imprimirGrafo(Grafo g);


int pertence(Grafo g, Aresta e) ;



void DFS_visit(Grafo g,Lista *v,cor c[],int pi[],int d[],int f[],int indice);


void printVet(int vet[],int n);


void showArvore(Grafo g,int d[]);

void DFS(Grafo g);

void DFS_origem(Grafo g,int vertice);

void InicializaOrigem(Grafo g, int vertice,int d[], int pi[]);
void Relax(Aresta a, int d[], int pi[]);
int Bellman_Ford(Grafo g,int origem);
void printCaminho(int pi[],int n);
void BFS(Grafo g,int vertice);


//ORDENAÇÃO TOPOLÓGICA:

void DFS_visit_OT(Grafo g,Lista *v,cor c[],int pi[],int d[],int f[],int indice,Lista**l);
Lista* DFS_OT(Grafo g) ;
Lista* ordenacaoTopologica(Grafo g);

#endif // GRAFOS_H_
