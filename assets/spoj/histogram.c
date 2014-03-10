#include<stdio.h>

int main()
{
    long long int *arr = (long long int*)malloc(sizeof(long long int)*100001);
    int n,x;
    int count;
    long long int temp;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%lld",&temp);
        arr[1] = temp;
        count = 1;
        for(x=2;x<=n;x++)
        {
            scanf("%lld",&temp);
            if(temp>=(arr[x-1]/count))
            {
                if(temp >= arr[x])
                {
                    arr[x] = temp;
                    count = 1;
                }
                else
                {
                    arr[x] = arr[x-1]+
                }
            }
        }
        scanf("%d",&n);
    }
}
