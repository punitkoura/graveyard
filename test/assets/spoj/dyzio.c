#include<stdio.h>


int hit,v,max,maxv;

int recurse(char *arr,int n)
{
    int l = arr[n] - '0';
    if(l==1)
    {
        //printf("max = %d hit = %d maxv = %d v = %d n= %d\n",max,hit,maxv,v,n);
        hit++;
        v++;
        if(max<hit)
        {
            max = hit;
            maxv = v;
        }
        //printf("max = %d hit = %d maxv = %d v = %d n= %d\n",max,hit,maxv,v,n);
        int m = recurse(arr,n+1);
        //printf("max = %d hit = %d maxv = %d v = %d n= %d\n",max,hit,maxv,v,n);
        hit++;
        int p = recurse(arr,m+1);
        //printf("max = %d hit = %d maxv = %d v = %d n= %d\n",max,hit,maxv,v,n);
        hit--;
        return p;
    }
    else
    {
        //printf("max = %d hit = %d maxv = %d v = %d n= %d\n",max,hit,maxv,v,n);
        hit--;
        return n;
    }
}

int main()
{
    char *arr;
    int n;
    int x;
    int p;
    for(x=1;x<=10;x++)
    {
        scanf("%d",&n);
        arr = (char*)malloc(sizeof(char)*(n+1));
        scanf("%s",arr);
        hit=max=maxv=v=0;
        p = recurse(arr,0);
        printf("%d\n",maxv);
        free(arr);
    }

    return 0;
}
