#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;

void enqueue(int x)
{
    queue[rear] = x;
    rear = (rear + 1) % 100;
}

int dequeue(void)
{
    int n = queue[front];
    front++;
    return n;
}

int main(void)
{
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        enqueue(x);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", dequeue());
    }

    return 0;
}
