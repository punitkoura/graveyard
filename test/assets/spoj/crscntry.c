#include<stdio.h>

int main()
{
    int ag[2000];
    int tom[2000];
    //int l[2000][2000];
    int**l;

    int t,m,n;
    scanf("%d",&t);
    int temp;

    int i,j;
    int max;

    while(t--)
    {
        m=n=0;
        max = 0;
        scanf("%d",&ag[m]);
        while(ag[m]!=0)
        {
            m++;
            scanf("%d",&ag[m]);
        }

        l = (int**)malloc(sizeof(int*)*(m+1));

        scanf("%d",&temp);
        while(temp!=0)
        {
            n=0;
            tom[0]=temp;
            while(tom[n]!=0)
            {
                n++;
                scanf("%d",&tom[n]);
            }


            for(i=0;i<=m;i++)
            {
                l[i]=(int*)malloc(sizeof(int)*(n+1));
            }
            for(i=0;i<=m;i++)
            {
                for(j=0;j<=n;j++)
                {
                    if(i==0||j==0)l[i][j]=0;
                    else if(ag[i-1]==tom[j-1])l[i][j]=l[i-1][j-1]+1;
                    else
                    {
                        l[i][j]=(l[i-1][j]>l[i][j-1])?l[i-1][j]:l[i][j-1];
                    }
                }
            }
            if(max<l[m][n])max = l[m][n];
            for(i=0;i<=m;i++)
            {
                free(l[i]);;
            }
            scanf("%d",&temp);

        }
        printf("%d\n",max);
        free(l);
    }
    return 0;
}
