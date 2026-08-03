#include <stdio.h>

int findMax(int arr[], int n)
{
    if(n == 1){
        return arr[0];
    }

    int max = findMax(arr, n - 1);

    if(arr[n - 1] > max){
        return arr[n - 1];

    }
    else{
        return max;
    }

}

int main(void)
{
    int arr[1000];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d", findMax(arr, n));
    return 0;
}
