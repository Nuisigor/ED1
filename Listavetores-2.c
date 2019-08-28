#include <stdio.h>
#include <stdlib.h>

int vetor_novoA(int tamanho, int valor){
    int *v = (int*) calloc(tamanho,sizeof(int));
    for(int i = 0 ; i < tamanho; i++){
        v[i] = valor;
    }
    return v;
}

void vetor_novoB(int tamanho, int valor, int **vetor)
{
    *vetor = (int*) calloc(tamanho,sizeof(int));
    int *vet = *vetor;
    for(int i = 0 ; i < tamanho; i++){
        vet[i] = valor;
    }
}

int main(){
    int *v1, *v2;
    v1 = vetor_novoA(10, -1);
    vetor_novoB(5, 0, &v2);
}