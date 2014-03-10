#include<stdio.h>
#include<stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);

    int x;
    int n;
    char* arr;
    int y;
    int res[8];
    char a,b,c;

    for(x=1;x<=test;x++)
    {
        for(y=0;y<8;y++) res[y] = 0;

        scanf("%d",&n);
        arr = (char*)malloc(sizeof(char)*41);
        scanf("%s",arr);

        for(y=0;y<38;y++)
        {
            a = arr[y];
            b=arr[y+1];
            c = arr[y+2];
            if(a=='H')
            {
                if(b=='H')
                {
                    if(c=='H') res[7]++;
                    else res[6]++;
                }
                else
                {
                    if(c=='H') res[5]++;
                    else res[4]++;

                }
            }
            else
            {
                if(b=='H')
                {
                    if(c=='H') res[3]++;
                    else res[2]++;
                }
                else
                {
                    if(c=='H') res[1]++;
                    else res[0]++;

                }
            }
        }
        printf("%d",n);
        for(y=0;y<8;y++) printf(" %d",res[y]);
        printf("\n");
        free(arr);
    }
    return 0;
}
