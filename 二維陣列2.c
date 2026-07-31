#include <stdio.h>

int main(void)
{
    int arr[3][3];
    int num=1;

    arr[0][0]=1;
    arr[0][1]=2;
    arr[0][2]=3;
    arr[1][0]=8;
    arr[1][1]=9;
    arr[1][2]=4;
    arr[2][0]=7;
    arr[2][1]=6;
    arr[2][2]=5;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
