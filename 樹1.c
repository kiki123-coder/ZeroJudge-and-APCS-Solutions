#include <stdio.h>

int tree[100][100] = {0};
int visited[100] = {0};

int n = 5;

void dfs(int now);

int main(void)
{
    tree[0][1] = tree[1][0] = 1;
    tree[0][2] = tree[2][0] = 1;
    tree[1][3] = tree[3][1] = 1;
    tree[1][4] = tree[4][1] = 1;

    dfs(0);

    return 0;
}

void dfs(int now)
{
    visited[now] = 1;

    printf("%d", now);

    for(int i = 0; i < n; i++){

        if(tree[now][i] == 1 && visited[i] == 0){
            dfs(i);
        }

    }
}
