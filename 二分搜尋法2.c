#include <stdio.h>

int main(void)
{
    int K;
    int wood[4] = {8, 5, 6, 10};

    scanf("%d", &K);

    int answer = 0;
    int left = 1;
    int right = 10;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        int count = 0;

        for(int i = 0; i < 4; i++){
            count += wood[i] / mid;
        }

        if(count >= K){
            answer = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }

    }

    printf("%d\n", answer);

    return 0;
}
