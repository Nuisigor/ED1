#include <stdio.h>

int vetor_dobra(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        v[i]*=2;
    }
}
int main(){
    int v1[5] = {10, 20, 30, 40, 50};
    vetor_dobra(v1, 5); // [20,40,60,80,100]
}