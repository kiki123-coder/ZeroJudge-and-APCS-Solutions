#include <stdio.h>

int main(void)
{
    int n, m;
    int max;

    scanf("%d %d", &n, &m);

    if(n > m){

        for(int i = 1; i <= n; i++){
            if(n%i == 0 && m%i == 0){
                max = i;
            }
        }

    }
    else{
        for(int i = 1; i <= m; i++){
            if(n%i == 0 && m%i == 0){
                max = i;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
