/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */
/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count 
variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
 #define EDGE_WEIGHT 6
 typedef struct{
    int *data;
    int front, rear, size;
 }Queue;
 Queue* createQueue(int n){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->data=(int*)malloc(n*sizeof(int));
    q->front=q->rear=0;
    q->size=n;
    return q;
 }
 int isEmpty(Queue* q){
    return q->front==q->rear;
 }
 void enqueue(Queue* q, int val){
    q->data[q->rear++]=val;
 }
 int dequeue(Queue* q){
    return q->data[q->front++];
 }
 int* bfs(int n, int m, int edges_rows, int edges_columns, int** edges, int s, 
int* result_count) {
 int **adj=(int**)malloc((n+1)*sizeof(int*));
 int *adjsize=(int*)calloc(n+1, sizeof(int));
 for(int i=0;i<=n;i++){
    adj[i]=(int*)malloc((m+1)*sizeof(int));
 }
 for(int i=0;i<m;i++){
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u][adjsize[u]++]=v;
    adj[v][adjsize[v]++]=u;
 }
 12
 13
 14
 15
 16
 17
 18
 19
 20
 21
 22
 23
 24
 25
 26
 27
 28
 29
 30
 31
 32
 33
 34
 35
 36
 37
 38
 39
 40
 41
 42
 43
 44
 45
 46
 47
 48
 49
 50
 51
 52
 53
 54
 55
 56
 57
 58
 59
 60
 61
 62
 63
 64
 65
 66
 67
 68
 69
 70
 71
 72
 73
 74
 4/16
int *dist=(int*)malloc((n+1)*sizeof(int));
 for(int i=1;i<=n;i++) dist[i]=-1;
 Queue* q=createQueue(n+5);
 dist[s]=0;
 enqueue(q, s);
 while(!isEmpty(q)){
    int u=dequeue(q);
    for(int i=0;i<adjsize[u];i++){
        int v=adj[u][i];
        if(dist[v]==-1){
        dist[v]=dist[u]+EDGE_WEIGHT;
        enqueue(q,v);
    }
    }
 }
 *result_count=n-1;
 int *result=(int*)malloc((*result_count)*sizeof(int));
 int idx=0;
 for(int i=1;i<=n;i++){
    if(i!=s){
        result[idx++]=dist[i];
    }
 }
 for(int i=0;i<=n;i++)
 free(adj[i]);
 free(adjsize);
 free(adj);
 free(dist);
 free(q->data);
 free(q);
 return result;
 }