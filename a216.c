#include <stdio.h>

long long f(int n){
            if(n == 1){
                return 1;
            }
            return n + f(n - 1);
        }


long long g(int n){
            if(n == 1){
                return 1;
            }
            return f(n) + g(n - 1);
        }
int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%lld %lld\n", f(n), g(n));
    }
}
