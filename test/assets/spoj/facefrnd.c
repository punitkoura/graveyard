#include<stdio.h>



int main()
{
    int arr[10000];
    int n;
    scanf("%d",&n);
    int x;
    int count = 0;
    int c;
    int y;
    int temp;

    for(x=0;x<10000;x++)
    {
        arr[x]=0;
    }
    int input[10000];
    int index = 0;
    int numelem = 0;
    for(x=0;x<n;x++)
    {
        scanf("%d",&temp);
        arr[temp] = 2;
        scanf("%d",&c);
        numelem+=c;

        for(y=0;y<c;y++)
        {
            scanf("%d",&input[index]);
            index++;
        }
    }

    for(x = 0;x<numelem;x++)
    {

        if(arr[input[x]]==0)
        {
            count++;
            arr[input[x]]=1;
        }

    }
    printf("%d\n",count);
    return 0;
}
