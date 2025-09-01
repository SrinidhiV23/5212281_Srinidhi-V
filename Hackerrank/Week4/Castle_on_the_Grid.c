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
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */
typedef struct{
    int x, y;
}Point; 

typedef struct{
    Point* data;
    int front, rear, cap;
}Queue ;
Queue* createQueue(int cap){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->data=(Point*)malloc(cap * sizeof(Queue));
    q->front=q->rear=0;
    q->cap=cap;
    return q;
}
bool isEmpty(Queue* q){
    return q->front==q->rear;
}
void enqueue(Queue* q, Point p){
    q->data[q->rear++]=p;
}
Point dequeue(Queue* q){
    return q->data[q->front++];
    
}
int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    int n=grid_count;
    int** dist=(int**)malloc(n* sizeof(int*));
    for(int i=0;i<n;i++){
        dist[i]=(int*)malloc(n* sizeof(int));
        for(int j=0;j<n;j++)
            dist[i][j]=INT_MAX;
    }
    Queue* q=createQueue(n*n);
    enqueue(q, (Point){startX, startY});
    dist[startX][startY]=0;
    
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    
    while(!isEmpty(q)){
        Point cur =dequeue(q);
        if(cur.x==goalX && cur.y == goalY) break;
        
        for(int d=0;d<4;d++){
            int nx=cur.x;
            int ny=cur.y;
            while(1){
                int tx=nx+dx[d];
                int ty=ny+dy[d];
                if(tx<0 || ty<0 || tx>=n || ty>=n || grid[tx][ty]=='X') break;
                nx=tx; ny=ty;
                if(dist[nx][ny]> dist[cur.x][cur.y]+1){
                    dist[nx][ny]=dist[cur.x][cur.y]+1;
                    enqueue(q, (Point){nx, ny});
                }
            }
        }}
        int res=dist[goalX][goalY];
        for(int i=0;i<n;i++) free(dist[i]);
        free(dist);
        free(q->data);
        free(q);
        
        return res;
}
        int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** grid = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    char** first_multiple_input = split_string(rtrim(readline()));

    int startX = parse_int(*(first_multiple_input + 0));

    int startY = parse_int(*(first_multiple_input + 1));

    int goalX = parse_int(*(first_multiple_input + 2));

    int goalY = parse_int(*(first_multiple_input + 3));

    int result = minimumMoves(n, grid, startX, startY, goalX, goalY);

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
