#include <stdio.h>

int main(void)
{
    int T, N, M;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        scanf("%d %d", &N, &M);
        int arr[10000];
        int N2=0;
        N2=N*N;

        for(int j=0; j<N2; j++){
            arr[j]=j+1;
        }

        if(M==1){ //¶¶®É°w
            for(int k=0; k<N; k++){
                printf("%d     ", arr[k]);
            }
            printf("\n");

        }
    }
}
