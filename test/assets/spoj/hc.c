#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int lc;
    char c;
    int bit;
    while(t--)
    {
        bit = 0;
        n=0;
        c=0;
        while(c<=32)c=getchar();
        while(c>32)
        {
            n = n*10 + c-'0';
            c=getchar();
        }
        while(n--)
        {
            c=0;
            while(c<=32)c = getchar();
            if(c=='l')bit=!bit;

            c = getchar();
            c = getchar();
        }
        if(bit) printf("lxh\n");
        else printf("hhb\n");
    }
    return 0;
}
