#include <stdio.h>

int main(void)
{
    int n;
    int arr[30001] = {0};
    int x;
    int max = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        arr[x]++;

        if(arr[x] > max)
            max = arr[x];
    }

    for(int i = 1; i <= 30000; i++){
        if(arr[i] == max)
            printf("%d   %d\n", i, max);
    }

    return 0;
}
