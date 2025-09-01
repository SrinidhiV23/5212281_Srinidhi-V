* }
 *
 */
 int find(int* parent, int x){
    if(parent[x]!=x)
    parent[x]=find(parent, parent[x]);
    return parent[x];
 }
 void unite(int* parent, int* size, int a, int b){
    int pa=find(parent, a);
    int pb=find(parent, b);
    if(pa!=pb){
        parent[pb]=pa;
    size[pa]+=size[pb];
 }
 }
 int* componentsInGraph(int gb_rows, int gb_columns, int** gb, int* 
result_count) {
 int n=gb_rows;
 int totalNodes=2*n;
 int* parent=(int*)malloc((totalNodes+5)*sizeof(int));
 int* adjsize=(int*)malloc((totalNodes+5)* sizeof(int));
 for(int i=0;i<=totalNodes;i++){
    parent[i]=i;
    adjsize[i]=1;
 }
 for(int i=0;i<n;i++){
    int u=gb[i][0];
    int v=gb[i][1];
    unite(parent, adjsize, u, v);
 }
 int minsize=totalNodes+1, maxsize=0;
 for(int i=1;i<=totalNodes;i++){
    if(parent[i]==i && adjsize[i]>1){
        if(adjsize[i]<minsize)
        minsize=adjsize[i];
        if(adjsize[i]>maxsize)
        maxsize=adjsize[i];
    }
        }
    
int* result=(int*)malloc(2*sizeof(int));
 result[0]=minsize;
 result[1]=maxsize;
 *result_count=2;
 free(adjsize);
 free(parent);
 return result;
 }