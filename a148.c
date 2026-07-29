#include<stdio.h>
int main(void)
{
    int n, s;
    while(scanf("%d",&n)!=EOF){

        int sum=0;
        double avg;
        for(int i=0;i<n;i++){

            scanf("%d",&s);
            sum=sum+s;

        }

        avg=(double)sum/n;//锣疊翴计磷计场だ礚猭秈︽ゑ耕
        /*肈ヘ璶―だ计蝶基夹非*/
        if(avg>59){
            printf("no\n");
        }
        else if(avg<=59){
            printf("yes\n");
        }
    }

    return 0;
}
