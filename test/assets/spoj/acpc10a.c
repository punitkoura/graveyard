#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int r;
    while(a!=0 || b!=0 || c!=0)
    {
        if(b-a == c-b)
        {
            printf("AP %d\n",c+b-a);
        }
        else
        {
            r = b/a;
            printf("GP %d\n",c*r);
        }
        scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    }
    return 0;
}
