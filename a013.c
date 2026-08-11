#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int romanTable[256]={0};
int romanToInt(char roman[]);

int main(void)
{
    romanTable['I']=1;
    romanTable['V']=5;
    romanTable['X']=10;
    romanTable['L']=50;
    romanTable['C']=100;
    romanTable['D']=500;
    romanTable['M']=1000;

    char roman[30];
    char droman[30];

    while(scanf("%s", roman) == 1){

        if(roman[0] == '#'){
            break;
        }

        scanf("%s", droman);

        int sum1=romanToInt(roman);
        int sum2=romanToInt(droman);

        int ans=abs(sum1-sum2);

        if(ans == 0){
            printf("ZERO\n");
        }
        else{

            int a = 1000;

            char one[] = "IXCM";
            char five[] = "VLD";
            char ten[] = "XCM";

            for(int i = 3; i >= 0; i--){

                int digit = ans / a;
                ans = ans % a;

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

    }

    return 0;
}

int romanToInt(char roman[])
{
    int sum=0;
    int len=strlen(roman);

    for(int i=0; i<len; i++){
        char a=roman[i];
        char b=roman[i+1];

        if(romanTable[a] >= romanTable[b]){
            sum += romanTable[a];
        }
        else{
            sum -= romanTable[a];
        }
    }

    return sum;
}

