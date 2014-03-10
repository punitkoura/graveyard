#include<stdio.h>

int main()
{
    char prime[100001];
    int x,y,t,temp,d,dc,pow;
    int a,b;
    int count;

    for(x=0;x<100001;x++)
    {
        prime[x]=1;
    }

    for(x=2;x<322;x++)
    {
        if(prime[x]==1)
        {
        t = 100000/(x);
        for(y=2;y<=t;y++)
        {
            prime[(x)*y] = 0;
        }
        }
    }
    prime[0]=0;
    prime[1]=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        count = 0;

        if(a>b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
        for(x=a;x<=b;x++)
        {
            dc=0;pow = 1;
            if(prime[x]==1)continue;
            if(x==100000)
            {
                count++;
                continue;
            }
            temp = x;
            while(temp!=0)
            {
                d = temp%10;
                temp/=10;
                pow*=10;
                dc++;
                if(prime[d]==1||prime[temp]==1)break;
            }
            if(temp!=0) continue;

            if(pow>10)
            {
            temp = x%(pow/10);
            while(temp>9)
            {
                if(prime[temp]==1)break;
                temp/=10;
            }

            if(temp>9)continue;
            }

            if(pow>100)
            {
            temp = x%(pow/100);
            while(temp>9)
            {
                if(prime[temp]==1)break;
                temp/=10;
            }

            if(temp>9)continue;
            }

            if(pow>1000)
            {
            temp = x%(pow/1000);
            while(temp>9)
            {
                if(prime[temp]==1)break;
                temp/=10;
            }

            if(temp>9)continue;
            }
            count++;

        }
        printf("%d\n",count);
    }
    return 0;
}
