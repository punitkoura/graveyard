#include<stdio.h>

int main()
{
    long long int t,a,b,c;
    scanf("%lld",&t);
    char ch;
    int sign;
    while(t--)
    {
        a=b=c= 0;
        sign=1;
        ch=0;
        while(ch<=32)ch = getchar();
        if(ch=='-')
        {
            sign=-1;
            ch=getchar();
        }
        while(ch>32)
        {
            a=a*10 + ch-'0';
            ch = getchar();
        }
        a*=sign;

        sign=1;
        ch=0;
        while(ch<=32)ch = getchar();
        if(ch=='-')
        {
            sign=-1;
            ch=getchar();
        }
        while(ch>32)
        {
            b=b*10 + ch-'0';
            ch = getchar();
        }
        b*=sign;

        sign=1;
        ch=0;
        while(ch<=32)ch = getchar();
        if(ch=='-')
        {
            sign=-1;
            ch=getchar();
        }
        while(ch>32)
        {
            c=c*10 + ch-'0';
            ch = getchar();
        }
        c*=sign;

        printf("%lld\n",(a*a - 2*b));
    }
    return 0;
}
