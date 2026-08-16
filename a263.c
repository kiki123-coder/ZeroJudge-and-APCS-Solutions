#include <stdio.h>

int leap(int y);
int date(int y, int m, int d);

int main(void)
{
    int y1, m1, d1;
    int y2, m2, d2;

    while(scanf("%d %d %d", &y1, &m1, &d1) != EOF){
        scanf("%d %d %d", &y2, &m2, &d2);

        int a = date(y1, m1, d1);
        int b = date(y2, m2, d2);

        if(a > b){ // 比較兩個日期的總天數，較大的減較小的
            printf("%d\n", a - b);
        }
        else{
            printf("%d\n", b - a);
        }

    }

    return 0;
}

int leap(int y)
{
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){ //判斷閏年
        return 1;
    }

    return 0;
}

int date(int y, int m, int d) //日期換總天數
{
    int month[13] = {0, 31, 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31};

    int total = y * 365;

    for(int i = 1; i < y; i++){
        if(leap(i)){
            total++;
        }
    }

    for(int i = 1; i < m; i++){
        total += month[i];
    }

    if(m > 2 && leap(y)){
        total++;
    }

    total += d;

    return total;
}
