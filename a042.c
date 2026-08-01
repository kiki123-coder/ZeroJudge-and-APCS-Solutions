#include <stdio.h>

int f(int n){
    if(n==1){
        return 2;
    }
    return f(n-1)+2*(n-1);
}

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", f(n));
    }
    return 0;
}
