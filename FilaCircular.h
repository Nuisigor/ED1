
#include <stdio.h>
#include <stdlib.h>
#define N 5


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;


Fila* fila_criar();
void fila_destruir(Fila* f);

Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);

Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);

Fila* fila_criar(){
    Fila* p = (Fila*) malloc(sizeof(Fila));
    p->vetor = (Tipo*) calloc(N, sizeof(Tipo));
    p->tam = N;
    p->inicio = 0;
    p->fim = 0;
    return p;
}

void fila_destruir(Fila* f){
    free(f->vetor);
    free(f);
}

/**/

void fila_duplica(Fila*f){
    Tipo* dobro = (Tipo*) calloc(f->tam*2, sizeof(Tipo));
    int i,j;
    for(i = 0, j = f->inicio; j < f->fim; i++, j++){
        dobro[i] = f->vetor[j%f->tam];
    }
    free(f->vetor);
    f->vetor = dobro;
    f->inicio = 0;
    f->fim = i ;
    f->tam *= 2;
}

/**/

Boolean fila_inserir(Fila* f, Tipo elemento){
    if(f->inicio%f->tam == f->fim%f->tam && f->inicio != f->fim)
        fila_duplica(f);
    f->vetor[f->fim] = elemento;
    f->fim++;
    return true;
}

/**/

void fila_metade(Fila* f){
    Tipo* metade = (Tipo*) calloc(f->tam/2, sizeof(Tipo));
    int i,j;
    for(i = 0, j = f->inicio; j < f->fim; i++, j++){
        metade[i] = f->vetor[j%f->tam];
    }
    free(f->vetor);
    f->vetor = metade;
    f->inicio = 0;
    f->fim = i;
    f->tam /= 2;
}

/**/

Tipo* fila_remover1(Fila* f){
    if(f->fim != f->inicio){
        Tipo* elemento = (Tipo*) malloc(sizeof(Tipo));
        *elemento = f->vetor[f->inicio%f->tam]; 
        f->inicio++;
        if(((f->fim - f->inicio)/f->tam < 0.25) && f->tam != N)
            fila_metade(f);
        return elemento;
    }
    else
        return NULL;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
    if(f->fim != f->inicio){
        *endereco = f->vetor[f->inicio%f->tam]; 
        f->inicio++;
        if(((f->fim - f->inicio)/f->tam < 0.25) && f->tam != N)
            fila_metade(f);
    }
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f->fim == f->inicio)
        return false;
    else{
        *endereco = f->vetor[f->inicio];
        return true;
    }
}

int fila_tamanho(Fila* f){
    return (f->fim - f->inicio);
}

int fila_contem(Fila* f, Tipo elemento){
    for(int i = f->inicio; i < f->fim; i++){
        if(f->vetor[f->inicio%f->tam] == elemento){
            return i;
        }
    }
    return -1;
}

void fila_imprimir(Fila* f){
    for(int i = f->inicio; i < f->fim; i++){
        if(i == f->inicio)
            printf("[%d",f->vetor[i%f->tam]);
        else
            printf(", %d",f->vetor[i%f->tam]);
    }
    printf("]\n");
}