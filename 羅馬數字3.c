#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*檔案2增加函式*/

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
            printf("%d\n",ans);
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
