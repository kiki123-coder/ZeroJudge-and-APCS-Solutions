#include <stdio.h>
#include <string.h>

int main(void)
{
    char numA[10000];
    char op;
    char numB[10000];
    int ans[10000];
    int b = 0;

    scanf("%s %c %s", numA, &op, numB);

    int lenA = strlen(numA);
    int lenB = strlen(numB);

    if(op == '-'){
        int k = 0;
        int len;

        if(lenA == lenB){
            len = lenA;

            for(int i = lenA - 1; i >= 0; i--){
                int a = (numA[i] - '0') - (numB[i] - '0') - b;

                //借位
                if(a < 0){
                    a = a + 10;
                    b = 1;
                }
                else{
                    b = 0;
                }

                ans[k] = a;
                k++;
            }
        }
        else if(lenA > lenB){
            len = lenA;

            for(int i = lenA - 1; i >= 0; i--){
                int indexB = i - (lenA - lenB);
                int a;

                if(indexB < 0){
                    a = (numA[i] - '0') - b;
                }
                else{
                    a = (numA[i] - '0') - (numB[indexB] - '0') - b;
                }

                if(a < 0){
                    a = a + 10;
                    b = 1;
                }
                else{
                    b = 0;
                }

                ans[k] = a;
                k++;
            }
        }

        int start = len - 1;

        while(start > 0 && ans[start] == 0){ //去掉答案前面的0
            start--;
        }

        for(int i = start; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }

    return 0;
}
