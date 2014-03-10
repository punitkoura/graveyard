#include<stdio.h>

int main()
{
    int p,q,r;
    int t;
    scanf("%d",&t);
    char c;
    int num;
    while(t--)
    {
        c = 0;
        p=q=r=0;
        num=0;
        while(c<=32)c = getchar();

        while(c>32)
        {
            if(c=='m')
            {
                num=1;
            }
            p = p*10 + c-'0';
            c = getchar();
        }
        printf("p = %d\n",p);
        c=0;
        while(c<=32)c = getchar();
        printf("char is %c",c);
        c=0;
        while(c<=32) c = getchar();
        while(c>32)
        {
            if(c=='m')
            {
                num=2;
            }
            q = q*10 + c-'0';
            c = getchar();
        }

        c=0;
        while(c<=32)c = getchar();

        while(c>32)
        {
            if(c=='m')
            {
                num=3;
            }
            r = r*10 + c-'0';
            c = getchar();
        }
        printf("")
        switch(num)
        {
            case 1:
            p = r-q;
            printf("%d + %d = %d\n",p,q,r);
            break;

            case 2:
            q = r-p;
            printf("%d + %d = %d\n",p,q,r);
            break;

            case 3:
            r = p+q;
            printf("%d + %d = %d\n",p,q,r);
            break;
        }
    }
    return 0;
}
