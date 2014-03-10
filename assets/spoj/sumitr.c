#include<stdio.h>
int main()
{
    int i,s,t,x,y,n,u,v;
    scanf("%d",&t);
    while(t--)
    {
        i=0;
        scanf("%d",&n);
        scanf("%d",&s);
        for(x=1;x<n;x++)
        {
            for(y=0;y<=x;y++)
            {
                scanf("%d",&u);
                if(y==i)
                {
                    y++;
                    scanf("%d",&v);
                    printf("u %d v %d \n",u,v);
                    if(u>v)
                    {
                        s+=u;
                    }
                    else
                    {
                        i++;
                        s+=v;
                    }
                    u=v;
                }
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
