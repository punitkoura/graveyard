#include<stdio.h>

int N = 100001;
int main()
{
    int n;
    scanf("%d",&n);
    long long int *arr;
    arr = (long long int*)malloc(sizeof(long long int)*(N+n));
    int x;
    for(x=n-1;x>=0;x--)
    {
        scanf("%d",&arr[x]);
    }
    int q;
    scanf("%d",&q);
    int l,r;
    int c;
    int y;
    long long int sum = 0;
    for(x=1;x<=q;x++)
    {

        scanf("%d",&c);
        if(c==1)
        {
            sum = 0;
            scanf("%d",&l);
            scanf("%d",&r);
            for(y=n-l;y>=n-r;y--)
                sum+=arr[y];
            printf("%lld\n",sum);
        }
        else
        {
            scanf("%d",&arr[n]);
            n++;
        }
    }
    return 0;
}
