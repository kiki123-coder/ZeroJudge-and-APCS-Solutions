#include <stdio.h>

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    if(n > m){

        for(int i = 1; i <= n; i++){
            if(n%i == 0 && m%i == 0){
                printf("%d\n", i);
            }
        }

    }
    else{
        for(int i = 1; i <= m; i++){
            if(n%i == 0 && m%i == 0){
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
