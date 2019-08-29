#include <stdio.h>
#include <stdlib.h>

int vetor_aleatorio(int tam){
    int *v = (int*) calloc(tam,sizeof(int));
    for(int i = 0; i < tam; i++){
        v[i] = rand();
    }
    return v;
}

int main()
{
    int *v1 = vetor_aleatorio(10);
    int *v2 = vetor_aleatorio(100);
}