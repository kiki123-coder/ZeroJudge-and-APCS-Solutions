#include <stdio.h>

int stack[100];
int top = -1;

void push(int n)
{
    top++;
    stack[top] = n;
}

int pop(void)
{
    int x = stack[top];
    top--;
    return x;
}

int main(void)
{
    int count, value; //count 有幾個 value 目前讀到的值
    scanf("%d", &count);

    for(int i = 0; i < count; i++){
        scanf("%d", &value);
        push(value);
    }

    for(int i = 0; i < count; i++){
        printf("%d ", pop());
    }

    return 0;
}
