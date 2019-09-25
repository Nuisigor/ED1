#include <stdio.h>
#include <stdlib.h>

typedef struct{
int* vetor;
int size; //quantidade de elementos armazenados no vetor
int length; // tamanho alocado
} Vetor;

typedef int DataType;
typedef enum {false, true} Boolean;
#define LENGTH 5

//  PARTE 1

Vetor* vetor_new();
void vetor_free(Vetor* v);
void vetor_print(Vetor *m);
Boolean vetor_insert(Vetor* v, DataType element, int index);

Boolean vetor_add(Vetor* v, DataType element);
DataType vetor_remove1(Vetor* v, int index);
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);
DataType vetor_shift1(Vetor *v);
Boolean vetor_shift2(Vetor *v, DataType *ptr);
DataType vetor_get1(Vetor* v, int index);
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
//DataType *vetor_get3(Vetor *v, int index);
Boolean vetor_set(Vetor* v, int index, DataType valor);
void vetor_map(Vetor* v, void (*funcao)(DataType*));
Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);
int vetor_size(Vetor* v);

// PARTE 2
Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*));
void vetor_sort(Vetor *v);

void vetor_genericSort(Vetor *v, int (*pfuncao)(DataType *a, DataType *b));

Vetor* vetor_new(){
    Vetor* v1= (Vetor*) malloc(sizeof(Vetor));
    v1->vetor = (DataType*) calloc(LENGTH, sizeof(DataType)); 
    v1->size = 0;
    v1->length = LENGTH;
    return v1;
}

void vetor_free(Vetor* v){
    free(v->vetor);
    free(v);
}

void vetor_print(Vetor* m){
    printf("[");
    for(int i = 0; i < m->size; i++){
        if(i == m->size - 1){printf("%d]",m->vetor[i]);}
        else{printf("%d,",m->vetor[i]);}
    }
}
// Funções terceirizadas para adição
Boolean vetor_add_verify(Vetor *v){
    if(v->size == v->length){return false;}
    else{return true;}
}

void vetor_double(Vetor *v){
    DataType *v1 = (DataType*) calloc(v->length*2,sizeof(DataType));
    for(int i = 0; i < v->length; i++){
        v1[i] = v->vetor[i];
    }
    free(v->vetor);
    v->vetor = v1;
    v->length*=2;
}

void vetor_shift3(Vetor *v, DataType index){
    DataType *v1 = (DataType*) calloc(v->length,sizeof(DataType));
    for(int i = 0, j = 0; i < v->size; i++, j++){
        if(i == index){
            j++;
            v1[j] = v->vetor[i];
        }
        else{
            v1[j] = v->vetor[i];
        }
    }
    free(v->vetor);
    v->vetor = v1;
}
//

Boolean vetor_insert(Vetor* v, DataType element, int index){
    if(index > v->size){
        return false;
    }
    else if(index == v->size){
        v->vetor[index] = element;
        v->size++;
        return true;
    }
    else{
        if(vetor_add_verify(v)){
            vetor_shift3(v,index);
            v->vetor[index] = element;
            v->size++;
            return true;
        }
        else{
            vetor_double(v);
            vetor_shift3(v,index);
            v->vetor[index] = element;
            v->size++;
            return true;
        }
    }
}

Boolean vetor_add(Vetor* v, DataType element){
    if(vetor_add_verify(v)){
        v->vetor[v->size] = element;
        v->size++;
        return true;
    }
    else{
        vetor_double(v);
        v->vetor[v->size] = element;
        v->size++;
        return true;
    }
}
//Funções terceirizadas para remoção

void vetor_reduce(Vetor *v){
    DataType *v1 = (DataType*) calloc(v->length/2,sizeof(DataType));
    for(int i = 0; i < v->size; i++){
        v1[i] = v->vetor[i];
    }
    free(v->vetor);
    v->vetor = v1;
    v->length /= 2;
}

void vetor_remove_verify(Vetor *v){
    if(v->size/v->length < 0.25 && v->length != LENGTH){
        vetor_reduce(v);
    }     
}

//
DataType vetor_remove1(Vetor* v, int index){
    if(index > v->size){
        return 0;
    }
    else{
        DataType valor = v->vetor[index];
        DataType* v1 = (DataType*) calloc(v->length,sizeof(DataType));
        for(int i = 0, j = 0; i < v->size - 1 ;i ++, j ++){
            if(index == i){j++;}
            v1[i] = v->vetor[j];
        }
        free(v->vetor);
        v->vetor = v1;
        v->size-=1;
        vetor_remove_verify(v);
        return valor;
    }
}

Boolean vetor_remove2(Vetor* v, int index, DataType* ptr){
    if(index > v->size){
        *ptr = 0;
        return false;
    }
    else{
        *ptr = v->vetor[index];
        DataType* v1 = (DataType*) calloc(v->length,sizeof(DataType));
        for(int i = 0, j = 0; i < v->size - 1 ;i ++, j ++){
            if(index == i){j++;}
            v1[i] = v->vetor[j];
        }
        free(v->vetor);
        v->vetor = v1;
        v->size-=1;
        vetor_remove_verify(v);
        return true;
    }
}

DataType vetor_shift1(Vetor *v){
    if(v->size == 0){
        return 0;
    }
    else{
        DataType valor = v->vetor[0];
        DataType *v1 = (DataType*) calloc(v->length,sizeof(DataType));
        for(int i = 0, j = 1; i < v->size - 1; i++, j++){
            v1[i] = v->vetor[j];
        }
        free(v->vetor);
        v->vetor = v1;
        vetor_remove_verify(v);
        return valor;
    }
}

Boolean vetor_shift2(Vetor *v, DataType *ptr){
    if(v->size == 0){
        *ptr = 0;
        return true;
    }
    else{
        *ptr = v->vetor[0];
        DataType *v1 = (DataType*) calloc(v->length,sizeof(DataType));
        for(int i = 0, j = 1; i < v->size - 1; i++, j++){
            v1[i] = v->vetor[j];
        }
        free(v->vetor);
        v->vetor = v1;
        vetor_remove_verify(v);
        return true;
    }
}

DataType vetor_get1(Vetor* v, int index){
    if(index > v->size){
        return NULL;
    }
    else{
        return v->vetor[index];
    }
}

Boolean vetor_get2(Vetor* v, int index, DataType *ptr){
    if(index > v->size){
        return false;
    }
    else{
        *ptr = v->vetor[index];
        return false;
    }
}


Boolean vetor_set(Vetor* v, int index, DataType valor){
    if(index > v->size){
        return false;
    }
    else{
        v->vetor[index] = valor;
    }
}

void vetor_map(Vetor* v, void (*funcao)(DataType*)){
    for(int i = 0; i < v->size; i++){
        funcao(v->vetor);
    }
}

Vetor* vetor_sub1(Vetor* v, int index){
    if(index < 0){
        int index1 = v->size - index;
        index = index1;
    }
    if(index > v->size){
        return NULL;
    }
    else{
        Vetor* v1 = (Vetor*) malloc(sizeof(Vetor));
        v1->vetor = (DataType*) calloc(v->size - index,sizeof(DataType));
        for(int i = index, j = 0; i < v->size; i++ , j++){
            v1->vetor[j] = v->vetor[i];
        }
        v1->length = v->size - index;
        v1->size = v->size -  index;
        return v1;
    }
}

Vetor* vetor_sub2(Vetor* v, int start, int end){
    if(start > v->size || end > v->size){
        return NULL;
    }
    else{
        Vetor* v1 = (Vetor*) malloc(sizeof(Vetor));
        v1->vetor = (DataType*) calloc(end - start,sizeof(DataType));
        for(int i = start, j = 0; i < end; i++, j++){
            v1->vetor[j] = v->vetor[i];
        }
        v1->length = end - start;
        v->size = end - start;
        return v1;
    }
}

int vetor_size(Vetor* v){
    return v->size;
}


//

Boolean ehPar(DataType* ptr){
    return (*ptr % 2 == 0 ? true : false);
}
Boolean ehImpar(DataType* ptr){
    return (*ptr % 2 == 0 ? false : true);
}

//
Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*)){
    int cont = 0;
    for(int i = 0; i < v->size; i++){
        if(funcao(&v->vetor[i])){
            cont++;
        }
    }
    Vetor* v1 = (Vetor*) malloc(sizeof(Vetor));
    v1->vetor = (DataType*) calloc(cont,sizeof(DataType));
    v1->length = cont;
    v1->size = cont;
    for(int i = 0, j = 0; i < v->size; i++){
        if(funcao(&v->vetor[i])){
            v1->vetor[j] = v->vetor[i];
            j++;
        }
    }
    return v1;
}

void vetor_sort(Vetor *v){
    for(int i = v->length-1 ; i > 0; i--){
        int houvetroca = 0;
        for(int j = 0; j < i; j++){
            if(v->vetor[j] > v->vetor[j+1]){
                DataType x = v->vetor[j+1];
                v->vetor[j+1] = v->vetor[j];
                v->vetor[j] = x;
                houvetroca++;
            }
        }
        if(houvetroca == 0){break;}
    }
}

int compara(DataType* a, DataType* b){
    if(*a > *b) return 1;
    else if (*a < *b) return -1;
    else return 0;
}

void vetor_genericSort(Vetor *v, int (*pfuncao)(DataType *a, DataType *b)){
    for( int i = v->length-1; i > 0; i--){
        int houvetroca = 0;
        for(int j = 0; j < i; j++){
            if(pfuncao(&v->vetor[j], &v->vetor[j+1])){
                DataType x = v->vetor[j+1];
                v->vetor[j+1] = v->vetor[j];
                v->vetor[j] = x;
                houvetroca++;
            }
        }
        if(houvetroca == 0){break;}
    }
}