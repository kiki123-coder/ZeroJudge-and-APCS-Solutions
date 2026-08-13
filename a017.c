#include <stdio.h>
#include <string.h>

int stack[1000];
char opStack[1000];

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

int main(void)
{
    char str[1000];

    while(fgets(str, 1000, stdin) != NULL){
        int num = 0;
        int top = 0;
        int opTop = 0;

        for(int i = 0; i < strlen(str); i++){

            if(str[i] != ' ' && str[i] != '\n'){

                if(str[i] >= '0' && str[i] <= '9'){

                    num = num * 10 + str[i] - '0';
                }

                else {
                    stack[top] = num;
                    top++;
                    num = 0;

                    if(str[i] == '('){
                        opStack[opTop] = '(';
                        opTop++;
                    }
                    else if(str[i] == ')'){ //處理括號裡的運算

                        while(opStack[opTop - 1] != '('){

                            if(opStack[opTop - 1] == '*' || opStack[opTop - 1] == '/' || opStack[opTop - 1] == '%'){
                                if(opStack[opTop - 1] == '*'){
                                    int b = stack[--top];
                                    int a = stack[--top];

                                    int ans = mul(a, b);

                                    stack[top] = ans;
                                    top++;
                                    opTop--;
                                }
                                else if(opStack[opTop - 1] == '/'){
                                    int b = stack[--top];
                                    int a = stack[--top];

                                    int ans = div(a, b);

                                    stack[top] = ans;
                                    top++;
                                    opTop--;
                                }
                                else if(opStack[opTop - 1] == '%'){
                                    int b = stack[--top];
                                    int a = stack[--top];

                                    int ans = mod(a, b);

                                    stack[top] = ans;
                                    top++;
                                    opTop--;
                                }
                              }
                            if(opStack[opTop - 1] == '+'){
                                int b = stack[--top];
                                int a = stack[--top];

                                int ans = add(a, b);

                                stack[top] = ans;
                                top++;
                                opTop--;
                              }
                              else if(opStack[opTop - 1] == '-'){
                                int b = stack[--top];
                                int a = stack[--top];

                                int ans = sub(a, b);

                                stack[top] = ans;
                                top++;
                                opTop--;
                              }

                        }

                        opTop--;   // 把 '(' 移掉
                    }

                    //處理括號外的運算
                    if(str[i] == '*' || str[i] == '/' || str[i] == '%'){

                    }


                }

            }

        }

        stack[top] = num; //最後一位
        top++;

    }
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int mod(int a, int b)
{
    return a%b;
}
