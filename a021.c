#include <stdio.h>
#include <string.h>

int main(void)
{
    char numA[10000];
    char op;
    char numB[10000];
    int ans[20000] = {0};

    scanf("%s %c %s", numA, &op, numB);

    int lenA = strlen(numA);
    int lenB = strlen(numB);

    if(op == '+'){

        int b = 0;
        int k = 0;

        for(int i = lenA - 1, j = lenB - 1; i >= 0 || j >= 0; i--, j--){

            int a = 0;

            if(i >= 0){
                a += numA[i] - '0';
            }

            if(j >= 0){
                a += numB[j] - '0';
            }

            a += b;

            ans[k] = a % 10;
            b = a / 10;

            k++;
        }

        if(b != 0){
            ans[k] = b;
            k++;
        }

        for(int i = k - 1; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }

    else if(op == '-'){

        int bigger = 0;

        if(lenA > lenB){
            bigger = 1;
        }
        else if(lenA < lenB){
            bigger = -1;
        }
        else{
            for(int i = 0; i < lenA; i++){ //長度相同時，從左到右逐位比較
                if(numA[i] > numB[i]){
                    bigger = 1;
                    break;
                }

                if(numA[i] < numB[i]){
                    bigger = -1;
                    break;
                }
            }
        }

        char *big;
        char *small;
        int lenBig;
        int lenSmall;

        if(bigger >= 0){
            big = numA;
            small = numB;
            lenBig = lenA;
            lenSmall = lenB;
        }
        else{
            big = numB;
            small = numA;
            lenBig = lenB;
            lenSmall = lenA;
        }

        int borrow = 0;
        int k = 0;

        for(int i = lenBig - 1, j = lenSmall - 1;
            i >= 0;
            i--, j--){

            int a = big[i] - '0' - borrow;
            int b = 0;

            if(j >= 0){
                b = small[j] - '0';
            }

            if(a < b){
                a += 10;
                borrow = 1;
            }
            else{
                borrow = 0;
            }

            ans[k] = a - b;
            k++;
        }

        while(k > 1 && ans[k - 1] == 0){
            k--;
        }

        if(bigger == -1){ //原本 A < B，結果前面加負號
            printf("-");
        }

        for(int i = k - 1; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }

    else if(op == '*'){

        for(int i = lenA - 1; i >= 0; i--){
            for(int j = lenB - 1; j >= 0; j--){

                int a = numA[i] - '0';
                int b = numB[j] - '0';

                int indexA = lenA - 1 - i;
                int indexB = lenB - 1 - j;

                ans[indexA + indexB] += a * b;
            }
        }

        for(int i = 0; i < lenA + lenB; i++){

            if(ans[i] >= 10){
                ans[i + 1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }

        int start = lenA + lenB - 1;

        while(start > 0 && ans[start] == 0){
            start--;
        }

        for(int i = start; i >= 0; i--){
            printf("%d", ans[i]);
        }
    }

    else if(op == '/'){

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

            int q = 0;

            for(int t = 0; t < 9; t++){ //每一位商最多減9次(縮短時間)

                if(lenCurrent < lenB){
                    break;
                }

                int smaller = 0;

                if(lenCurrent == lenB){
                    for(int j = 0; j < lenB; j++){

                        if(current[j] < numB[j] - '0'){
                            smaller = 1;
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

                    int indexB = j - (lenCurrent - lenB);
                    int b;

                    if(indexB < 0){
                        b = 0;
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
