#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;
    double x, y;
    int D;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    D = a * e - b * d;

    if(D != 0){
        x = (double)(c * e - b * f) / D;
        y = (double)(a * f - c * d) / D;

        printf("x=%.2f\n", x);
        printf("y=%.2f\n", y);
    }
    else{
        if(a * f == c * d && b * f == c * e){
            printf("Too many\n");
        }
        else{
            printf("No answer\n");
        }
    }

    return 0;
}
