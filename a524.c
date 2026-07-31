#include <stdio.h>

int n;
int arr[9], used[9];
void dfs(int step)
{
    if(step==n){
        for(int i=0; i<n; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    for(int i=n; i>=1; i--){
        if(used[i] == 0){
            used[i]=1;
            arr[step]=i;

            dfs(step+1);

            used[i]=0;
        }
    }
    return;

}

int main(void)
{
    while(scanf("%d", &n) != EOF){
            dfs(0);
        printf("\n");
    }
}
