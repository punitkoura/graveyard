#include<stdio.h>

char *arr;
int k,l;
char coin(int n)
{
    if(arr[n]!=2) return arr[n];

    char a,b,c;
    a = coin(n-1);
    b = coin(n-k);
    c = coin(n-l);

    if(a==1 || b==1 || c==1)
    arr[n] = 0;
    else
    arr[n] = 1;
    return arr[n];
}

int main()
{
    arr = (char*)malloc(sizeof(char)*1000001);
    int m;
    int n;
    scanf("%d",&k);
    scanf("%d",&l);
    scanf("%d",&m);
    int x;
    for(x=0;x<=1000000;x++)arr[x]=2;
    arr[0]=arr[1]=0;
    int ch = 1;

    for(x=2;x<k;x++)
    {
        arr[x] = !arr[x-1];
    }
    arr[k] = 0;
    arr[k+1] = 1;
    for(x=k+2;x<l;x++)
    {
        if(arr[x-1]==1 || arr[x-k]==1)
        arr[x] = 0;
        else
        arr[x] = 1;
    }

    arr[l] = 0;
/*
    for(x=l+1;x<=1000000;x++)
    {
        if(arr[x-1]==1 || arr[x-k]==1 || arr[x-l]==1)
        arr[x] = 0;
        else
        arr[x] = 1;
    }
*/
    char temp;
    while(m--)
    {
        scanf("%d",&n);
        printf("hi\n");
        temp = coin(n);
        printf("%c",(temp==0)?'A':'B');
        /*
        if(arr[n]==0)printf("%c",'A');
        else printf("%c",'B');
        */
    }
    printf("\n");

    free(arr);
    return 0;
}
