#include <stdio.h>

char ans[30];
int N;

int dfs(int a, int left, int right);

int main(void)
{
    while(scanf("%d", &N) != EOF){
        dfs(0, 0, 0);

        printf("\n");
    }

    return 0;
}

int dfs(int a, int left, int right)
{
    if(left > N || right > left){ //如果不合法
        return 0;
    }

    if(a == N * 2){ //如果填滿
        ans[a] = '\0'; //補結尾
        printf("%s\n", ans);
        return 0;
    }

    //嘗試放置
    ans[a] = '(';
    dfs(a + 1, left + 1, right);

    ans[a] = ')';
    dfs(a + 1, left, right + 1);

    return 0;
}
