#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;
int graph[100][100] = {0};
int n;

void enqueue(int n);
int dequeue(void);
void bfs(int start);

int main(void)
{
    int m;

    scanf("%d %d", &n, &m); //n是節點 m是邊數

    for(int i = 0; i < m; i++){
        int a, b;

        scanf("%d %d", &a, &b);

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    bfs(0);

    return 0;
}

void bfs(int start)
{
    int visited[100] = {0};

    enqueue(start);
    visited[start] = 1;

    while(front < rear){
        int now = dequeue();

        printf("%d ", now);

        for(int i = 0; i < n; i++){

            if(graph[now][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }

        }
    }
}

void enqueue(int n)
{
    queue[rear] = n;
    rear++;
}

int dequeue(void)
{
    int n = queue[front];
    front++;
    return n;
}
