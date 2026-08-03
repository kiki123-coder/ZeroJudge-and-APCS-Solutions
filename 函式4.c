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
    if(n < 10){
        printf("%s\n", numberTable[n]);
    }
    else{
        int a = n / 10;
        int b = n%10;
        printf("%s %s\n", numberTable[a], numberTable[b]);
    }
}
