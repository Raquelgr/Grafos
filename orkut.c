/* Grupo 4 - Tema 4 (Orkut)
 * Alunos: Luisa Katsuda, Raquel Gonçalves, Thiago Cassiano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orkut.h"
 
Grafo *cria_grafo(int v){
    //aloca memoria para grafo
    Grafo *gf = (Grafo*)malloc(sizeof(Grafo));
 
    gf->num_Vertices = v;
    gf->num_Arestas = 0;
 
    //aloca memoria para os vertices
    gf->no = (Vertice*)malloc(v * sizeof(Vertice));
 
    int i;
 
    //como os nos nao tem arestas
    //inicia a lista de adjacencia
    //com NULL
    for(i = 0; i < v; i++){
        gf->no[i].nos_adj = NULL;
    }
 
    return gf;
}
 
Lista_adj *cria_lista_adj(int v, Tipo_Ponderado peso){
    //Aloca espaco para um no na lista de adjacencia
    Lista_adj *list = (Lista_adj*)malloc(sizeof(Lista_adj));
    list->vertice = v;
    list->peso = peso;
    list->prox = NULL;
 
    return list;
}
 
int cria_aresta(Grafo *gf, int vi, int vf, Tipo_Ponderado peso){
    //caso nao exista grafo
    if(!gf){
        return -1;
    }
 
    //caso o vertice seja menor que 0 ou maior que
    //o numero de vertices
    if(vf < 0 || (vf >= gf->num_Vertices)){
        return -1;
    }
 
    //caso o vertice seja menor que 0 ou maior que
    //o numero de vertices
    if(vi < 0 || (vi >= gf->num_Vertices)){
        return -1;
    }
 
    //caso já exista nao uma aresta com esses vertices
    //nao cria outra
    Lista_adj *adj = gf->no[vi].nos_adj;
 
    while(adj){
        if(adj->vertice == vf){
            return -1;
        }
        adj = adj->prox;
    }
 

    Lista_adj *new2 = cria_lista_adj(vi, peso);
 
    new2->prox = gf->no[vf].nos_adj;
 
    gf->no[vf].nos_adj = new2;
    gf->num_Arestas++;
 
    return 1;
}
 
 
void destroi_grafo(Grafo *gf){
    int i;

    for(i = 0; i < gf->num_Vertices; i++){
        Lista_adj *adj = gf->no[i].nos_adj;
        Lista_adj *aux = adj;

        while(adj){
            aux = adj->prox;
            free(adj);
            adj = aux;
        }
 
    }
 
    free(gf->no);
    free(gf);
 
}



int procura_id(Grafo *gf, char nome[], int qtd) {
  int i;

    for (i = 0; i < qtd; i++){
        if (strcmp(gf->no[i].nome, nome)==0){
            
        return i;
        }
    }
}


void profundidade(Grafo *gf, int inicio, int qtd){
    int *cor = (int*)calloc(gf->num_Vertices,sizeof(int));
    int i, aux;
    i = inicio; 
    int vet[gf->num_Vertices];
    aux = 0;


    procura_nome(gf, inicio, qtd);

    if(cor[i] == BRANCO){
        visitaP(gf,i,cor,vet,aux);
        printf("\n\n");
    }

    destroi_grafo(gf);

}

void visitaP(Grafo *gf, int u, int *cor, int vet[], int aux){

    cor[u] = CINZA;
    Lista_adj *v = gf->no[u].nos_adj;

    while(v){

        if(cor[v->vertice] == BRANCO){
            vet[aux] = v->vertice;
            procura_nome(gf, vet[aux], gf->num_Vertices);
            aux++;
            visitaP(gf,v->vertice,cor,vet,aux);
        }
        
        v = v->prox;
    }


    cor[u] = PRETO;  
}


void procura_nome(Grafo *gf, int id, int qtd) {
    int i;
    char res[16];


    for (i = 0; i < qtd; i++){
        if (gf->no[i].identificador == id){
            strcpy(res, gf->no[i].nome);
            printf("%s ", res);
        }
    }
}
