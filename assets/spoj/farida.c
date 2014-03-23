#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    int n;

    long long int *m;

    int x,y;
    long long int temp;
    for(x=1;x<=t;x++)
    {
        scanf("%d",&n);
        if(n==0)
        {
            printf("Case %d: 0\n",x);
            continue;
        }

        m = (long long int*)malloc(sizeof(long long int)*n);

        for(y=0;y<n;y++)
        {
            scanf("%lld",&temp);
            if(y<=2)
            {
                m[y] = temp;
                if(y==2)m[y] =temp+m[0];
                continue;
            }
            m[y] = ((temp+m[y-2])>(temp+m[y-3]))?(temp+m[y-2]):(temp+m[y-3]);
        }
        if(n==1)printf("Case %d: %lld\n",x,m[0]);
        else printf("Case %d: %lld\n",x,((m[n-1]>m[n-2])?m[n-1]:m[n-2]));
        free(m);
    }
    return 0;
}
