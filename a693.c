#include <stdio.h>

int main(void)
{
    int n, m;
    int sum[100005];

    while(scanf("%d %d", &n, &m) != EOF){

        sum[0] = 0;

        for(int i = 1; i <= n; i++){
            int food;

            scanf("%d", &food);

            sum[i] = sum[i - 1] + food;
        }

        for(int i = 0; i < m; i++){
            int l, r;

            scanf("%d %d", &l, &r);

            printf("%d\n", sum[r] - sum[l - 1]);
        }
    }

    return 0;
}
