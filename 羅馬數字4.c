#include <stdio.h>
#include <string.h>

/*數字變羅馬數字，只能輸入表上正規數字*/

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

        int len = strlen(num);

        if(num[0] == '#'){
            return 0;
        }

        for(int i = 0; i < 256; i++){
            int digit = num[0] - '0';
            if(romanTable[i] == digit){
                printf("%c\n", i);
            }
        }
    }

    return 0;
}

