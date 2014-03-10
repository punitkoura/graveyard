#include<stdio.h>

int main()
{
    char c;
    int n;
    scanf("%d",&n);
    int sign;
    long long int num,sum;
    int count=0;
    while(n--)
    {
        c=0;
        sum = num=0;
        sign = 1;
        while(c<=32) c = getchar();
        if(c == '-')
        {
            sign = -1;
            c = getchar();
        }
        while(c>32)
        {
            num= num*10 + (c-'0');
            c = getchar();
        }
        num *= sign;
        sum+=num;


        sign = 1;c=0;num=0;
        while(c<=32) c = getchar();
        if(c == '-')
        {
            sign = -1;
            c = getchar();
        }
        while(c>32)
        {
            num= num*10 + (c-'0');
            c = getchar();
        }
        num *= sign;
        sum+=num;


        sign = 1;c=0;num=0;
        while(c<=32) c = getchar();
        if(c == '-')
        {
            sign = -1;
            c = getchar();
        }
        while(c>32)
        {
            num= num*10 + (c-'0');
            c = getchar();
        }
        num *= sign;
        sum+=num;



        sign = 1;c=0;num=0;
        while(c<=32) c = getchar();
        if(c == '-')
        {
            sign = -1;
            c = getchar();
        }
        while(c>32)
        {
            num= num*10 + (c-'0');
            c = getchar();
        }
        num *= sign;
        sum+=num;



        if(sum==0) count++;
    }

    printf("%d",count);
    return 0;
}
