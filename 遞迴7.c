#include <stdio.h>

int search(int arr[], int n, int target)
{
    if(n == 0){
        return 0;
    }

    if(arr[n - 1] == target){
        return 1;
    }
    return search(arr, n-1, target);
}

int main(void)
{
    int arr[1000];
    int n;
    int target;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);
    printf("%d", search(arr, n, target));
    return 0;
}
