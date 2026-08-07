#include <stdio.h>

int graph[100][100] = {0};
int visited[100] = {0};

int n = 5;

void dfs(int now);

int main(void)
{
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;

    dfs(0);

    return 0;
}

void dfs(int now)
{
    visited[now] = 1;

    printf("%d", now);

    for(int i = 0; i < n; i++){
        if(graph[now][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}
