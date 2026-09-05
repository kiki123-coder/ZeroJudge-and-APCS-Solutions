#include <stdio.h>

int main(void)
{
    int n;
    int x[1000], y[1000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    //排序
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){

            if(x[j] > x[j + 1] || (x[j] == x[j + 1] && y[j] > y[j + 1])){

                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;

                temp = y[j];
                y[j] = y[j + 1];
                y[j + 1] = temp;
            }
        }
    }

    //輸出
    for(int i = 0; i < n; i++){
        printf("%d %d\n", x[i], y[i]);
    }

    return 0;
}
