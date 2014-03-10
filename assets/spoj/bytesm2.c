#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int h,w;
    int **arr;
    int temp;
    int max;
    int x,y;

    while(t--)
    {
        scanf("%d",&h);
        scanf("%d",&w);
        arr = (int**)malloc(sizeof(int*)*(h+2));
        for(x=0;x<=h+1;x++)
        {
            arr[x] = (int*)malloc(sizeof(int)*(w+2));
        }
        for(x=0;x<=h+1;x++)
        {
            for(y=0;y<=w+1;y++)
            {
                arr[x][y] = 0;
            }
        }


        for(x=1;x<=w;x++)
        {
            scanf("%d",&arr[1][x]);
        }

        for(x=2;x<=h;x++)
        {
            for(y=1;y<=w;y++)
            {
                scanf("%d",&temp);
                max = arr[x-1][y-1];
                max = max>arr[x-1][y]?max:arr[x-1][y];
                max = max>arr[x-1][y+1]?max:arr[x-1][y+1];
                arr[x][y] = max+temp;;
            }
        }
        max = 0;


        for(x=1;x<=w;x++)
        {
            if(max<arr[h][x])max = arr[h][x];
        }
        printf("%d\n",max);
        free(arr);
    }
    return 0;
}
