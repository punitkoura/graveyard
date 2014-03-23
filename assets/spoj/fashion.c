#include<stdio.h>
#include<stdlib.h>

void quicksort(int* a,int p, int r)
{
    if(p<r)
    {
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int partition(int* a,int p,int r)
{
    int pivot = rand()%(r-p) + p;

    int t;
    t = a[pivot];
    a[pivot] = a[r];
    a[r] = t;
    int x = a[r];
    int i = p-1;
    int j;
    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i = i+1;
            t = a[i];
            a[i]=a[j];
            a[j] = t;
        }
    }
    t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
    return i+1;
}


int main()
{
    int t;
    int n;
    int *men;
    int *women;

    scanf("%d",&t);
    int x;
    int y;
    for(x=0;x<t;x++)
    {
        scanf("%d",&n);
        men = (int*)malloc(sizeof(int)*n);
        women = (int*)malloc(sizeof(int)*n);
        for(y=0;y<n;y++)
        {
            scanf("%d",&men[y]);
        }
        for(y=0;y<n;y++)
        {
            scanf("%d",&women[y]);
        }
        quicksort(men,0,n-1);
        quicksort(women,0,n-1);
        int sum = 0;

        for(y=0;y<n;y++)
        {
            sum+=men[y]*women[y];
        }
        printf("%d\n",sum);
        free(men);
        free(women);
    }
    return 0;
}
