#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a;
        long long b, c;
        long long ans;
        scanf("%d %lld %lld", &a, &b, &c);

        if(a==1){
            ans=b+c;
            printf("%lld\n", ans);
        }
        else if(a==2){
            ans=b-c;
            printf("%lld\n", ans);
        }
        else if(a==3){
            ans=b*c;
            printf("%lld\n", ans);
        }
        else{
            ans=b/c;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
