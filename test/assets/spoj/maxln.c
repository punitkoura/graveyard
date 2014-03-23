#include<stdio.h>


int main()
{
    long r;

    int t;
    scanf("%d",&t);
    int x;
    double ans;
    for(x=1;x<=t;x++)
    {
        scanf("%ld",&r);
        ans = (double)4*r*r + 0.25;

        printf("Case %d: %.2lf\n",x,ans);

    }
    return 0;
}
