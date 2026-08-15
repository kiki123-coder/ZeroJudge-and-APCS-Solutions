#include <stdio.h>

int f(int n);
int g(int n);

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF){

        printf("%d\n", f(n));

    }

    return 0;
}

int f(int n)
{
    if(n == 0){
        return 1;
    }
    return f(n - 1) + g(n - 1);
}

int g(int n)
{
    return 1 + n + n * (n - 1) / 2;
}
