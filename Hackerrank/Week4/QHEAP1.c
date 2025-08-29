#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef  struct{
    long long *arr;
    int size;
    int capacity;
    
}Heap ;
Heap* createHeap(int cap){
    Heap* h=(Heap*)malloc(sizeof(Heap));
    h->arr=(long long*)malloc(sizeof(long long)*cap);
    h->size=0;
    h->capacity=cap;
    return h;
}
void swap(long long *a, long long *b){
    long long t=*a;*a=*b;*b=t;
}
void heapifyup(Heap* h, int i){
    while(i>0){
        int p=(i-1)/2;
        if(h->arr[p]>h->arr[i]){
            swap(&h->arr[p],&h->arr[i]);
            i=p;
        }else break;;
    }
}
void heapifydown(Heap* h, int i){
    while(1){
        int l=2*i+1;
        int r=2*i+2;
        int s=i;
        if(l<h->size && h->arr[l]<h->arr[s]){
            s=l;
        }
        if(r<h->size && h->arr[r]<h->arr[s]){
            s=r;
        }
        if(s!=i){
            long long temp=h->arr[i];
            h->arr[i]=h->arr[s];
            h->arr[s]=temp;
            i=s;
        }else{
            break;
        }
    }
}
void push(Heap* h, long long val){
    h->arr[h->size++]=val;
    heapifyup(h, h->size-1);
}
long long top(Heap* h){
    return h->arr[0];
}
void pop(Heap* h){
    h->arr[0]=h->arr[--h->size];
    heapifydown(h, 0);
}
int empty(Heap* h){
    return h->size==0;
}
int main() {
    int Q;
    scanf("%d",&Q);
    Heap* minHeap=createHeap(Q+5);
    Heap* delHeap=createHeap(Q+5);
    while(Q--){
        int type;
        int long long x;
        scanf("%d",&type);
        if(type==1){
            scanf("%lld",&x);
            push(minHeap,x);
        }else if(type==2){
            scanf("%lld",&x);
            push(delHeap,x);
        }else{
            while(!empty(minHeap)&& !empty(delHeap)&& top(minHeap)==top(delHeap)){
                pop(minHeap);
                pop(delHeap);
            }
            printf("%lld\n",top(minHeap));
        }
    }
        return 0;
}
