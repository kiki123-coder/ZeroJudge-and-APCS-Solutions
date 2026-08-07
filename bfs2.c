#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;

void enqueue(int n);
int dequeue(void);

int main(void)
{
    int visited[100] = {0};
    int graph[3][3] = {{0, 1, 1}, {1, 0, 0}, {1, 0, 0}};

    queue[rear] = 0;
    rear++;

    visited[0] = 1;

    while(front < rear){
        int now = dequeue();

        printf("%d ", now);

        for(int i = 0; i < 3; i++){

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
    int x = queue[front];
    front++;
    return x;
}
