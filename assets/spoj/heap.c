
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
    int * a = (int*)malloc(sizeof(int)*10);
    int size= 10;

    int x;
    for(x=0;x<size;x++)
    {
        scanf("%d",&a[x]);
    }
    build_maxheap(a,size);
    for(x=0;x<size;x++)
    printf("%d ",a[x]);
    return 0;
}
