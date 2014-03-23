#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int sum,sum1;
    int temp;
    int s1[1000];
    int s2[1000];
    int count=1;
    int x,y;

    while(n!=0)
    {
        sum=0;
        sum1=0;
        for(x=0;x<n;x++)
        {
            s1[x]=0;
            s2[x]=0;
        }
        for(x=0;x<n;x++)
        {
            for(y=0;y<n;y++)
            {
                scanf("%d",&temp);
                sum+=temp;
                s1[x]+=temp;
                s2[y]+=temp;
            }
        }
        for(x=0;x<n;x++)
        {
            sum1+=(s1[x]-s2[x]>0)?s1[x]-s2[x]:s2[x]-s1[x];
        }
        printf("%d. %d %d\n",count,sum,sum1);
        count++;
        scanf("%d",&n);
    }
    return 0;
}
