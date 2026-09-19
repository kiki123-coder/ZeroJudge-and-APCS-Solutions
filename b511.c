#include <stdio.h>

int N;
int arr[5];
int ans[5];

void dfs(int t, int sum);

int main(void)
{
    int M;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &M);

    dfs(0, M);

    return 0;
}

void dfs(int t, int sum)
{
    if(t == N){
        if(sum == 0){
            printf("(");

            for(int i = 0; i < N; i++){
                if(i > 0)
                    printf(",");

                printf("%d", ans[i]);
            }

            printf(")\n");
        }

        return;
    }

    for(int i = 0; i <= sum / arr[t]; i++){
        ans[t] = i;
        dfs(t + 1, sum - i * arr[t]);
    }
}
