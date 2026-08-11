#include <stdio.h>
#include <string.h>

/*羅馬數字轉阿拉伯數字，有加法*/

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
    while(scanf("%s", roman) == 1){
        int sum=0;
        int len=strlen(roman);
        if(roman[0]=='#'){
            return 0;
        }

        for(int i=0; i<len; i++){
            char a, b;
            a=roman[i];
            b=roman[i+1];

            if(romanTable[a]>=romanTable[b]){
                sum=sum+romanTable[a];
            }
            else{
                sum=sum-romanTable[a];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
