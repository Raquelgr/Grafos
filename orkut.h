/* Grupo 4 - Tema 4 (Orkut)
 * Alunos: Luisa Katsuda, Raquel Gonçalves, Thiago Cassiano
 */

#ifndef ORKUT_H
#define ORKUT_H

#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef int Tipo_Ponderado;
 
//cria uma lista de adjacencia
typedef struct lista_adj{
    int vertice; //vertice de destino
    Tipo_Ponderado peso;  //guarda o numero de arestas de um grafo
    struct lista_adj *prox;
}Lista_adj;

typedef struct vertice{
	char nome[16]; 
	int identificador;
    Lista_adj *nos_adj; //lista de nos adjacentes
}Vertice;
 
//Estrutura de um grafo
typedef struct grafo{
    int num_Vertices; //guarda o numero de vertices em um grafo
    int num_Arestas;  //guarda o numero de arestas de um grafo
    Vertice *no;    //vetor de vertices
}Grafo;

typedef struct pilha{
	Lista_adj *prim;
}Pilha;


/** \brief Cria um grafo com
 *         um numero especifico
 *         de nos, porem sem
 *         arestas
 *
 * \param  numero de nos do grafo
 * \return ponteiro para grafo
 *         criado
 *
 */
Grafo *cria_grafo(int v);
 
/** \brief Cria uma adjacencia
 *         entre um no
 *
 * \param  numero de nos do grafo
 * \return ponteiro para elemento
 *         criado
 *
 */
Lista_adj *cria_lista_adj(int v, Tipo_Ponderado peso);
 
/** \brief Cria uma aresta
 *         entre dois nos
 *
 * \param  ponteiro para grafo
 * \param  vertice de uma ponta
 * \param  vertice de outra ponta
 * \param  peso da aresta
 * \return 1 - operacao concluida com sucesso
 *        -1 - operacao nao pode ser concluida
 *
 */
int cria_aresta(Grafo *gf, int vi, int vf, Tipo_Ponderado peso);
 
/** \brief Destroi um grafo
 *
 * \param  ponteiro para grafo
 * \return void
 *
 */
void destroi_grafo(Grafo *gf);

/** \brief Busca em profundidade
 *
 * \param ponteiro para grafo
 * \param indice do nó inicial
 * \param indice da quantidade de amigos
 * \return void
 *
 */
void profundidade(Grafo *gf, int inicio, int qtd);
 
/** \brief Busca em profundidade
 *
 * \param ponteiro para grafo
 * \param indice do no
 * \param ponteiro vetor de cor
 * \param vetor que armazena os indices do vertices no decorrer da busca
 * \param auxiliar para o vetor
 * \return void
 *
 */
void visitaP(Grafo *gf, int u, int *cor, int vet[], int aux);

/**\brief Procura identificador do amigo
 *
 * \param ponteiro para o grafo
 * \param nome do amigo, cujo identificador será procurado
 * \param indice da quantidade de amigos
 * \return identificador
 *
 */  
int procura_id(Grafo *gf, char nome[], int qtd);

/**\brief Procura nome do amigo
 *
 * \param ponteiro para o grafo
 * \param identificador do amigo, cujo nome será procurado
 * \param indice da quantidade de amigos
 * \return void
 *
 */  
void procura_nome(Grafo *gf, int id, int qtd);

#endif //ORKUT_H
