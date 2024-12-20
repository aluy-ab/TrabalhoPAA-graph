#include "grafos.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "listas.h"
#include "filas.h"

int timestamp_grafos = 0;//vari�vel global de timeStamp.

//cria uma aresta
Aresta ARESTA(int v,int w, int peso) {
    Aresta a;
    a.v = v;
    a.w = w;
    a.peso = peso;
    return a;
}


//inicializa um grafo com |V| vertices
Grafo inicializa(int V,int ordenado) {
    Grafo novo = (struct grafo*) malloc(sizeof(struct grafo));
    novo->v = V;
    novo->orientado = ordenado;
    novo->vetor = (Lista**) malloc(V*sizeof(Lista*));
    for(int i = 0; i < V; i++) {
        novo->vetor[i] = NULL;
    }
    return novo;
}


//Insere a aresta e no grafo g
void grafoInsere(Grafo g, Aresta e) {
    g->vetor[e.v] = inserirComPeso(g->vetor[e.v],e.w,e.peso);
    if(g->orientado == 0){
        g->vetor[e.w] = inserirComPeso(g->vetor[e.w],e.v,e.peso);
        g->vetor[e.w] = ordenar(g->vetor[e.w]);
    }
    g->vetor[e.v] = ordenar(g->vetor[e.v]);

}
//Remove a aresta e do grafo g
void grafoRemove(Grafo g, Aresta e) {
    g->vetor[e.v] = remover(g->vetor[e.v],e.w);
    if(g->orientado == 0){
        g->vetor[e.w] = remover(g->vetor[e.w],e.v);
    }
}
//Preenche o vetor com as arestas de g
//Retorna |E|, quantidade de arestas
int grafoArestas(Aresta a[], Grafo g) {
    int count = 0;
    Lista* aux = NULL;
    for(int i = 0; i < g->v; i++) {
        aux = g->vetor[i];
        while(aux != NULL) {
            a[count++] = ARESTA(i,aux->info,aux->peso);//rever isso, o peso inserido
            aux = aux->prox;
        }
    }
    return count;
}
//imprime um grafo G = (V,E);
void imprimirGrafo(Grafo g) {
    Aresta a[50];
    int n = grafoArestas(a,g);
    for(int i = 0; i < n; i++) {
        printf("(%d,%d)\n",a[i].v,a[i].w);
    }
}


int pertence(Grafo g, Aresta e) {
    if(busca(g->vetor[e.v],e.w) != NULL)
        return 1;
    return 0;
}

//(d) Implemente a busca em profundidade a partir de um vertice de origem s, tal que imprima a
//arvore de busca obtida.



void DFS_visit(Grafo g,Lista *v,cor c[],int pi[],int d[],int f[],int indice) {
    c[indice] = cinza;
    printf("%d ",indice);//imprimir v�rtice visitado.
    timestamp_grafos++;
    d[indice] = timestamp_grafos;
    while(v != NULL) {
        if(c[v->info] == branco) {
            pi[v->info] = indice;
            DFS_visit(g,g->vetor[v->info],c,pi,d,f,v->info);
        }
        v = v->prox;
    }
    c[indice] = preto;

    timestamp_grafos++;
    f[indice] = timestamp_grafos;
}


void printVet(int vet[],int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n",vet[i]);
    }
    printf("\n");
}


void showArvore(Grafo g,int d[]) {
    printf("show arvore!!:\n");
    int newline = 0;
    for(int i = 0; i <= g->v; i++) {
        for(int j = 0; j < g->v; j++) {
            if(d[j] == i) {
                printf("%d ",j);
                newline = 1;
            }
        }
        if(newline == 1){
            printf("\n");
            newline = 0;
        }
    }
    //printf("\n");
}

void DFS(Grafo g) {
    cor c[g->v];
    int pi[g->v];
    int d[g->v];
    int f[g->v];

    for(int i = 0; i < g->v; i++) {
        c[i] = branco;
        pi[i] = -1;
    }

    timestamp_grafos = 0;
    for(int i = 0; i < g->v; i++) {
        if(c[i] == branco)
            DFS_visit(g,g->vetor[i],c,pi,d,f,i);
    }

    showArvore(g,d);
    /*printVet(c,g->v);
    printVet(pi,g->v);
    printVet(d,g->v);
    printVet(f,g->v);*/
}

void DFS_origem(Grafo g,int vertice) {
    cor c[g->v];
    int pi[g->v];
    int d[g->v];
    int f[g->v];

    for(int i = 0; i < g->v; i++) {
        c[i] = branco;
        pi[i] = -1;
    }

    timestamp_grafos = 0;
    DFS_visit(g,g->vetor[vertice],c,pi,d,f,vertice);
    //showArvore(g,d);
}





/*(e) Implemente a busca em largura a partir de um vertice de origem s, tal que imprima a arvore de
busca obtida.*/





void BFS(Grafo g,int vertice) {
    Fila* q = cria_fila_vazia();
    cor c[g->v];
    int pi[g->v];
    int d[g->v];
    int f[g->v];

    for(int i = 0; i < g->v; i++) {
        if(i != vertice) {
            c[i] = branco;
            d[i] =  INT_MAX;//maior valor de int = infinito.
            pi[i] = -1;
        }
    }

    c[vertice] = cinza;
    printf("%d ",vertice);//imprimir v�rtiuce visitado.
    pi[vertice] = -1;
    d[vertice] = 0;
    enqueue(q,vertice);

    while(!vaziaFila(q)){
        int *u = head(q);
        //printf("u = %d\n",*u);
        //printf("U = %d\n",*u);
        Lista* aux = g->vetor[*u];
        while(aux != NULL){
            int info = aux->info;
            if(c[info] == branco){
                //printf("%d ",info);
                c[info] = cinza;
                 printf("%d ",info);//imprimir v�rtiuce visitado.
                d[info] = d[*u] + 1;
                pi[info] = (*u);
                enqueue(q,info);
            }
            aux = aux->prox;
        }
        dequeue(q);
        c[*u] = preto;
        free(u);
    }
    printf("\n\n\n");
    //showArvore(g,d);
    /*printVet(c,g->v);
    printVet(pi,g->v);
    printVet(d,g->v);
    printVet(f,g->v);*/
}


void InicializaOrigem(Grafo g, int vertice,int d[], int pi[]){
    for(int i = 0; i < g->v; i++){
        d[i] =  INT_MAX;//maior valor de int = infinito. //PEDIR PARA O PROFESSOR, N�O FUNCIONOU COM NUMERO INFINITO, FUNCIONOU COM 0.
        pi[i] = -1;
    }
    d[vertice] = 0;
}


void Relax(Aresta a, int d[], int pi[]){
    if(d[a.w] > d[a.v] + a.peso && d[a.v] != INT_MAX){
        printf("Entrou relaxar !!!\n");
        d[a.w] = d[a.v] + a.peso;
        pi[a.w] = a.v;
    }
}



//p�s-condi��o: caso exista ciclo de peso negativo, o algoritmo retorna false
int Bellman_Ford(Grafo g,int origem){
    int d[g->v];
    int pi[g->v];

    InicializaOrigem(g,origem,d,pi);
    printVet(d,g->v);
    printVet(pi,g->v);

    Aresta e[g->v * g->v];
    int count_arestas = grafoArestas(e,g);



    for(int i = 0; i < g->v -1; i++){
        for(int j = 0; j < count_arestas; j++){
            Relax(e[j],d,pi);
        }
    }
    for(int i = 0; i < count_arestas; i++){
        if(d[e[i].w] > d[e[i].v] + e[i].peso && d[e[i].v] != INT_MAX)
            return 0;
    }

    printf("Imprimindo o vetor pi!!\n");
    printVet(pi,g->v);
    //imprimir os caminhos:
    printf("Origem: %d\n",origem);
    for(int i = 0; i < g->v; i++){
        printf("Destino:  %d dist.:  %d caminho:  ",i,d[i]);
        printCaminho(pi,i);
        printf("%d",i);
        printf("\n");
    }


    return 1;
}

void printCaminho(int pi[],int n){
    if(pi[n] != -1){
        printCaminho(pi,pi[n]);
        printf("%d ",pi[n]);
    }
}

//ORDENA��O TOPOL�GICA:

void DFS_visit_OT(Grafo g,Lista *v,cor c[],int pi[],int d[],int f[],int indice,Lista**l) {
    c[indice] = cinza;
    timestamp_grafos++;
    d[indice] = timestamp_grafos;
    while(v != NULL) {
        if(c[v->info] == branco) {
            pi[v->info] = indice;
            DFS_visit_OT(g,g->vetor[v->info],c,pi,d,f,v->info,l);
        }
        v = v->prox;
    }
    c[indice] = preto;
    timestamp_grafos++;
    f[indice] = timestamp_grafos;
    (*l) = inserir(*l,indice);
}


Lista* DFS_OT(Grafo g) {
    Lista* l = NULL;
    cor c[g->v];
    int pi[g->v];
    int d[g->v];
    int f[g->v];

    for(int i = 0; i < g->v; i++) {
        c[i] = branco;
        pi[i] = -1;
    }

    timestamp_grafos = 0;
    for(int i = 0; i < g->v; i++) {
        if(c[i] == branco)
            DFS_visit_OT(g,g->vetor[i],c,pi,d,f,i,&l);
    }
    return l;
}


Lista* ordenacaoTopologica(Grafo g){
    Lista* l = DFS_OT(g);
    return l;
}
