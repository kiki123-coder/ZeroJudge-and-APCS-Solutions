#include <stdio.h>

int main(void)
{
    int n, a;
    while(scanf("%d", &n) != EOF){
        int arr[1000];

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n - 1; i++){

                if(arr[i]%10 > arr[i + 1]%10){
                    int b = 0;
                    b = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = b;
                }


                else if(arr[i]%10 == arr[i + 1]%10){

                    if(arr[i] < arr[i + 1]){
                        int b = 0;
                        b = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = b;
                    }
                }

            }

        }

        for(int j = 0; j < n; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    return 0;
}
