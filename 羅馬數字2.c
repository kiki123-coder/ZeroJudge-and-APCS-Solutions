#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*兩組數字相減*/
int main(void)
{
    int romanTable[256]={0};
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
        if(roman[0]=='#'){
            return 0;
        }

        scanf("%s", droman);
        int sum=0, sum1=0, sum2=0;
        int lenr=strlen(roman);
        int lend=strlen(droman);


        for(int i=0; i<lenr; i++){
            char a, b;
            a=roman[i];
            b=roman[i+1];

            if(romanTable[a]>=romanTable[b]){
                sum1=sum1+romanTable[a];
            }
            else{
                sum1=sum1-romanTable[a];
            }
        }
        for(int i=0; i<lend; i++){
            char a, b;
            a=droman[i];
            b=droman[i+1];

            if(romanTable[a]>=romanTable[b]){
                sum2=sum2+romanTable[a];
            }
            else{
                sum2=sum2-romanTable[a];
            }
        }


        sum=sum1-sum2;
        if(sum != 0){
            printf("%d\n", abs(sum));
        }
        else{
            printf("ZERO\n");
        }
    }

    return 0;
}
