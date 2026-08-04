#include <stdio.h>

int queue[100];
int front = 0;
int rear = 0;
int count = 0;

void enqueue(int x)
{
    if(count == 100){
        printf("full\n");
        return;
    }

    queue[rear] = x;
    rear = (rear + 1) % 100;
    count++;
}

int dequeue(void)
{
    if(count == 0){
        printf("empty\n");
        return -1;
    }

    int x = queue[front];
    front = (front + 1) % 100;
    count--;
    return x;
}

int main(void)
{
    int n, x;
    int total = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        if(count < 100){
            enqueue(x);
            total++;
        }
        else{
            printf("full\n");
        }
    }

    for(int i = 0; i < total; i++){
        printf("%d\n", dequeue());
    }

    return 0;
}
