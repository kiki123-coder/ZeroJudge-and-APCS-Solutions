#include <stdio.h>

int main(void)
{
    int arr[3][3];
    int num = 1;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                arr[j][k] = num;
                num++;
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

    return 0;
}
