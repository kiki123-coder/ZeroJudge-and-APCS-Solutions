#include <stdio.h>

int main(void)
{
    int a;
    while(scanf("%d", &a) == 1){ //確認是否有資料
        if(a == 0){ //不處理0
            break;
        }
        int n=0;

        while(a != 0){
            if(a%2 == 1){
                n=n+1;
            }
            else{
                break;
            }
            a=a/2;
        }
        printf("%d\n", n);
    }
    return 0;
}
