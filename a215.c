#include <stdio.h>

int main(void)
{
    long long m, n;

    while(scanf("%lld %lld", &n, &m) != EOF){

        long long sum = 0, run = 0;

        for(long long i = n; ; i++){
            sum += i;
            run++;

            if(sum > m)
                break;
        }

        printf("%lld\n", run);
    }

    return 0;
}

