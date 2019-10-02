#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cod[6];
    char *nome;
    float *preco;
    int qtde; // qtde de produtos no estoque
    int qtdePrecos; // qtde de preços
}Produto;

typedef struct{
    char* nome;
    Produto** produtos;
    int qtde; // qtde de produtos
    int tam; // Tam do vetor;
}Empresa;

Produto *novoProduto(char *cod, char *desc, float preco, int qtde){
    Produto* prod = (Produto*) malloc(sizeof(Produto));
    strcpy(prod->cod,cod);
    prod->nome = (char*) calloc(strlen(desc),sizeof(char));
    strcpy(prod->nome,desc);
    prod->preco = (float*) malloc(sizeof(float));
    *prod->preco = preco;
    prod->qtde = qtde;
    prod->qtdePrecos = 1;
    return prod;
}

void print(Produto *p){
    printf("Codigo : %s\n",p->cod);
    printf("Nome : %s\n",p->nome);
    printf("Preço : %f\n",*(p->preco));
    printf("Qtde : %d\n",p->qtde);
    printf("Qtde de preços: %d\n",p->qtdePrecos);
}

float mediaDePreco(Empresa *e){
    float quantidade = 0, precototal = 0;
    for(int i = 0; i < e->qtde; i++){
        if(e->produtos[i]->qtdePrecos > 1){
            float quantidap = 0,precototalp = 0;
            for(int j = 0; j < e->produtos[i]->qtdePrecos; j++){
                quantidap += 1;
                precototalp += *(e->produtos[i]->preco + j);
            }
            precototal += precototalp/quantidap;
            quantidade += 1;
        }
        else{
            precototal += *(e->produtos[i]->preco);
            quantidade +=1;
        }
    }
    return precototal/quantidade;
}

int buscaRemoveDuplicados(Empresa* e, char* cod){
    int removidos = 0;
    for(int i = 0; i < e->tam; i++){
        if(strcmp(e->produtos[i]->cod,cod) == 0){
            Produto *p = (Produto*) calloc(e->tam - 1,sizeof(Produto));
            for(int j = 0, k = 0; j < (e->qtde - 1); j++){
                if(j == i){
                    k++;
                }
                p[j] = *(e->produtos)[k];
            }
            *(e->produtos) = p;
            e->qtde--;
            e->tam--;
            removidos++;
            i--;
        }
    }
    return removidos;
}

int main(){
    Produto* p = novoProduto("154", "Dedodope", 1.5, 25);
    print(p);
}