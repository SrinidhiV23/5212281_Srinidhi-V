#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int q;
    scanf("%d", &q);
    
    int queue[MAX];
    int front=0, rear=0;
    while(q--){
        int type;
        scanf("%d", &type);
        if(type==1){
            int x;
            scanf("%d", &x);
            queue[rear++]=x;
        }else if(type==2){
            front++;
        }else if(type==3){
            printf("%d\n",queue[front]);
        }
    }
    return 0;
}
