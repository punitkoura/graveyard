#include<stdio.h>
int main()
{
    long long int t,a,b,x;
    scanf("%lld",&t);
    int digit;
    long long temp;
    long long temp1;
    while(t--)
    {
        scanf("%lld",&a);
        scanf("%lld",&b);

        digit = a%10;
        if(b==0) printf("1\n");
        else
        {
            temp = b%4;
            temp1 = 1;
            if(temp==0)
            {
                temp1 = digit*digit*digit*digit;
            }
            else
                for(x=1;x<=temp;x++)
                {
                    temp1*=digit;
                }

            temp1 = temp1%10;

            printf("%d\n",temp1);
        }

    }
    return 0;
}
