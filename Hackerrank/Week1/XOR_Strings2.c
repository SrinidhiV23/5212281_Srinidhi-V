#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char a[101], b[101];
    scanf("%s", a);
    scanf("%s", b);
    
    for(int i=0; a[i]!='\0';i++){
        char res=((a[i]-'0')^(b[i]-'0'))+'0';
        printf("%c", res);
    }
    printf("\n");
    return 0;
}