#include <stdio.h>

int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans=add(a,b);

    printf("%d", ans);

    return 0;
}
