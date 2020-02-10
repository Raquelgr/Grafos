/* Grupo 4 - Tema 4 (Orkut)
 * Alunos: Luisa Katsuda, Raquel Gonçalves, Thiago Cassiano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "orkut.h"
#define MAX 30



int main(){

	int i, j, k, p, w;
	int qtd, relacoes[30], resul, result, num, inicial;
	char nome[16], nome1[16], nome2[16];

	num = 0;
	inicial = -3;

	for(w = 0; w < 30; w++){
		relacoes[w] = -1;
	}
	
	
	printf("Digite a quantidade de amigos:\n");
	scanf("%d", &qtd);

	Grafo *g = cria_grafo(qtd);

	printf("\nDigite o nome de cada amigo(por favor, separe os nomes por um espaço em branco):\n");
	
	for(i = 0; i < qtd; i++){
		scanf("%s", g->no[i].nome);
		g->no[i].identificador = num++;
	}

	printf("\nDigite o pré-requisito de cada amigo(respeitando a ordem passada anteriormente):\n");

	for(j = 0; j < qtd; j++){
		scanf("%s %i", nome1, &relacoes[j]);
	    result = procura_id(g, nome1, qtd);

		for(k = 0; k < relacoes[j]; k++){
			scanf(" %s", nome2);
			resul = procura_id(g, nome2, qtd);

			if(result != resul){
			cria_aresta(g, g->no[result].identificador, g->no[resul].identificador, 0);
			}
		}
	} 

	printf("\n");

	for(p = 0; p < qtd; p++){

		if(relacoes[p] == 0 &&  g->no[p].nos_adj == NULL){
			procura_nome(g, p, qtd);
		} else if(relacoes[p] == 0 &&  g->no[p].nos_adj != NULL){
			inicial = p;
			break;
		}
	}
			

	if(inicial == -3){
		printf("Impossível montar uma sequência!\n");
	} else {
		profundidade(g, inicial, qtd);
	}


}


