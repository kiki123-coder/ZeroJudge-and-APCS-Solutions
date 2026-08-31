#include <stdio.h>

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF){
        int ans = 0;

        for(int i = 2; i * i <= n; i++){
            while(n % i == 0){
                ans = ans + i;
                n /= i;
            }
        }
        if(n > 1){
            ans = ans + n;
        }
        printf("%d\n", ans);
    }
    return 0;
}
