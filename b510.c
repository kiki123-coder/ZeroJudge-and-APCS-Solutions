#include <stdio.h>

int board[10][10];
int M, N;
int ans = 0;
int size;

int check(int x, int y, int type)
{
    // 行
    for(int i = 0; i < size; i++){
        if(board[x][i])
            return 0;
    }

    // 列
    for(int i = 0; i < size; i++){
        if(board[i][y])
            return 0;
    }

    // 斜線
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};

    for(int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        while(nx >= 0 && nx < size &&
              ny >= 0 && ny < size){

            if(board[nx][ny] == 1 || type == 1){
                if(board[nx][ny])
                    return 0;
            }

            nx += dx[d];
            ny += dy[d];
        }
    }

    return 1;
}

void dfs(int pos, int queen, int rook)
{
    if(queen == M && rook == N){
        ans++;
        return;
    }

    if(pos == size * size)
        return;

    int x = pos / size;
    int y = pos % size;

    // 不放棋子
    dfs(pos + 1, queen, rook);

    // 放皇后
    if(queen < M && check(x, y, 1)){
        board[x][y] = 1;
        dfs(pos + 1, queen + 1, rook);
        board[x][y] = 0;
    }

    // 放城堡
    if(rook < N && check(x, y, 2)){
        board[x][y] = 2;
        dfs(pos + 1, queen, rook + 1);
        board[x][y] = 0;
    }
}

int main(void)
{
    scanf("%d %d", &M, &N);

    size = M + N;

    dfs(0, 0, 0);

    printf("%d\n", ans);

    return 0;
}
