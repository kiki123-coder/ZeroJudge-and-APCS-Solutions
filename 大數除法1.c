#include <stdio.h>
#include <string.h>

int main(void)
{
    char numA[10000];
    char op;
    char numB[10000];
    int ans[10000] = {0};

    scanf("%s %c %s", numA, &op, numB);

    int lenA = strlen(numA);
    int lenB = strlen(numB);

    if(op == '/'){

        int current[10000] = {0};
        int lenCurrent = 0;
        int k = 0;

        for(int i = 0; i < lenA; i++){

            current[lenCurrent] = numA[i] - '0';
            lenCurrent++;

            while(lenCurrent > 1 && current[0] == 0){
                for(int j = 0; j < lenCurrent - 1; j++){
                    current[j] = current[j + 1];
                }
                lenCurrent--;
            }

            int q = 0; //商

            while(1){

                if(lenCurrent < lenB){ //current 比除數短，不能再減
                    break;
                }

                if(lenCurrent == lenB){
                    int smaller = 0;

                    for(int j = 0; j < lenB; j++){
                        if(current[j] < numB[j] - '0'){
                            smaller = 1; //current 比除數小
                            break;
                        }

                        if(current[j] > numB[j] - '0'){
                            break;
                        }
                    }

                    if(smaller){
                        break;
                    }
                }

                int borrow = 0;

                for(int j = lenCurrent - 1; j >= 0; j--){

                    int indexB = j - (lenCurrent - lenB); //讓除數和 current 右對齊
                    int b;

                    if(indexB < 0){
                        b = 0; //沒有對應位數就當成 0
                    }
                    else{
                        b = numB[indexB] - '0';
                    }

                    int a = current[j] - b - borrow;

                    if(a < 0){
                        a += 10;
                        borrow = 1;
                    }
                    else{
                        borrow = 0;
                    }

                    current[j] = a;
                }

                while(lenCurrent > 1 && current[0] == 0){
                    for(int j = 0; j < lenCurrent - 1; j++){
                        current[j] = current[j + 1];
                    }
                    lenCurrent--;
                }

                q++;
            }

            ans[k] = q;
            k++;
        }

        int start = 0;

        while(start < k - 1 && ans[start] == 0){
            start++;
        }

        for(int i = start; i < k; i++){
            printf("%d", ans[i]);
        }
    }

    return 0;
}
