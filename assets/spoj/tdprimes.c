#include<stdio.h>
#define h 100000000

void fo(int n)
{
    char c;
    int t,d;
    t=0;
    while(n!=0)
    {
        d=n%10;
        n=n/10;
        t=t*10 + d;
    }


    while(t!=0)
    {
        c = (char)(t%10 + '0');
        putchar_unlocked(c);
        t/=10;
    }
    c='\n';
    putchar_unlocked(c);
    return;
}

int main()
{
    char* arr;
    arr = (char*)malloc(sizeof(char)*(h+1));

    int x,y,t;
    int count=0;
    arr[1]=0;
    for(x=2;x<=h;x++)arr[x]=1;

    for(x=2;x<=10000;x++)
    {
        if(arr[x]==1)
        {
            t = h/x;
            for(y=2;y<=t;y++)
            {
                arr[x*y] = 0;
            }
        }
    }

    for(x=1;x<=10000;x++)
    {
        if(arr[x])
        {
            count++;
            if(count%100==1) fo(x);;
        }
    }
    return 0;
}
