#include <stdio.h>

char *numberTable[10] = {"Zero", "One", "Two", "Three", "Four",
                         "Five", "Six", "Seven", "Eight", "Nine"};
void printNumber(int n);

int main(void)
{

    int n;
    scanf("%d", &n);

    printNumber(n);

    return 0;
}

void printNumber(int n)
{
    int digit[20];
    int i = 0;

    if(n == 0){
        printf("Zero");
        return;
    }

    while(n > 0){
        digit[i] = n%10;
        n = n / 10;
        i++;
    }

    for(i = i - 1; i >= 0; i--){
        printf("%s ", numberTable[digit[i]]);
    }
}
