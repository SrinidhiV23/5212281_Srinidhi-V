/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
 int getTotalX(int a_count, int* a, int b_count, int* b) {
    int count=0;
    int x;
    int maxa=0;
    for(int i=0;i<a_count;i++){
        if(a[i]>maxa){
            maxa=a[i];
        }
    }
    int minb=101;
    for(int i=0;i<b_count;i++){
        if(b[i]<minb){
            minb=b[i];
        }
    }
    for(x=maxa;x<=minb;x++){
        int isfactorofallb=1;
        for(int i=0;i<b_count;i++){
            if(b[i]%x!=0){
                isfactorofallb=0;
                break;
            }
        }
        if(isfactorofallb){
            int isMultipleofallA=1;
            for(int i=0;i<a_count;i++){
                if(x%a[i]!=0){
                    isMultipleofallA=0;
                    break;
                }
            }
            if(isMultipleofallA){
                count++;
            }
        }
    }
    return count;
 }