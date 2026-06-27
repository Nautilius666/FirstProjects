#include<stdio.h>
#include<stdlib.h>

typedef struct {

    int *data;
    size_t size;
    size_t capacity;

} Vector;

void vector_init(Vector *vector){
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

void vector_push_back(Vector *vector, int value){
    if(vector->size == vector->capacity){
        if(vector->capacity == 0){
            vector->capacity = 8;
            vector->data = malloc(vector->capacity * sizeof(int));
        }
        else{
            vector->capacity *= 2;
            vector->data = realloc(vector->data, vector->capacity * sizeof(int));
        }
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void vector_destroy(Vector *vector)
{
    free(vector->data);

    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

int main(void){
    Vector v;
    vector_init(&v);
    vector_push_back(&v, 1488);
    printf("значение: %d\n", v.data[0]);
    vector_destroy(&v);
    return 0;
}