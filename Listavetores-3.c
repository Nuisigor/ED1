#include <stdio.h>

int maiorindice(int *vetor, int tamanho){
    int maior = 0;
    for(int i = 1; i < tamanho; i++){
        if(vetor[i] > vetor[maior])
            maior = i;
    }
    return maior;
}

int main(){
    int vet[5] = {2,3,7,8,5};
}