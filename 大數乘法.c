#include <stdio.h>
#include <string.h>

int main(void)
{
    char numA[10000];
    char op;
    char numB[10000];
    int ans[20000] = {0};

    scanf("%s %c %s", numA, &op, numB);

    int lenA = strlen(numA);
    int lenB = strlen(numB);

    if(op == '*'){
        for(int i = lenA - 1; i >= 0; i--){
            for(int j = lenB - 1; j >= 0; j--){

                int a = numA[i] - '0';
                int b = numB[j] - '0';

                int indexA = lenA - 1 - i;
                int indexB = lenB - 1 - j;

                ans[indexA + indexB] += a * b; //兩位相乘，累加到對應位置
            }
        }

        for(int i = 0; i < lenA + lenB; i++){
            if(ans[i] >= 10){  //進位
                ans[i + 1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }

        int start = lenA + lenB - 1;

        while(start > 0 && ans[start] == 0){ //去掉答案前面的0
            start--;
        }

        for(int i = start; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }

    return 0;
}
