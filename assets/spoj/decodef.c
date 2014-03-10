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
    int in[5];
    int z;
    int y;
    char c;
    int temp;
    for(u=1;u<=t;u++)
    {
        flag=1;
        hi=0;
        t1=0;t2=1;
        s=0;
        count = 0;
        scanf("%d",&m);
        scanf("%d",&n);
        arr = (int**)malloc(sizeof(int)*m);
        for(x=0;x<m;x++)
        {
            arr[x] = (int*)malloc(sizeof(int)*n);
        }
        c=0;
        while(c<33)c = getchar();

        for(x=0;x<m;x++)
        {
            for(y=0;y<n;y++)
            {
                arr[x][y]=c-'0';
                c = getchar();
            }
        }
        z = 0;
        printf("%d ",u);
        while(1)
        {
            s=hi;
            hi = n-t2;
            lo = t1;

            for(x=lo;x<=hi;x++)
            {
                count++;
                in[z] = arr[s][x];
                z++;

                if(count%5==0)
                {
                    temp = 16*in[0] + 8*in[1] + 4*in[2] + 2*in[3] + in[4];
                    printf("%c",temp==0?' ':'A'-1+temp);
                    z=0;
                }

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

                in[z] = arr[x][s];
                z++;

                if(count%5==0)
                {
                    temp = 16*in[0] + 8*in[1] + 4*in[2] + 2*in[3] + in[4];
                    printf("%c",temp==0?' ':'A'-1+temp);
                    z=0;
                }


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
                in[z] = arr[s][x];
                z++;

                if(count%5==0)
                {
                    temp = 16*in[0] + 8*in[1] + 4*in[2] + 2*in[3] + in[4];
                    printf("%c",temp==0?' ':'A'-1+temp);
                    z=0;
                }

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
                in[z] = arr[x][s];
                z++;

                if(count%5==0)
                {
                    temp = 16*in[0] + 8*in[1] + 4*in[2] + 2*in[3] + in[4];
                    printf("%c",temp==0?' ':'A'-1+temp);
                    z=0;
                }

            }

            if(count==m*n)
            {
                flag=0;
                break;
                //continue;
            }
        }
        printf("\n");
        free(arr);
    }
    return 0;
}



