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

    if(op == '+'){
        int k = 0;
        int len;

        if(lenA == lenB){
            len = lenA;

            for(int i = lenA - 1; i >= 0; i--){
                int a = numA[i] - '0' + numB[i] - '0' + b;

                //進位
                if(a < 10){
                    ans[k] = a;
                    b = 0;
                }
                else{
                    b = a / 10;
                    a = a%10;
                    ans[k] = a;
                }

                k++;
            }

        }
        else if(lenA > lenB){
            len = lenA;

            for(int i = lenA - 1; i >= 0; i--){
                int indexB = i - (lenA - lenB);
                int a;

                if(indexB < 0){
                    a = numA[i] - '0' + b;
                }
                else{
                    a = numA[i] - '0' + numB[indexB] - '0' + b;
                }

                if(a < 10){
                    ans[k] = a;
                    b = 0;
                }
                else{
                    b = a / 10;
                    a = a%10;
                    ans[k] = a;
                }
                k++;

            }
        }
        else{
            len = lenB;

            for(int i = lenB - 1; i >= 0; i--){
                int indexA = i - (lenB - lenA);
                int a;

                if(indexA < 0){
                    a = numB[i] - '0' + b;
                }
                else{
                    a = numA[indexA] - '0' + numB[i] - '0' + b;
                }

                if(a < 10){
                    ans[k] = a;
                    b = 0;
                }
                else{
                    b = a / 10;
                    a = a%10;
                    ans[k] = a;
                }
                k++;

            }
        }

        if(b != 0){ //處理最高進位
            printf("%d", b);
        }

        for(int i = len - 1; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }
}
