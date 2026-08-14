#include <stdio.h>
#include <string.h>

int stack[1000];
char opStack[1000];

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int priority(char op);
int calculate(int a, int b, char op);

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

                else { //處理符號

                    if(str[i] == '('){
                        opStack[opTop] = '(';
                        opTop++;
                    }
                    else if(str[i] == ')'){ //處理括號裡的運算

                        if(i >= 2 && str[i - 2] != ')'){ //進入括號前的數字放入stack
                            stack[top] = num;
                            top++;
                            num = 0;
                        }

                        while(opStack[opTop - 1] != '('){ //運算

                            char op = opStack[opTop - 1];
                            opTop--;

                            int b = stack[top - 1];
                            top--;

                            int a = stack[top - 1];
                            top--;

                            stack[top] = calculate(a, b, op);
                            top++;
                        }

                        opTop--;
                    }
                    else{ //處理括號外運算

                        if(i >= 2 && str[i - 2] != ')'){
                            stack[top] = num;
                            top++;
                            num = 0;
                        }

                        while(opTop > 0 && opStack[opTop - 1] != '(' && priority(opStack[opTop - 1]) >= priority(str[i])){

                            char op = opStack[opTop - 1];
                            opTop--;

                            int b = stack[top - 1];
                            top--;

                            int a = stack[top - 1];
                            top--;

                            stack[top] = calculate(a, b, op);
                            top++;
                        }

                        opStack[opTop] = str[i];
                        opTop++;
                    }
                }
            }
        }

        if(strlen(str) >= 2 && str[strlen(str) - 2] != ')'){ //處理優先權
            stack[top] = num;
            top++;
        }

        while(opTop > 0){

            char op = opStack[opTop - 1];
            opTop--;

            int b = stack[top - 1];
            top--;

            int a = stack[top - 1];
            top--;

            stack[top] = calculate(a, b, op);
            top++;
        }

        printf("%d\n", stack[top - 1]);
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

int priority(char op)
{
    if(op == '+' || op == '-'){
        return 1;
    }
    else if(op == '*' || op == '/' || op == '%'){
        return 2;
    }

    return -1;
}

int calculate(int a, int b, char op)
{
    if(op == '+'){
        return add(a, b);
    }
    else if(op == '-'){
        return sub(a, b);
    }
    else if(op == '*'){
        return mul(a, b);
    }
    else if(op == '/'){
        return div(a, b);
    }
    else if(op == '%'){
        return mod(a, b);
    }

    return 0;
}
