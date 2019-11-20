#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* sentinela;
    int qtde;
}Lista;


Lista* lista_criar();
Lista* lista_destruir(Lista* l);

void lista_inserir(Lista* l, Tipo elemento, int posicao);
void lista_inserir_fim(Lista* l, Tipo elemento);

int* lista_remover1(Lista* l, int posicao);
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);
Boolean lista_remover_elemento(Lista* l, Tipo elemento);


Boolean lista_buscar(Lista* l, int posicao, int* endereco);
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);

int lista_tamanho(Lista* l);
void lista_imprimir(Lista* l);

Lista* lista_criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->sentinela = (No*) malloc(sizeof(No));
    l->sentinela->prox = l->sentinela->ant = l->sentinela;
    l->qtde = 0;
    return l;
}

Lista* lista_destruir(Lista *l){
    No* aux = l->sentinela->prox;
    No* aux2;
    for(int i = 0; i <= l->qtde; i++){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(l->sentinela);
    free(l);
    return NULL;
}

/*
    Busca Nó
                */

No* getNo(Lista* l, int posicao){
    No* aux = l->sentinela;
    if(l->qtde - posicao > posicao){
        for(int i = l->qtde-1; i >= posicao; i--){
            aux = aux->ant;
        }
    }
    else if(l->qtde - posicao < posicao){
        for(int i = 0; i < posicao; i++){
            aux = aux->prox;
        }
    }
    else{
        for(int i = 0; i < posicao; i++){
                aux = aux->prox;
        }
    }
    return aux;
}

/*
    Cria Nó
                */

No* criaNo(Tipo elemento, No* anterior, No* proximo){
    No* n = (No*) malloc(sizeof(No));
    n->dado = elemento;
    n->ant = anterior;
    n->prox = proximo;
    return n;
}

void lista_inserir(Lista *l, Tipo elemento, int posicao){
    if(posicao < 0 || posicao > l->qtde)    return;
    if(l == NULL)   return;

    No* aux = getNo(l,posicao);
    No* novo = criaNo(elemento,aux,aux->prox);
    aux->prox->ant = novo;
    aux->prox = novo;
    l->qtde++;
}

void lista_inserir_fim(Lista *l, Tipo elemento){
    if(l == NULL)   return;

    No* n = criaNo(elemento,l->sentinela->ant,l->sentinela);
    l->sentinela->ant->prox = n;
    l->sentinela->ant = n;
    l->qtde++;
}

int* lista_remover1(Lista *l, int posicao){
    if(posicao < 0 || posicao > l->qtde)    return NULL;
    if(l == NULL)   return NULL;
    if(l->qtde == 0)    return NULL;

    No* aux = getNo(l,posicao);
    int* elemento = (int*) malloc(sizeof(int));
    *elemento = aux->dado;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    l->qtde--;
    free(aux);
    return elemento;
}

Boolean lista_remover2(Lista *l, int posicao, Tipo *endereco){
    if(posicao < 0 || posicao > l->qtde)    return false;
    if(l == NULL)   return false;
    if(l->qtde == 0)    return false;

    No* aux = getNo(l,posicao);
    *endereco = aux->dado;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    l->qtde--;
    free(aux);
    return true;
}

Boolean lista_remover_elemento(Lista *l, Tipo elemento){
    if(l == NULL)   return false;
    if(l->qtde == 0)    return false;
    
    No* aux;
    aux = l->sentinela;
    for(int i = 0; i <= l->qtde; i++){
        if(elemento == aux->dado)
            break;
        aux = aux->prox;
    }
    if(aux != l->sentinela){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        l->qtde--;
        free(aux);
        return true;
    }
    return false;
}

Boolean lista_buscar(Lista *l, int posicao, int *endereco){
    if(posicao < 0 || posicao > l->qtde)    return false;
    if(l == NULL)   return false;
    if(l->qtde == 0)    return false;

    No* aux = getNo(l,posicao);
    *endereco = aux->dado;
    return true;
}

Boolean lista_contem(Lista *l, Tipo elemento){
    if(l == NULL)   return false;
    if(l->qtde == 0)    return false;

    No* aux = l->sentinela;
    for(int i = 0; i <= l->qtde; i++){
        if(elemento == aux->dado)
            return true;
        aux = aux->prox;
    }
    return false;
}

int lista_posicao(Lista *l, Tipo elemento){
    if(l == NULL)   return -1;
    if(l->qtde == 0)    return -1;
    No* aux = l->sentinela->prox;
    for(int i = 0; i < l->qtde; i ++){
        if(aux->dado == elemento)
            return i;
        aux = aux->prox;
    }
    return -1;
}

int lista_tamanho(Lista *l){
    if(l == NULL)   return -1;
    return l->qtde;
}

void lista_imprimir(Lista* l){
    if(l == NULL)   return;
    if(l->sentinela == NULL)    return;
    if(l->qtde <= 0)    return;
    No* aux = l->sentinela->prox;
    printf("[ %d",aux->dado);
    aux = aux->prox;
    for(int i = 0; i < l->qtde-1; i++){
        printf(", %d",aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}