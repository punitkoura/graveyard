#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *a;
    long t;
    t = 100000;
    int m,z;
    int test;



    a = (char*)malloc(sizeof(char)*1000000000);

    int x,y;

	if(a==NULL) return 0;

    for(x=0;x<1000000000;x++)
    {
        a[x] = 0;
    }
    a[0] = 1;

    long n;
    int temp;
    for(x=1;x<t;x++)
    {
        if(a[x]==0)
        {
            temp = x+1;
            n = 1000000000/temp;
            for(y=2;y<=n;y++)
            {
                a[temp*y - 1]=1;
            }
        }
    }

/*
    for(x=0;x<t;x++)
    {
        if(a[x]==0) printf("%d\n",x+1);
    }*/
    scanf("%d",&test);
    for(x=0;x<test;x++)
    {
        scanf("%d",&m);
        scanf("%d",&z);
        for(y=m-1;y<=z-1;y++)
        {
            if(a[y]==0) printf("%d\n",y+1);
        }
        printf("\n");
    }

    return 0;
}
