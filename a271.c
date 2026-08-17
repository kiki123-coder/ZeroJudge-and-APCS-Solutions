#include <stdio.h>

int main(void)
{
    int round;
    int x, y, z, w, n, m;
    int food = 0;
    int poison = 0; //中毒程度
    int alive = 1;
    char c;

    scanf("%d", &round);

    while(round != 0){
        scanf("%d %d %d %d %d %d", &x, &y, &z, &w, &n, &m);

        poison = 0;
        alive = 1;

        getchar();

        while((c = getchar()) != '\n' && c != EOF){

            if(c >= '0' && c <= '4'){
                food = c - '0';

                if(alive){
                    // 早上先扣掉之前的中毒
                    m -= poison;

                    if(m <= 0){
                        alive = 0;
                    }
                    else{
                        // 晚上吃蘿蔔
                        if(food == 1){
                            m += x;
                        }
                        else if(food == 2){
                            m += y;
                        }
                        else if(food == 3){
                            m -= z;
                        }
                        else if(food == 4){
                            m -= w;
                            poison += n;
                        }

                        if(m <= 0){
                            alive = 0;
                        }
                    }
                }
            }
        }

        if(alive){ //還活著
            printf("%dg\n", m);
        }
        else{ //掛了
            printf("bye~Rabbit\n");
        }

        round--;
    }

    return 0;
}
