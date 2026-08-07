#include <stdio.h>

int main(void)
{
    int arr[100];
    int n;
    int target;

    scanf("%d", &n); //輸入資料

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    int left = 0; //設定範圍
    int right = n - 1;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == target){
            printf("Found");
            return 0;
        }
        else if(target > arr[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

        printf("Not Found");

    return 0;
}
