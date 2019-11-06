#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;    
}FilaPrioridade;


FilaPrioridade* fila_criar(int tam);
void fila_destruir(FilaPrioridade* f);

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento);
Boolean fila_remover(FilaPrioridade* f, Tipo* endereco);

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco);
int fila_tamanho(FilaPrioridade* f);
int fila_contem(FilaPrioridade* f, Tipo elemento);
void fila_imprimir(FilaPrioridade* f);

FilaPrioridade* fila_criar(int tam){
    if(tam <= 0)    return NULL;
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->vetor = (Tipo*) calloc(tam,sizeof(Tipo));
    f->qtde  = 0;
    f->tam = tam;
    return f;
}

void fila_destruir(FilaPrioridade* f){
    free(f->vetor);
    free(f);
}

void troca(Tipo* a, Tipo* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int pai(int j){
    return ((j-1)/2);
}

void sobeHeap(FilaPrioridade* f, int pos){
    if(f->vetor[pos] <= f->vetor[pai(pos)]) return;
    troca(&f->vetor[pos],&f->vetor[pai(pos)]);
    sobeHeap(f, pai(pos));
}

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento){
    if(f == NULL)   return false;
    if(f->qtde == f->tam)    return false;

    f->vetor[f->qtde] = elemento;
    sobeHeap(f,f->qtde);
    f->qtde++;
    return true;
}
int filhoEsquerda(int i){
    return i*2+1;
}

int filhoDireita(int i){
    return i*2+2;
}

void desceHeap(FilaPrioridade* f, int pos){
    if(filhoEsquerda(pos) < f->qtde){
        int maiorFilho = filhoEsquerda(pos);
        int filhoaDireita = (filhoDireita(pos) < f->qtde ? 1 : 0);
        if(filhoaDireita && f->vetor[filhoDireita(pos)] > f->vetor[filhoEsquerda(pos)])
            maiorFilho = filhoDireita(pos);
        
        if(f->vetor[pos] < f->vetor[maiorFilho]){
            troca(&f->vetor[pos],&f->vetor[maiorFilho]);
            desceHeap(f,maiorFilho);
        }
    }
}


Boolean fila_remover(FilaPrioridade* f, Tipo* endereco){
    if(f == NULL)   return false;
    if(f->qtde == 0)    return false;

    *endereco = f->vetor[f->qtde-1];
    troca(&f->vetor[0], &f->vetor[f->qtde-1]);
    f->qtde--;
    desceHeap(f,0);
}

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco){
    if(f == NULL)   return false;
    if(f->qtde == 0)    return false;
    
    *endereco = f->vetor[0];
    return true;
}

int fila_tamanho(FilaPrioridade* f){
    return f->qtde;
}

int fila_contem(FilaPrioridade* f, Tipo elemento){
    for(int i = 0 ; i < f->qtde; i++)
        if(f->vetor[i] == elemento)
            return i;
    return -1;
}

void fila_imprimir(FilaPrioridade* f){
    printf("[%d",f->vetor[0]);
    for(int i = 0; i < f->qtde; i++){
        printf(", %d", f->vetor[i]);
    }
    printf("]\n");
}