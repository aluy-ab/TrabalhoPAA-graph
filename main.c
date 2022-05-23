#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "grafos.h"
#include "listas.h"
#include "arquivo.h"

int main() {
    char nome_arquivo[30];
    setlocale(LC_ALL, "Portuguese");
    Grafo g = NULL;
    //ler o grafo do arquivo
    while(g == NULL) {
        printf("Carregar Grafo\n");
        printf("Digite o nome do arquivo\n");
        scanf("%s[^\n]",nome_arquivo);
        g = ler_grafo(nome_arquivo);
    }


    int option = 0;
    int origem = 0;
    do {
        printf("Escolha uma op��o:\n");
        printf("0.Busca em Profundidade\n");
        printf("1.Busca em Largura\n");
        printf("2.Bellman-Ford\n");
        printf("3.Kruskal\n");
        printf("4.Prim\n");
        printf("5.Sair\n");
        scanf("%d",&option);
        switch(option) {
        case 0:
            printf("Digite o v�rtice de origem!\n");
            scanf("%d",&origem);
            DFS_origem(g,origem);
            printf("\n");
            break;

        case 1:
            printf("Digite o v�rtice de origem!\n");
            scanf("%d",&origem);
            BFS(g,origem);
            printf("\n");
            break;
        case 2:
            if(!g->orientado) {
                printf("O grafo carregado n�o � orientado! Bellman Ford precisa Grafo Orientado!\n");
            } else {
                printf("Digite o v�rtice de origem!\n");
                scanf("%d",&origem);
                Bellman_Ford(g,origem);
            }
            break;
        case 3:


        case 4:
        case 5:


            break;
        default:
            printf("Escolha uma op��o v�lida!\n");

        }
    } while(option != 5);


    printf("\n\n\n\n\n");
    imprimirGrafo(g);
    printf("Ordena��o Topol�gica: \n");
    Lista* ord = ordenacaoTopologica(g);
    imprimir(ord);
    return 0;
}

