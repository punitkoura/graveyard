#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long int n,k,x,*arr,sum=0,l,r,max;
    l =r =  0;
    int flag = 1;
    scanf("%lld",&n);
    scanf("%lld",&k);
    arr = (long long int*)malloc(sizeof(long long int)*n);
    for(x=0;x<n;x++)
    {
        scanf("%lld",&arr[x]);
    }
    sum =max =  arr[0];
    while(flag && r<n)
    {
        r++;
        sum+=arr[r];
        if(sum==k)break;
        while(sum>k)
        {
            sum-=arr[l];
            l++;
        }
        if(sum>max)
            max = sum;
    }
    printf("%lld\n",max);
    return 0;
}
