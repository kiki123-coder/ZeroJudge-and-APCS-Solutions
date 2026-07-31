#include <stdio.h>

int main(void)
{
    int T, N, M;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        scanf("%d %d", &N, &M);
        int arr[100][100];
        int top=0;
        int left=0;
        int right=N-1;
        int bottom=N-1;
        int num=1;

        if(M==1){
            while(top<=bottom && left<=right){

                //往右
                for(int i=left; i<=right; i++){
                    arr[top][i]=num;
                    num++;
                }

                //往下
                for(int i=top+1; i<=bottom; i++){
                    arr[i][right]=num;
                    num++;
                }

                //往左
                for(int i=right-1; i>=left; i--){
                    arr[bottom][i]=num;
                    num++;
                }

                //往上
                for(int i=bottom-1; i>top; i--){
                    arr[i][left]=num;
                    num++;
                }
                top++;
                bottom--;
                left++;
                right--;

            }
        }

        else if(M==2){
            while(top<=bottom && left<=right){

                //往下
                for(int i=top; i<=bottom; i++){
                    arr[i][left]=num;
                    num++;
                }

                //往右
                for(int i=left+1; i<=right; i++){
                    arr[bottom][i]=num;
                    num++;
                }

                //往上
                for(int i=bottom-1; i>=top; i--){
                    arr[i][right]=num;
                    num++;
                }

                //往左
                for(int i=right-1; i>left; i--){
                    arr[top][i]=num;
                    num++;
                }

                top++;
                bottom--;
                left++;
                right--;

            }

        }



        for(int k=0; k<N; k++){
            for(int j=0; j<N; j++){
                printf("%5d", arr[k][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
