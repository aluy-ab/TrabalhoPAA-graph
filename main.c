#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include "grafos.h"
#include "listas.h"


int main()
{
    char nome_arquivo[30];
    setlocale(LC_ALL, "Portuguese");

    printf("Carregar Grafo\n");
    printf("Digite o nome do arquivo\n");
    scanf("%s[^\n]",nome_arquivo);
    printf(nome_arquivo);

    Grafo g = ler_grafo("grafo1.txt");

    imprimirGrafo(g);
    printf("Ordenação Topológica: \n");
    Lista* ord = ordenacaoTopologica(g);
    imprimir(ord);
    return 0;
}

