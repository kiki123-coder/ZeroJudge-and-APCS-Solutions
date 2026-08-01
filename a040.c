#include <stdio.h>

int main(void)
{
    int  n, m;
    int none=1;
    scanf("%d %d", &n, &m); //輸入範圍

    for(int i=n; i<=m; i++){
        int num=i, sum=0, len=1, power; //len次方次數 power次方後的數

        while(num>=10){
            num=num/10;
            len++;
        }
        num=i;

        for(int j=0; j<len; j++){
            int a=num % 10;
            num=num / 10;
            power=1;

            for(int k=0; k<len; k++){
                power=power*a;
            }

            sum=sum+power;
        }

        if(sum == i){
            printf("%d ", i);
            none=0;
        }

    }

    if(none != 0){
        printf("none");
    }

    return 0;
}
