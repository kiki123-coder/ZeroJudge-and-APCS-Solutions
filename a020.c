#include <stdio.h>

int main(void)
{
    char Letter[26] = {'A', 'B', 'C', 'D', 'E', 'F',
                       'G', 'H', 'I', 'J', 'K', 'L',
                       'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X',
                       'Y', 'Z'};
    int Number[26]={10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24,
                     25, 26, 27, 28, 29, 32, 30, 31, 33};

    char ID[10];
    int check = 0;
    int num = 0;
    int a = 0;
    int b = 0;

    scanf("%s", ID);

    for(int i = 0; i < 26; i++){
        if(ID[0] == Letter[i]){
            int num = 0;

            num = Number[i]%10;
            check = Number[i] / 10 + num * 9;

        }
    }


    num = 8;
    for(int i = 1; i < 9; i++){

        a = ID[i] - '0';
        b = a * num;

        check = check + b;
        num = num - 1;
    }

    a = ID[9] - '0';
    check = check + a;

    if(check%10 == 0){
        printf("real");
    }
    else{
        printf("fake");
    }
    return 0;
}
