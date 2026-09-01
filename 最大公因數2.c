#include <stdio.h>

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    while(m != 0){
        int temp = n%m;
        n = m;
        m = temp;
    }
    printf("%d", n);
    return 0;
}
