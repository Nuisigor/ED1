#include <stdio.h>
#include <stdlib.h>

int intercala_a(int *v1, int tam1, int *v2, int tam2){
    int *v3 = (int*) calloc(tam1+tam2, sizeof(int));
    int i= 0, i1 = 0, i2 =0;

    while(i < tam1+tam2){
        if(i1 < tam1){
            v3[i] = v1[i1];
            i++;
            i1++; 
        }
        if(i2 < tam2){
            v3[i] = v2[i2];
            i++;
            i2++;
        }
    }
    return v3;
}

void intercala_b(int *v1, int tam1, int *v2, int tam2, int *v3){
    int i= 0, i1 = 0, i2 =0;
    while(i < tam1+tam2){
        if(i1 < tam1){
            v3[i] = v1[i1];
            i++;
            i1++; 
        }
        if(i2 < tam2){
            v3[i] = v2[i2];
            i++;
            i2++;
        }
    }
}

int main(){
    int v1[3] = {2, 4, 6};
    int v2[4] = {3, 5, 7, 9};
    int v3[7];
    int *v4;
    v4 = intercala_a(v1, 3, v2, 4);
    intercala_b(v1, 3, v2, 4, v3);
}
