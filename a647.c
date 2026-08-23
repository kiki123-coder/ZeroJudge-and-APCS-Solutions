#include <stdio.h>

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF){
        int m, p;

        while(n != 0){
            scanf("%d %d", &m, &p);

            double x;

            x = (double)(p - m) / m * 100;

            if(x > 0){
                x += 0.000000001;
            }
            else if(x < 0){
                x -= 0.000000001;
            }

            if(x == 0){
                x = 0;
            }

            if(x >= 10.00 || x <= -7.00){
                printf("%6.2f%% dispose\n", x);
            }
            else{
                printf("%6.2f%% keep\n", x);
            }

            n--;
        }
    }

    return 0;
}
