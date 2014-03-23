#include<stdio.h>

int main()
{
    int m,n;
    int t;
    char c;
    scanf("%d",&t);
    int i;
    int x;
    int y;
    int flag;
    int hi,lo,s;
    int count;
    int t1,t2;
    char  **arr;
    char in[6];
    in[5] = '\0';
    int z;
    int temp;
    for(i=1;i<=t;i++)
    {
        printf("\nt = %d",t);
        scanf("%d",&m);
        scanf("%d",&n);
        c = 0;
        arr = (char**)malloc(sizeof(char*)*m);

        for(x=0;x<m;x++)
        {
            arr[x] = (char*)malloc(sizeof(char)*n);
        }
        while(c<33)c = getchar();

        for(x=0;x<m;x++)
        {
            for(y=0;y<n;y++)
            {
                arr[x][y]=c;
                c = getchar();
            }
        }
        flag=1;
        hi=0;
        t1=0;t2=1;
        s=0;
        count = 0;
        z = 0;
        temp = 0;
        while(1)
        {
            s=hi;
            hi = n-t2;
            lo = t1;

            for(x=lo;x<=hi;x++)
            {
                printf("%c\t",arr[s][x]);
                in[z] = arr[s][x];
                z++;
                count++;

                if(count%5==0)
                {
                    z=0;

                    temp = in[4]-'0'+2*(in[3]-'0')+4*(in[2]-'0')+8*(in[1]-'0')+16*(in[0]-'0');
                    if(temp==0)printf(" ");
                    else printf("%c",(char)('A'-1+temp));
                    printf("\n%s\n",in);

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
                printf("%c\t",arr[x][s]);
                in[z] = arr[s][x];
                z++;
                count++;

                if(count%5==0)
                {
                    z=0;
                    temp = in[4]-'0'+2*(in[3]-'0')+4*(in[2]-'0')+8*(in[1]-'0')+16*(in[0]-'0');
                    if(temp==0)printf(" ");
                    else printf("%c",'A'-1+temp);
                    printf("\n%s\n",in);
                }

                in[z] = arr[s][x];
                z++;
                printf("lolo");
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
                printf("%c\t",arr[s][x]);
                in[z] = arr[s][x];
                z++;
                count++;

                if(count%5==0)
                {
                    z=0;
                    temp = in[4]-'0'+2*(in[3]-'0')+4*(in[2]-'0')+8*(in[1]-'0')+16*(in[0]-'0');
                    if(temp==0)printf(" ");
                    else printf("%c",'A'-1+temp);
                    printf("\n%s\n",in);
                }
                in[z] = arr[s][x];
                z++;
                printf("lolo");
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
                printf("%c\t",arr[x][s]);
                in[z] = arr[s][x];
                z++;
                count++;

                if(count%5==0)
                {
                    z=0;
                    temp = in[4]-'0'+2*(in[3]-'0')+4*(in[2]-'0')+8*(in[1]-'0')+16*(in[0]-'0');
                    if(temp==0)printf(" ");
                    else printf("%c",'A'-1+temp);
                    printf("\n%s\n",in);
                }
                in[z] = arr[s][x];
                z++;
                printf("lolo");
            }

            if(count==m*n)
            {
                flag=0;
                break;
                //continue;
            }
            printf("count = %d\n",count);
        }
    }

    return 0;
}

