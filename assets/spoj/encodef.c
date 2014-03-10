#include<stdio.h>

int main()
{
    int m,n;
    int t;
    scanf("%d",&t);
    int u,x,flag;
    int count;
    int s,hi,lo,t1,t2;
    int **arr;
    int z;
    int y;
    char c;
    int temp;
    int en[400];
    int count1;
    for(u=1;u<=t;u++)
    {
        flag=1;
        hi=0;
        t1=0;t2=1;
        s=0;
        count = 0;
        count1=0;
        scanf("%d",&m);
        scanf("%d",&n);
        arr = (int**)malloc(sizeof(int)*m);
        for(x=0;x<m;x++)
        {
            arr[x] = (int*)malloc(sizeof(int)*n);
        }
        c=0;
        c = getchar();
        c=getchar();
        while(c>=32)
        {
            temp = c-' '==0?0:c-'A'+1;
            for(x=4;x>=0;x--)
            {
                en[count1+x] = temp%2;
                temp = temp/2;
            }
            count1+=5;
            c = getchar();
        }
        for(x=count1;x<m*n;x++)
        {
            en[x] = 0;
        }

        temp=0;
        while(flag)
        {
            s=hi;
            hi = n-t2;
            lo = t1;

            for(x=lo;x<=hi;x++)
            {
                count++;
                arr[s][x] = en[temp];
                temp++;


            }
            if(count==m*n)
            {
                flag=0;
                break;
                //continue;
            }
            s = hi;
            hi = m-t2;
            lo = t2;

            for(x=lo;x<=hi;x++)
            {
                count++;
                arr[x][s] = en[temp];
                temp++;


            }
            if(count==m*n)
            {
                flag=0;
                break;
                //continue;
            }
            t1++;
            t2++;
            s = hi;
            hi = t1-1;
            lo = n-t2;

            for(x=lo;x>=hi;x--)
            {
                count++;
                arr[s][x] = en[temp];
                temp++;

            }
            if(count==m*n)
            {
                flag=0;
                break;
                //continue;
            }
            s = hi;
            lo = m-t2;
            hi = t1;

            for(x=lo;x>=hi;x--)
            {
                count++;
                arr[x][s] = en[temp];
                temp++;

            }

            if(count==m*n)
            {
                flag=0;
                break;
                //continue;
            }
        }
        printf("%d ",u);
        for(x=0;x<m;x++)
        {
            for(y=0;y<n;y++)
            {
                printf("%d",arr[x][y]);
            }
        }

        printf("\n");
        free(arr);
    }
    return 0;
}



