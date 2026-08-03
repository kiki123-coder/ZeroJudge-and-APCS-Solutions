#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int top = 0;
    int bottom = N - 1;
    int left = 0;
    int right = N - 1;
    int arr[100][100];
    int num = 1;

    while(top <= bottom && left <= right){

        //第一列往右
        for(int i = left; i <= right; i++){
            arr[top][i] = num;
            num++;
        }

        //往下
        for(int i = top + 1; i <= bottom; i++){
            arr[i][right] = num;
            num++;
        }

        //往左
        for(int i = right - 1; i >= left; i--){
            arr[bottom][i] = num;
            num++;
        }

        //往上
        for(int i = bottom - 1; i > top; i--){
            arr[i][left] = num;
            num++;
        }
        top++;
        bottom--;
        left++;
        right--;

    }


    for(int k = 0; k < N; k++){
        
        for(int j = 0; j < N; j++){
            printf("%d\t", arr[k][j]);
        }
        
        printf("\n");
    }
    return 0;
}
