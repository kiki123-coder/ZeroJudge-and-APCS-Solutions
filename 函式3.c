#include <stdio.h>

int max(int a, int b);

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans=max(a,b);

    printf("%d", ans);

    return 0;
}

int max(int a, int b)
{
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
