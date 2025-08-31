#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
 
 
typedef struct node{
    int freq;
    char data;
    struct node *left, *right;
    
}node;
typedef struct{
    node **a;
    int n, cap;
}heap;
static inline int isLeaf(node *r){ return r->left==NULL && r->right==NULL;
}
node* newnode(char c, int f, node*l, node*r){
    node* n=(node*)malloc(sizeof(node));
    n->data=c; n->freq=f; n->left=l; n->right=r; return n;
}
heap* heap_new(int cap){
    heap*h=(heap*)malloc(sizeof(heap));
    h->a=(node**)malloc(sizeof(node*)*cap);
    h->n=0; h->cap=cap; return h;
}
void heap_swap(node**x,node**y){ node*t=*x;*x=*y;*y=t;}

void heap_up(heap*h,int i){
    while(i>0){
        int p=(i-1)/2;
        if(h->a[p]->freq<=h->a[i]->freq) break;
        i=p;
    }
}
void heap_down(heap*h,int i){
    for(;;){
        int l=2*i+1,r=2*i+2,sm=i;
        if(l<h->n && h->a[l]->freq<h->a[sm]->freq) sm=l;
        if(r<h->n && h->a[r]->freq<h->a[sm]->freq) sm=r;
        if(sm==i) break;
        heap_swap(&h->a[i],&h->a[sm]); i=sm;
            }
}
void heap_push(heap*h, node* v){
    if(h->n==h->cap){
        h->cap*=2;
        h->a=(node**)realloc(h->a,sizeof(node*)*h->cap);
    }
    h->a[h->n++]=v; heap_up(h,h->n-1);
}
node* heap_pop(heap*h){
    node * top=h->a[0];
    h->a[0]=h->a[--h->n];
    heap_down(h,0);
    return top;
}
char* mydup(const char*s){
    size_t n=strlen(s); char*d=(char*)malloc(n+1); memcpy(d,s,n+1); return d;
}
void build_codes(node*root, char*path,int d, char*codes[]){
    if(isLeaf(root)){
        if(d==0){ path[0]='0'; path[1]='\0';}
        else path[d]='\0';
        codes[(unsigned char)root->data]=mydup(path);
        return;
    }
    if(root->left){ path[d]='0'; build_codes(root->left,path,d+1,codes);}
    if(root->right){ path[d]='1'; build_codes(root->right,path,d+1,codes);}
}
void decode_huff(node *root, char *s){
    if(!root) return;
    if(isLeaf(root)){
        size_t k=strlen(s);
        for(size_t i=0;i<k;i++) putchar(root->data);
        return;
    }
    node* curr=root;
    for(size_t i=0;s[i];i++){
        curr=(s[i]=='0')?curr->left:curr->right;
        if(isLeaf(curr)){ putchar(curr->data); curr=root;
        }
    }
}

int main() {
    char buf[200005];
    if(!fgets(buf,sizeof(buf), stdin)) return 0;
    size_t L=strlen(buf);
    if(L && buf[L-1]=='\n'){ buf[L-1]='\0'; L--;}
    if(L==0){ printf("\n"); return 0;}
    int freq[256]={0};
    for(size_t i=0;i<L;i++) freq[(unsigned char)buf[i]]++;
    heap*h=heap_new(256);
    for(int c=0;c<256;c++) if(freq[c]>0) heap_push(h,newnode((char)c,freq[c],NULL,NULL));
    node*root=NULL;
    if(h->n==1){
        root=heap_pop(h);
    }else{
        while(h->n>1){
            node*a=heap_pop(h);
            node*b=heap_pop(h);
            node* p=newnode('\0', a->freq+b->freq,a,b);
            heap_push(h,p);
        }
        root=heap_pop(h);
    }
    char* codes[256]={0};
    char path[1024];
    build_codes(root,path,0,codes);
    
    size_t cap=L*16+16;
    char* enc=(char*)malloc(cap);
    size_t len=0;
    for(size_t i=0;i<L;i++){
        char* t=codes[(unsigned char)buf[i]];
        size_t m=strlen(t);
        if(len+m+1>cap){ cap=(cap+m+1)*2; enc=(char*) realloc(enc,cap);}
        memcpy(enc+len,t,m); len+=m;
    }
    enc[len]='\0';
    decode_huff(root,enc);
    return 0;
}