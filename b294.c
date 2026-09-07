#include <stdio.h>

int main(void)
{
    int n, money = 0;
    int food[1000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &food[i]);
    }

    for(int i = 0; i < n; i++){
        money += food[i] * (i + 1);
    }

    printf("%d", money);

    return 0;
}
