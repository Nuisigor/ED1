#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;
}Pilha;

Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
void pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);

Pilha* pilha_criar(){
    Pilha* p1= (Pilha*) malloc(sizeof(Pilha));
    p1->vetor = (Tipo*) calloc(N, sizeof(Tipo)); 
    p1->qtde = 0;
    p1->tam = N;
    return p1;
}

Boolean pilha_push(Pilha *p, Tipo elemento){
    p->vetor[p->qtde] = elemento;
    p->qtde++;
    return true;
}

Tipo *pilha_pop1(Pilha *p){
    Tipo* retorno = (Tipo*) malloc(sizeof(Tipo));
    *retorno = p->vetor[p->qtde -1];
    p->qtde--;
    return retorno;
}

Boolean pilha_pop2(Pilha *p, Tipo *end){
    if(p->vetor[p->qtde - 1] !=NULL){
        *end = p->vetor[p->qtde - 1];
        p->qtde--;
        return true;
    }
    else
        return false;
}

void pilha_destruir(Pilha *p){
    free(p->vetor);
    free(p);
}

void pilha_imprimir(Pilha *p){
    for(int i = 0; i < p->qtde; i++){
        if(i == 0)
            printf("[ %d", p->vetor[i]);
        printf(", %d",p->vetor[i]);
    }
    printf("]");
}

int pilha_posicao(Pilha *p, Tipo elemento){
    
    for(int  i = 0; i < p->qtde; i++){
        if(p->vetor[i] == elemento)
            return i;
    }
    return -1;
}

int pilha_tamanho(Pilha* p){
    return p->qtde;
}

int pilha_pushAll(Pilha *p, Tipo *vetor, int tam){
    for(int i = 0; i < tam; i++){
        pilha_push(p, vetor[i]);
    }
    return tam;
}

void pilha_inverter(Pilha* p){
    Tipo* inverso = (Tipo*) calloc(p->tam, sizeof(Tipo));
    for(int i = p->qtde - 1, j = 0; i > 0; i--){
        inverso[j] = p->vetor[i];
    }
    free(p->vetor);
    p->vetor = inverso;
}

Pilha* pilha_clone(Pilha* p){
    Pilha* p1 = pilha_criar();
    p1 ->tam = p->tam;
    p1 ->qtde = pilha_pushAll(p1, p->vetor, p->qtde);
    return p1;
}