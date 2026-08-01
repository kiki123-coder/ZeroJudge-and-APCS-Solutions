#include <stdio.h>
#include <string.h>

int main(void)
{
    char num[10];
    char turn[10];
    scanf("%s", num);

    int len=strlen(num);
    int k=len-1;

    for(int i=0; i<len; i++){ //反轉
        turn[i]=num[k];
        k--;
    }

    int j=0;
    for(int i=0; i<len; i++){ //避免輸出前導0
        if(turn[j] == '0'){
            j++;
        }
        else{
            break;
        }
    }

    if(j==len){  //全部為0的狀況
        printf("0");
    }
    else{
        for(; j<len; j++){
            printf("%c", turn[j]);
        }
    }
    return 0;
}
