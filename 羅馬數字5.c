#include <stdio.h>
#include <stdlib.h>

/*數字轉羅馬數字，方法1*/

int main(void)
{
    char num[10];

    while(scanf("%s", num) == 1){

        if(num[0] == '#'){
            return 0;
        }

        int n = atoi(num);
        int a = 1000;

        for(int i = 0; i < 4; i++){

            int digit = n / a;
            n = n % a;

            if(i == 0){
                // 千位
                for(int j = 0; j < digit; j++){
                    printf("M");
                }
            }

            else if(i == 1){
                // 百位
                if(digit <= 3){
                    for(int j = 0; j < digit; j++){
                        printf("C");
                    }
                }

                else if(digit == 4){
                    printf("CD");
                }

                else if(digit <= 8){
                    printf("D");
                    for(int j = 0; j < digit - 5; j++){
                        printf("C");
                    }
                }

                else{
                    printf("CM");
                }

            }

            else if(i == 2){
                // 十位
                if(digit <= 3){
                    for(int j = 0; j < digit; j++){
                        printf("X");
                    }
                }

                else if(digit == 4){
                    printf("XL");
                }

                else if(digit <= 8){
                    printf("L");
                    for(int j = 0; j < digit - 5; j++){
                        printf("X");
                    }
                }

                else{
                    printf("XC");
                }

            }

            else{
                // 個位
                if(digit <= 3){
                    for(int j = 0; j < digit; j++){
                        printf("I");
                    }
                }

                else if(digit == 4){
                    printf("IV");
                }

                else if(digit <= 8){
                    printf("V");
                    for(int j = 0; j < digit - 5; j++){
                        printf("I");
                    }
                }

                else{
                    printf("IX");
                }

            }

            a = a / 10;
        }

        printf("\n");
    }

    return 0;
}
