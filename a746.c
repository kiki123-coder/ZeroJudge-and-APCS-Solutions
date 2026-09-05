#include <stdio.h>

int main(void)
{
    int n, m;
    char arr[500][500];

    while(scanf("%d %d", &n, &m) != EOF){

        //初始化
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = ' ';
            }
        }

        int x1, y1;
        int x2, y2;

        //讀取第一個點
        scanf("%d %d", &x1, &y1);

        //依序連接後面的點
        for(int i = 1; i < m; i++){

            scanf("%d %d", &x2, &y2);

            //x相同，代表左右連線
            if(x1 == x2){

                if(y1 < y2){
                    for(int y = y1; y <= y2; y++){
                        arr[x1 - 1][y - 1] = '*';
                    }
                }
                else{
                    for(int y = y2; y <= y1; y++){
                        arr[x1 - 1][y - 1] = '*';
                    }
                }
            }

            //y相同，代表上下連線
            else{

                if(x1 < x2){
                    for(int x = x1; x <= x2; x++){
                        arr[x - 1][y1 - 1] = '*';
                    }
                }
                else{
                    for(int x = x2; x <= x1; x++){
                        arr[x - 1][y1 - 1] = '*';
                    }
                }
            }

            //更新前一個點
            x1 = x2;
            y1 = y2;
        }

        //上方圍欄
        for(int i = 0; i < n + 2; i++){
            printf("-");
        }
        printf("\n");

        //左右圍欄
        for(int i = 0; i < n; i++){
            printf("|");

            for(int j = 0; j < n; j++){
                printf("%c", arr[i][j]);
            }

            printf("|\n");
        }

        //下方圍欄
        for(int i = 0; i < n + 2; i++){
            printf("-");
        }
        printf("\n");
    }

    return 0;
}
