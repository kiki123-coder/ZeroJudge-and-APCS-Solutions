#include <stdio.h>

int graph[100][100] = {0};
int visited[100] = {0};

int n = 5;

void dfs(int now);

int main(void)
{
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[3][4] = graph[4][3] = 1;

    int count = 0;

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            count++;
            dfs(i);
        }
    }
    printf("%d", count);
    return 0;
}

void dfs(int now)
{
    visited[now] = 1;

    for(int i = 0; i < n; i++){
        if(visited[i] == 0 && graph[now][i] == 1){
            dfs(i);
        }
    }
}
