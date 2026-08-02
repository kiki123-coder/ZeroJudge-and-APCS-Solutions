#include <stdio.h>

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

    char c;
    scanf("%c", &c);

    printf("%d", romanTable[c]);

    return 0;
}
