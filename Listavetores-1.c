#include <stdio.h>

void vetor(int* vet, int i){
    for(int j = 0; j < i ;j++){
        vet[j]=j+1;
        if(j>0 && j <4) 
            printf(" %d,",vet[j]);
        if(j == 0)  
            printf("[%d,",vet[j]);
        if(j == 4) 
            printf(" %d]\n",vet[j]);
    }
}

int main(){
    int v[5];
    vetor(v, 5);
}