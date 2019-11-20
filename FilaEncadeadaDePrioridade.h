#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim;
    No* ult;
    int qtde;
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

Fila *fila_criar(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->qtde = 0;
}

void fila_destruir(Fila *f){
    No* aux = f->prim;
    No* aux2;
    for(int i = 0; i < f->qtde; i++){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(f);
}

Boolean fila_inserir(Fila *f, Tipo elemento){
    if(f == NULL)  return false;
    No* n = (No*) malloc(sizeof(No*));
    n->dado = elemento;
    No* aux = f->prim;
    No* aux2;
    int flag = 0;
    for(int pos = 0; pos < f->qtde; pos++){
        if(elemento < aux->dado){
            n->prox = aux;
            if(f->qtde == 1)    
                f->prim = n;
            else    
                aux2->prox = n;
            flag++;
            break;
        }
        aux2 = aux;
        aux = aux->prox;
    }
    if(flag == 0){
        if(f->ult != NULL)  f->ult->prox = n;
        f->ult = n;
        if(f->prim == NULL)
            f->prim = n;
    }
    f->qtde++;
    return true;
}

Tipo *fila_remover1(Fila *f){
    if(f->prim == NULL) return NULL;
    Tipo* temp = (Tipo*) malloc(sizeof(Tipo));
    No* temp1 = f->prim;
    *temp = f->prim->dado;
    f->prim = f->prim->prox;
    free(temp1);
    if(f->qtde == 1)
        f->ult == NULL;
    f->qtde--;
    return temp;
}

Boolean fila_remover2(Fila *f, Tipo *endereco){
    if(f->prim == NULL) return false;
    No *temp1 = f->prim;
    *endereco = f->prim->dado;
    f->prim = f->prim->prox;
    free(temp1);
    if (f->qtde == 1)
        f->ult == NULL;
    f->qtde--;
    return true;
}

Boolean fila_primeiro(Fila *f, Tipo *endereco){
    if(f->prim == NULL) return false;
    *endereco = f->prim->dado;
    return true;
}

int fila_tamanho(Fila *f){
    return f->qtde;
}

int fila_contem(Fila *f, Tipo elemento){
    No* aux = f->prim;
    for(int i = 0; i < f->qtde; i++){
        if(elemento == aux->dado)
            return i;
        aux = aux->prox;
    }
    return -1;
}

void fila_imprimir(Fila *f){
    No* aux = f->prim;
    printf("[ ");
    for(int i = 0; i < f->qtde; i++){
        printf("%d ",aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}