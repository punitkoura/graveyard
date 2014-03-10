#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int num;
    char c;
    int count=0;
    while(n--)
    {
        c = 0;
        num=0;
        while(c<=32) c=getchar();
        while(c>32)
        {
            num=num*10 + c-'0';
            c = getchar();
        }
        if(num%k==0)count++;
    }
    printf("%d\n",count);
    return 0;
}
