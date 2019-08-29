#include <stdio.h>

void vetor_incrementa(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        v[i]+=1;
    }
}

int main(){
    int v1[5] = {10, 20, 30, 40, 50};
    vetor_incrementa(v1, 5); // [11,21,31,41,51]
}