#include <stdio.h>
#include <string.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        char num[11];
        scanf("%s", num);

        int a = 1, b = 0;
        int len = strlen(num);
        for(int j = 0; j < len; j++){

            if(num[j] != '0'){
                a = a * (num[j] - '0');//將 ASCII 字元精準轉換為實質個位數整數進行乘積
            }
            else{
                b++;
            }

        }

        if(b == 0)
            printf("%d\n", a);
        else
            printf("0\n");
    }
    return 0;
}
