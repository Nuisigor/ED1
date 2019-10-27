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
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
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
Pilha* pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);


/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */
Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->qtde = 0;
    return p;
}

/**
 * Desaloca a pilha <p>.
 */
void pilha_destruir(Pilha* p){
    No* aux1 = p->topo;
    No* aux2;
    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = aux1->prox;
        free(aux2);
    }
    free(aux1);
    free(p);
}

/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */
Boolean pilha_push(Pilha* p, Tipo elemento){
    No* temp = (No*) malloc(sizeof(No));
    temp->dado = elemento;
    temp->prox = p->topo;
    p->qtde++;
    p->topo = temp;
    return true;
}


/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
 */
Tipo* pilha_pop1(Pilha* p){
    if(p->topo !=NULL){
        Tipo* temp = (Tipo*) malloc(sizeof(Tipo));
        *temp = p->topo->dado;
        p->topo = p->topo->prox;
        p->qtde--;
        free(temp);
        return temp;
    }
    else
        return NULL;
}

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço 
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */
Boolean pilha_pop2(Pilha* p, Tipo* end){
    if(p->topo == NULL)
        return false;
    *end = p->topo->dado;
    p->topo = p->topo->prox;
    p->qtde--;
    return true;
}


/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */
void pilha_imprimir(Pilha* p){
    No* temp = p->topo;
    printf("[");
    for(int i = 0; i < p->qtde; i++){
        printf("%d ",temp->dado);
        temp = temp->prox;
    }
    printf("]");
}

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */
int pilha_posicao(Pilha* p, Tipo elemento){
    No* temp = p->topo;
    for(int i = 0; i < p->qtde; i++){
        if(temp->dado == elemento)
            return i;
    }
    return -1;
}

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */
int pilha_tamanho(Pilha* p){
    return p->qtde;
}

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    int qtde = 0;
    for(int i = 0; i < tam; i ++){
        if(vetor[i] != NULL){
            No* temp;
            temp->dado = vetor[i];
            temp->prox = p->topo;
            p->topo = temp;
            p->qtde++;
            qtde++;
        }
    }
    return qtde;
}

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 */
Pilha* pilha_inverter(Pilha* p){
    Pilha* p1 = pilha_criar();
    No* aux = p->topo;
    while(aux != NULL){
        pilha_push(p1,aux->dado);
        aux = aux->prox;
    }
    p1->qtde = p->qtde;
    pilha_destruir(p);
    return p1;
}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */
Pilha* pilha_clone(Pilha* p){
    Pilha* clone = (Pilha*) malloc(sizeof(Pilha));
    No* caminho = p->topo;
    No* temp;
    for(int i = 0; i < p->qtde; i++){
        No* dado = (No*) malloc(sizeof(No));
        dado->dado = caminho->dado;
        
        if(i == 0)
            clone->topo = dado;
        else 
            temp->prox = dado;
        
        temp = dado;
        caminho = caminho->prox;
    }
    return clone;
}

