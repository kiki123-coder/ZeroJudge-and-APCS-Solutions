#include<stdio.h>
int main(void)
{
    int n, s;
    while(scanf("%d", &n) != EOF){

        int sum = 0;
        double avg;
        for(int i = 0; i < n; i++){

            scanf("%d", &s);
            sum = sum + s;

        }

        avg = (double)sum / n;//轉浮點數，避免小數部分無法進行比較
        /*題目要求的分數評價標準*/
        if(avg > 59){
            printf("no\n");
        }
        else if(avg <= 59){
            printf("yes\n");
        }
    }

    return 0;
}
