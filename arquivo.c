#include "arquivo.h"

Grafo ler_grafo(char* nome_arquivo){
    FILE* arquivo = fopen(nome_arquivo, "r");//abre para leitura o arquivo
    char orientado[4];
    int num_vertices = 0;
    Grafo g = NULL;
	if (arquivo == NULL)
	{
		printf("Não foi possível abrir o arquivo\n");
		return NULL;
	}

	    //le se é orietnado ou não:
		fscanf(arquivo, "%*[ ]");//le espaços em branco.
		fscanf(arquivo, "%*[^=]");
		fscanf(arquivo, "%*c");
		fscanf(arquivo, "%s",orientado);

		fscanf(arquivo, "%*[ ]");//le espaços em branco.
		fscanf(arquivo, "%*[^=]");
		fscanf(arquivo, "%*c");
		fscanf(arquivo, "%d",&num_vertices);

		int orientado_numero = 0;
		if(orientado[0] == 's'){
            orientado_numero = 1;
		}

		g = inicializa(num_vertices,orientado_numero);

		int v = 0;
		int w = 0;
		int peso = 0;
	while (1)
	{
	    //le o vertice v
	    fscanf(arquivo, "%*[ ]");//le espaços em branco.
		fscanf(arquivo, "%*[^(]");
		fscanf(arquivo, "%*c");
		fscanf(arquivo, "%d",&v);

        fscanf(arquivo, "%*[ ]");//le espaços em branco.
		fscanf(arquivo, "%*[^,]");
		fscanf(arquivo, "%*c");
		fscanf(arquivo, "%d",&w);

		fscanf(arquivo, "%*[ ]");//le espaços em branco.
		fscanf(arquivo, "%*[^:]");
		fscanf(arquivo, "%*c");
		fscanf(arquivo,"%d",&peso);

        //insere uma aresta lida no grafo.
	    grafoInsere(g,ARESTA(v,w,peso));
		if (feof(arquivo))
		{
			break;
		}

	}
	fclose(arquivo);
	return g;

}
