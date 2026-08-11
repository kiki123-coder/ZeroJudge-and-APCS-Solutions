#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*數字轉羅馬數字*/

int main(void)
{
    int romanTable[256] = {0};
    romanTable['I'] = 1;
    romanTable['V'] = 5;
    romanTable['X'] = 10;
    romanTable['L'] = 50;
    romanTable['C'] = 100;
    romanTable['D'] = 500;
    romanTable['M'] = 1000;

    char num[10];

    while(scanf("%s", num) == 1){

        if(num[0] == '#'){
            return 0;
        }

        int n = atoi(num);
        int a = 1000;

        char one[] = "IXCM";
        char five[] = "VLD";
        char ten[] = "XCM";

        for(int i = 3; i >= 0; i--){

            int digit = n / a;
            n = n % a;

            if(digit <= 3){
                for(int j = 0; j < digit; j++){
                    printf("%c", one[i]);
                }
            }
            else if(digit == 4){
                printf("%c%c", one[i], five[i]);
            }
            else if(digit <= 8){
                printf("%c", five[i]);

                for(int j = 0; j < digit - 5; j++){
                    printf("%c", one[i]);
                }
            }
            else{
                printf("%c%c", one[i], ten[i]);
            }

            a = a / 10;
        }

        printf("\n");
    }

    return 0;
}
