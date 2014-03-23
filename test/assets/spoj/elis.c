#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    int *arr = (int*)malloc(sizeof(int)*t);
    int x;
    int *aux = (int*)malloc(sizeof(int)*t);

    for(x=0;x<t;x++)
    {
        scanf("%d",&arr[x]);
        aux[x] = 1;
    }

    int y;
    int z;
    int max,index=-1;
    max = 0;
    int maxl = 1;
    for(x=1;x<t;x++)
    {
        max = 0;
        index = -1;
        for(y=x-1;y>=0;y--)
        {
            if(arr[x]>arr[y])
            {
                if(aux[y]>max)
                {
                    max = aux[y];
                    index = y;
                }
            }
            if(index==-1) continue;
            else aux[x] = aux[index] + 1;
            if(maxl<aux[x])maxl = aux[x];
        }


    }
    printf("%d\n",maxl);
    return 0;
}
