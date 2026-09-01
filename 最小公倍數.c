#include <stdio.h>

int main(void)
{
    int n, m;
    int max = 0, ans = 0;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; ; i++){
        ans = m * i;
        if(ans%n == 0){
            printf("%d", ans);
            break;
        }
    }

    return 0;
}
