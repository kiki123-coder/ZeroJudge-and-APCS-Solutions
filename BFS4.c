#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;
int graph[100][100] = {0};
int k;

void enqueue(int x);
int dequeue(void);
void bfs(int start);

int main(void)
{
    int m;

    scanf("%d %d", &k, &m);

    for(int i = 0; i < m; i++){
        int a, b;

        scanf("%d %d", &a, &b);

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    bfs(0);

    return 0;
}

void enqueue(int x)
{
    queue[rear] = x;
    rear++;
}

int dequeue(void)
{
    int n = queue[front];
    front++;
    return n;
}

void bfs(int start)
{
    int visited[100] = {0};
    int distance[100] = {0};

    enqueue(start);
    visited[start] = 1;
    distance[start] = 0;

    while(front < rear){
        int now = dequeue();

        for(int i = 0; i < k; i++){

            if(graph[now][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                distance[i] = distance[now] + 1;
                enqueue(i);
            }

        }

    }

    for(int j = 0; j < k; j++){
        printf("%d\n", distance[j]);
    }
}
