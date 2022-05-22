#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "grafos.h"
#include "listas.h"
#include "arquivo.h"

int main()
{
    char nome_arquivo[30];
    setlocale(LC_ALL, "Portuguese");

    //ler o grafo do arquivo
    printf("Carregar Grafo\n");
    printf("Digite o nome do arquivo\n");
    scanf("%s[^\n]",nome_arquivo);
    Grafo g = ler_grafo(nome_arquivo);



    int option = 0;
    int origem = 0;
		do {
			printf("Escolha uma opção:\n");
			printf("0.Busca em Profundidade\n");
			printf("1.Busca em Largura\n");
			printf("2.Bellman-Ford\n");
			printf("3.Kruskal\n");
			printf("4.Prim\n");
			printf("5.Sair\n");
			scanf("%d",&option);
			switch(option) {
			case 0:
			    printf("Digite o vértice de origem!\n");
			    scanf("%d",&origem);
			    DFS_origem(g,origem);
			    break;

			case 1:
			    printf("Digite o vértice de origem!\n");
			    scanf("%d",&origem);
			    BFS(g,origem);
			    break;

            case 3:
            case 4:
            case 5:


                break;
            default:
                printf("Escolha uma opção válida!\n");

			}
    }while(option != 5);


    printf("\n\n\n\n\n");
    imprimirGrafo(g);
    printf("Ordenação Topológica: \n");
    Lista* ord = ordenacaoTopologica(g);
    imprimir(ord);
    return 0;
}

