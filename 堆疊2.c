#include <stdio.h>

char stack[1000];
int top = -1;

void push(char n)
{
    top++;
    stack[top] = n;
}

char pop(void)
{
    char x = stack[top];
    top--;
    return x;
}

int main(void)
{
    char str[1000];
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){

        if(str[i] == '('){
            push('(');
        }
        else if(str[i] == ')'){

            if(top == -1){
                printf("N");
                return 0;
            }
            else{
                pop();
            }

        }
    }

    if(top == -1){
        printf("Y");
    }
    else{
        printf("N");
    }

    return 0;
}
