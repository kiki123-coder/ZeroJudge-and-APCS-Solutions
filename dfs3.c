#include <stdio.h>

int grid[100][100] = {0};
int visited[100][100] = {0};

int n = 3;

void dfs(int x, int y);

int main(void)
{
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][1] = 1;
    grid[2][0] = 1;

    dfs(0, 0);

    return 0;
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    printf("%d %d\n", x, y);

    int dx[4] = {- 1, 0, + 1, 0}; //方向
    int dy[4] = {0, - 1, 0, + 1};

    for(int i = 0; i < 4; i++){

        int nx = x + dx[i]; //下一個要去的格子
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < n){

            if(grid[nx][ny] == 1){

                if(visited[nx][ny] == 0){
                    dfs(nx, ny);
                }

            }

        }
    }
}
