#include <stdio.h>
int main(void)
{
    int n;
    while(scanf("%d",&n) != 0){

        if(n == 0){
        return 0;
        }

        for(int i=0; i<n; i++){
            if(i%7 != 0){
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
