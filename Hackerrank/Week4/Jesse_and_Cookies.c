#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */
typedef struct{
    int *arr;
    int size;
    int capacity;
}MinHeap ;
MinHeap* createHeap(int capacity){
    MinHeap* h=(MinHeap*)malloc(sizeof(MinHeap));
    h->arr=(int*)malloc(sizeof(int)*capacity);
    h->size=0;
    h->capacity=capacity;
    return h;
}
void swap(int *a, int *b){
    int t=*a;*a=*b;*b=t;
}
void heapifyUp(MinHeap* h, int idx){
    while(idx>0){
        int p=(idx-1)/2;
        if(h->arr[p]>h->arr[idx]){
            swap(&h->arr[p],&h->arr[idx]);
            idx=p;
    }else break;
}
}
void heapifyDown(MinHeap* h ,int idx){
   while(1){
    int left=2*idx+1,right=2*idx+2,smallest=idx;
    if(left<h->size && h->arr[left]<h->arr[smallest])smallest=left;
    if(right<h->size && h->arr[right]<h->arr[smallest])smallest=right;
    if(smallest!=idx){
        swap(&h->arr[idx],&h->arr[smallest]);
        idx=smallest;
    }else break;
   } 
}
void push(MinHeap* h, int val){
    h->arr[h->size++]=val;
    heapifyUp(h,h->size-1);
}
int pop(MinHeap* h){
    if(h->size==0) return -1;
    int minval=h->arr[0];
    h->arr[0]=h->arr[--h->size];
    heapifyDown(h,0);
    return minval;
}
int top(MinHeap* h){
    return h->size>0?h->arr[0]:-1;
    }
int cookies(int k, int A_count, int* A) {
   MinHeap* h= createHeap(A_count*2);
   for(int i=0;i<A_count;i++){
    push(h,A[i]);
    
   }
   int operations=0;
   while(h->size>0 && top(h)<k){
    if(h->size<2)return -1;
    int least=pop(h);
    int second=pop(h);
    int newcookie=least+2*second;
    push(h,newcookie);
    operations++;
   }     
   return operations;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** A_temp = split_string(rtrim(readline()));

    int* A = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int A_item = parse_int(*(A_temp + i));

        *(A + i) = A_item;
    }

    int result = cookies(k, n, A);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
