#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int *arr;
    arr = (int*)malloc(sizeof(int)*t);

    int x;
    for(x=0;x<t;x++)
    {
        scanf("%d",&arr[x]);
    }
    int *ans;
    ans = (int*)malloc(sizeof(int)*t);
    int j;
    ans[0] = arr[0];

    for(j=1;j<t;j++)
    {
        if(ans[j-1]+arr[j] > arr[j])
        {
            ans[j] = ans[j-1]+arr[j];
        }
        else
        {
            ans[j] = arr[j];
        }
    }

    for(x=0;x<t;x++)
    {
        printf("%d ",ans[x]);
    }
    printf("\n");
    return 0;
}
