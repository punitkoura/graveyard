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
    int test;
    int p;
    scanf("%d",&test);
    int x;
    int* enter;
    int *exit;
    int y;
    int i1,i2;
    int max;
    int temp;
    for(x=1;x<=test;x++)
    {
        scanf("%d",&p);
        i1=0;
        i2=0;
        max = 0;
        temp = 0;
        enter = (int*)malloc(sizeof(int)*p);
        exit = (int*)malloc(sizeof(int)*p);
        for(y=0;y<p;y++)
        {
            scanf("%d",&enter[y]);
            scanf("%d",&exit[y]);
        }
        quicksort(enter,0,p-1);
        quicksort(exit,0,p-1);
        for(y=enter[0];y<=exit[p-1];y++)
        {
            if(enter[i1]==y)
            {
                i1++;
                temp++;
            }
            else if(exit[i2]==y)
            {
                i2++;
                temp--;
            }

            if(temp>max)max = temp;
        }
        free(enter);
        free(exit);
        printf("%d\n",max);
    }
    return 0;
}
