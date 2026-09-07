#include <stdio.h>

int main(void)
{
    int T, n, m;
    int a[10][10];

    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);

        int ok = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != a[n-1-i][m-1-j])
                    ok = 0;
            }
        }

        printf("%s\n", ok ? "go forward" : "keep defending");
    }

    return 0;
}
