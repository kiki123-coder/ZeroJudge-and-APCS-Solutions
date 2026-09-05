#include <stdio.h>

int arr[31];
int ans[31];
int n, m;
int found = 0;

//±ÆÄò
void sort(void)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void dfs(int index, int sum, int count)
{
    if(sum == m){
        for(int i = 0; i < count; i++){
            if(i > 0)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");

        found = 1;
        return;
    }

    if(sum > m || index == n)
        return;

    for(int i = index; i < n; i++){
        ans[count] = arr[i];

        dfs(i + 1, sum + arr[i], count + 1);
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort();

    dfs(0, 0, 0);

    if(found == 0){
        printf("-1\n");
    }

    return 0;
}
