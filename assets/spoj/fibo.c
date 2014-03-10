#include<stdio.h>

long fib(int n,long* arr)
{
    if(arr[n]!=-1) return arr[n];
    else if(n==0 || n==1)
    {
        arr[n] = 1;
        return arr[n];
    }
    else
    {
        long ans = fib(n-1,arr)+fib(n-2,arr);
        arr[n] = ans;
        return ans;
    }
}

long fiboN(int n)
{
    if(n==1 || n==0) return 1;
    else return fiboN(n-1)+fiboN(n-2);
}

int main()
{
    long* arr;
    arr = (long*) malloc(sizeof(long)*100);
    int t;
    int n;
    scanf("%d",&t);
    int c;
    int x;
    for(x=0;x<100;x++)arr[x] = -1;

    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&c);
        if(c==0) printf("%ld",fib(n,arr));
        if(c==1) printf("%ld",fiboN(n));

    }
}
