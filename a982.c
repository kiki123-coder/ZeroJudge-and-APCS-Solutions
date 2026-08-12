#include <stdio.h>

int queueX[10000]; //用bfs
int queueY[10000];

int front = 0;
int rear = 0;



int main(void)
{
    int N;
    char road[101][101];
    int visited[101][101] = {0}; //紀錄走過
    int distance[101][101] = {0}; //紀錄與起點的距離

    scanf("%d", &N);

    for(int i = 0; i < N; i++){ //輸入迷宮
        scanf("%s", road[i]);
    }

    //起點
    int startX = 1;
    int startY = 1;

    //終點
    int endX = N - 2;
    int endY = N - 2;

    //四個移動方向：上、下、左、右
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queueX[rear] = startX;  //起點加入Queue
    queueY[rear] = startY;
    rear++;

    visited[startX][startY] = 1; //起點標記為已走過
    distance[startX][startY] = 1; //起點距離為1

    while(front < rear){ //Queue不是空的

        int x = queueX[front];
        int y = queueY[front];
        front++;

        for(int i = 0; i < 4; i++){ //檢查四個方向
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N){ //判斷範圍
                continue;
            }

            if(road[nx][ny] == '#'){ //障礙物
                continue;
            }

            if(visited[nx][ny] == 1){ //已走過
                continue;
            }

            visited[nx][ny] = 1; //標示為已走過
            distance[nx][ny] = distance[x][y] + 1; //距離+1

            if(nx == endX && ny == endY){ //到終點
                printf("%d\n", distance[nx][ny]);
                return 0;
            }

            queueX[rear] = nx; //新位置加入Queue
            queueY[rear] = ny;
            rear++;
        }

    }
    printf("No solution!\n"); //bfs結束還沒到終點
    return 0;
}



