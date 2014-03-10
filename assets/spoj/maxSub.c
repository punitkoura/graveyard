#include<stdio.h>

void max_heapify(int* a,int i,int size)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest;
    if(l<size && a[l]>a[i])
    {
        largest = l;
    }
    else largest = i;

    if(r<size && a[r]>a[largest])
        largest = r;

    if(largest != i)
    {
        int t=a[largest]
        ; a[largest]=a[i];
        a[i] = t;
        max_heapify(a,largest,size);
    }

    return;
}


void build_maxheap(int* a,int size)
{
    int i = size/2;
    while(i>=0)
    {
        max_heapify(a,i,size);
        i--;
    }
}

int main()
{
    int *arr;
    int n;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    int k;

    int x;
    int *temp;
    int max;
    int i;

    for(x=0;x<n;x++)
    {
        scanf("%d",&arr[x]);

    }
    scanf("%d",&k);
    temp = (int*)malloc(sizeof(int)*k);
    for(x=0;x<k;x++)
    {
        temp[x] = arr[x];
    }
        build_maxheap(temp,k);

        max = temp[0];
        printf("%d ",max);
    for(x=k;x<n;x++)
    {
        if(arr[x-k] == arr[x])
        {
            printf("%d ",max);
        }
        else if(arr[x-k]>arr[x])
        {
            if(arr[x-k]!=max)
            {
                printf("%d ",max);
            }
            else
            {
                for(i=x-k+1;i<=x;i++)
                {
                    temp[i-x+k-1] = arr[i];
                }
                build_maxheap(temp,k);
                max = temp[0];
                printf("%d ",max);
            }
        }
        else
        {
            for(i=x-k+1;i<=x;i++)
            {
                temp[i-x+k-1] = arr[i];
            }
            build_maxheap(temp,k);
            max = temp[0];
            printf("%d ",max);
        }
    }
    printf("\n");
    return 0;
}
