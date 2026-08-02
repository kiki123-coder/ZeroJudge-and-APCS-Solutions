#include <stdio.h>

int main(void)
{
    char Letter[26]={'A','B','C','D','E','F',
                     'G','H','I','J','K','L',
                     'M','N','O','P','Q','R',
                     'S','T','U','V','W','X',
                     'Y','Z'};
    int Number[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
                     17,18,19,20,21,22,23,24,25};

    char c;
    scanf("%c", &c);
    for(int i=0; i<26; i++){

        if(c == Letter[i]){
            printf("%d", Number[i]);
        }
    }

    return 0;
}
