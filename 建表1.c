#include <stdio.h>

int main(void)
{
    char Letter[256]={0};
    Letter['A']=0;
    Letter['B']=1;
    Letter['C']=2;
    Letter['D']=3;
    Letter['E']=4;
    Letter['F']=5;
    Letter['G']=6;
    Letter['H']=7;
    Letter['I']=8;
    Letter['J']=9;
    Letter['K']=10;
    Letter['L']=11;
    Letter['M']=12;
    Letter['N']=13;
    Letter['O']=14;
    Letter['P']=15;
    Letter['Q']=16;
    Letter['R']=17;
    Letter['S']=18;
    Letter['T']=19;
    Letter['U']=20;
    Letter['V']=21;
    Letter['W']=22;
    Letter['X']=23;
    Letter['Y']=24;
    Letter['Z']=25;


    char c;
    scanf("%c", &c);

    printf("%d", Letter[c]);

    return 0;
}
