#include <stdio.h>

int main(void)
{
    int arr[4];
    while(scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]) != EOF){

        int run;
        scanf("%d", &run);

        for(int i=0; i<run; i++){
            int test[4];
            int A=0, B=0;
            int used_test[4]={0};
            int used_arr[4]={0};
            scanf("%d %d %d %d", &test[0], &test[1], &test[2], &test[3]);

            for(int j=0; j<4; j++){
                //A
                if(test[j] == arr[j]){
                    A=A+1;
                    used_arr[j]=1;  //¬ö¿ý¤w¨Ï¥Î¹Lªºarr¸òtest
                    used_test[j]=1;

                }
            }

                for(int j=0; j<4; j++){

                    if(used_test[j]){
                        continue;
                    }

                for(int k=0; k<4; k++){
                    //B
                    if(test[j] == arr[k] && used_arr[k]==0){
                        B=B+1;
                        used_arr[k]=1;
                        used_test[j]=1;
                        break;
                        }

                    }
                }

            printf("%dA%dB\n", A, B);
        }
    }
    return 0;
}
