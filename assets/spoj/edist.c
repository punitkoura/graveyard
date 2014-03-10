#include<stdio.h>

int main()
{
    char a[2000];
    char b[2000];
    char **arr;
    int i,j;
    char c;
    int t;int al,bl;
    scanf("%d",&t);
    int alt1,alt2,alt3;
    while(t--)
    {
        c=0;i=0;
        while(c<=32)c=getchar();
        while(c>32)
        {
            a[i]=c;
            i++;
            c = getchar();
        }
        a[i] = '\0';
        al = i;

        c=0;j=0;
        while(c<=32)c=getchar();
        while(c>32)
        {
            b[j]=c;
            j++;
            c = getchar();
        }
        b[j] = '\0';
        bl = j;

        arr = (char**)malloc(sizeof(char*)*(al+1));

        for(i=0;i<=al;i++)
        {
            arr[i] = (char*)malloc(sizeof(char)*(bl+1));
        }

        arr[0][0] = 0;

        for(i=1;i<=al;i++) arr[i][0] = i;
        for(i=1;i<=bl;i++) arr[0][i] = i;

        for(i=1;i<=al;i++)
        {
            for(j=1;j<=bl;j++)
            {
                alt1 = arr[i-1][j-1] + (a[i-1]==b[j-1]?0:1);
                alt2 = arr[i-1][j]+1;
                alt3 = arr[i][j-1]+1;

                alt1 = (alt1<alt2)?alt1:alt2;
                alt1 = (alt1<alt3)?alt1:alt3;
                arr[i][j] = alt1;
            }
        }
        printf("%d\n",arr[al][bl]);

    }
    return 0;
}
