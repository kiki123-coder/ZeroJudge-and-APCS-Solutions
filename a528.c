#include <stdio.h>
#include <string.h>

int compare(char a[], char b[]);

int main(void)
{
    int a;
    char arr[1000][1000];
    char temp[1000];

    while(scanf("%d", &a) != EOF){

        for(int i = 0; i < a; i++){
            scanf("%s", arr[i]);
        }

        //排序
        for(int i = 0; i < a - 1; i++){
            for(int j = i + 1; j < a; j++){

                if(compare(arr[i], arr[j]) > 0){
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
            }
        }

        //輸出
        for(int i = 0; i < a; i++){
            printf("%s\n", arr[i]);
        }
    }

    return 0;
}

int compare(char a[], char b[])
{
    int negativeA = 0;
    int negativeB = 0;

    if(a[0] == '-'){
        negativeA = 1;
    }

    if(b[0] == '-'){
        negativeB = 1;
    }

    //一個負數、一個正數
    if(negativeA && !negativeB){
        return -1;
    }

    if(!negativeA && negativeB){
        return 1;
    }

    //兩個都是負數
    if(negativeA && negativeB){

        int lenA = strlen(a) - 1;
        int lenB = strlen(b) - 1;

        //絕對值比較，長的反而比較小
        if(lenA > lenB){
            return -1;
        }

        if(lenA < lenB){
            return 1;
        }

        //長度相同，逐位比較
        for(int i = 1; i < strlen(a); i++){
            if(a[i] > b[i]){
                return -1;
            }

            if(a[i] < b[i]){
                return 1;
            }
        }

        return 0;
    }

    //兩個都是正數
    int lenA = strlen(a);
    int lenB = strlen(b);

    if(lenA > lenB){
        return 1;
    }

    if(lenA < lenB){
        return -1;
    }

    //長度相同，逐位比較
    for(int i = 0; i < lenA; i++){
        if(a[i] > b[i]){
            return 1;
        }

        if(a[i] < b[i]){
            return -1;
        }
    }

    return 0;
}
