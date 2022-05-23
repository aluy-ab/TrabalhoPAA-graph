#ifndef LISTAS_H_
#define LISTAS_H_

#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem; // tipo dos elementos na lista

typedef struct no { //estrutura para lista encadeada
    TipoItem info;
    TipoItem peso;
    struct no * prox; // ponteiro para proximo elemento
} Lista;



//testa se uma lista � vazia
//Entrada: lista
//Retorno: 1se lista � vazia ou 0 caso contr�rio
//pre condi�ao : nennhuma
//P�s-condi�ao : nenhuma
int vazia(Lista *l) ;
//insere um eleemento na lista
//Entrada: llista e elemento a ser inserido
//Retorno: lista alterada
//Pr�-condi��o: nenhuma
//P�s_condi��o: elemento � inserido na lista.
Lista* inserirComPeso(Lista* l, TipoItem info, TipoItem peso);
Lista* inserir(Lista* l, TipoItem info);
//Remove um elemento da lista
//entrada: listae elemento a ser removido
//retorno: lista alterada
//pr�_condi�ao: nenhuma
//P�s-condi��o: elemento e removido da lista.
Lista* remover(Lista* l, TipoItem info);

//Imprime os elementos da lista
//Entrada : lista
//Retorn: nenhum
//Pr�-condi��o: nenhuma
//P�s-Condi��o: os elementos sao impressos no console
void imprimir(Lista* l) ;
//Inverte um lista
//Entrada: Lista
//Retorno: lista invertida
//Pr�-Condi��o: nenhuma
//P�s-condi��o: lista original n�o � modificada
Lista* inverter(Lista* l);

//Copia uma lista e retonar ela
//entrada: lista a ser copiada
//Pr�-condi�ao: nenhuma
//P�s-Condi��es: lista copiada ponteiro
Lista* copiar(Lista* copia) ;

Lista* FindUltimo(Lista* l) ;
//concatena duas listas
//entrada: listas a serem concatenadas
//retorno: lista resultante da concaten��o
//Pr�-condi��o: nenhuma
//P�s-condi��es: listas originais nao sao modificadas
Lista* concatenar(Lista* l1, Lista* l2);
//Intercala duas listas
//Enntrada: Listas a serem intercaladas
//Retorno: lita resultante da intercala��o
//Pr�-condi��o: nenhuma
//P�s-condi��o: listas originais permancem inalteradas
Lista* intercalar(Lista* l1, Lista* l2) ;
//pre- requisito: nenhum
//P�s-requisitov: l1 � modificada
Lista* append(Lista* l1, Lista* l2) ;
int conta_ocorrencias(Lista* l,TipoItem x) ;
Lista* elimina_repetidos(Lista* l);

Lista* pares(Lista* l);

int elementosLista(Lista* l);
Lista* ordenar(Lista* l);
Lista* busca(Lista* l, TipoItem info);


#endif
