#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int t;
    scanf("%d",&t);
    int *arr;
    int x;
    int hi;
    int index;
    long long sum;
    long long sum1;
    long long s;
    while(t--)
    {
        scanf("%d",&n);
        sum = 0;
        arr = (int*)malloc(sizeof(int)*n);

        for(x=0;x<n;x++)
        {
            scanf("%d",&arr[x]);
            sum +=arr[x];

        }
        sum1 = 0;
        index = 0;
        s = sum;
        for(x=0;x<n;x++)
        {
            if(x==0)
            {
                sum=sum-arr[x];
                if(sum<s)
                {
                    s = sum;
                    index = x;
                }

            }
            else if(x==n-1)
            {

                sum1+=arr[x-1];
                sum = 0;
                if(sum1<s)
                {
                    s = sum1;
                    index = x;
                }

            }
            else
            {
                sum1+=arr[x-1];
                sum-=arr[x];


                if(sum1<sum)
                {
                    if((2*sum1+sum) < s)
                    {
                        s = 2*sum1+sum;
                        index = x;
                    }
                }
                else
                {
                    if((2*sum+sum1)<s)
                    {
                        s = 2*sum+sum1;
                        index = x;
                    }
                }


            }
        }
        printf("%d\n",s);
    }
    return 0;
}
