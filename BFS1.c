#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;

void enqueue(int x)
{
    queue[rear] = x;
    rear++;
}

int dequeue(void)
{
    int x = queue[front];
    front++;
    return x;
}

int main(void)
{
    int visited[100] = {0};

    queue[rear] = 1;
    rear++;

    visited[1] = 1;

    while(front < rear){
        int now = queue[front];
        front++;

        printf("%d ", now);
    }

    return 0;
}
