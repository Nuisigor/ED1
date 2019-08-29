#include <stdio.h>
#include <stdlib.h>

int vetor_dobraTamanho(int **v, int tamanho){
    int *v2 = (int*) calloc(tamanho*2,sizeof(int));
    int *v1 = *v;
    for(int i = 0; i < tamanho*2; i++){
        if(i >= tamanho){
            v2[i] = 0;
        }
        else{
            v2[i] = v1[i];
        }
    }
    free(v);
    *v = v2;
    return tamanho*2;
}

int main(){
    int *v = (int *)calloc(3, sizeof(int));
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    int novoTamanho = vetor_dobraTamanho(&v, 3);
    //Resultado esperado
    // [2,4,6,0,0,0]
}