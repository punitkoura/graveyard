#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int x,y;
    int i;
    for(i=0;i<t;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);

        if(x==y || y==(x-2))
        {
            if(x==0 && y==0)printf("%d\n",0);
            else if(x%2==0)printf("%d\n",x+y);
            else printf("%d\n",x+y-1);
        }
        else printf("No Number\n");

    }
    return 0;
}
