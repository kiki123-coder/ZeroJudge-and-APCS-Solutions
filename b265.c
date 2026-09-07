#include <stdio.h>
#include <stdlib.h>

long long code[10000];

int compare(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;

    if(x < y)
        return -1;
    if(x > y)
        return 1;

    return 0;
}

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF && n != 0){

        for(int i = 0; i < n; i++){

            int course[5];

            for(int j = 0; j < 5; j++){
                scanf("%d", &course[j]);
            }

            // 排序這個人的5門課
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4 - j; k++){
                    if(course[k] > course[k + 1]){
                        int temp = course[k];
                        course[k] = course[k + 1];
                        course[k + 1] = temp;
                    }
                }
            }

            // 把課程組合編碼
            code[i] = 0;

            for(int j = 0; j < 5; j++){
                code[i] = code[i] * 400 + course[j];
            }
        }

        // 用 qsort 排 n 個組合
        qsort(code, n, sizeof(long long), compare);

        int max = 0;
        int count = 1;
        int answer = 0;

        // 計算並列最多的組合
        for(int i = 1; i <= n; i++){

            if(i < n && code[i] == code[i - 1]){
                count++;
            }
            else{

                if(count > max){
                    max = count;
                    answer = count;
                }
                else if(count == max){
                    answer += count;
                }

                count = 1;
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
