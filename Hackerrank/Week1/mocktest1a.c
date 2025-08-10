 /*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 int compare(const void *a, const void *b){
 return(*(int *)a-*(int *)b);
 }
 int findMedian(int arr_count, int* arr) {
 qsort(arr, arr_count, sizeof(int), compare);
 return arr[arr_count/2];
 }
