#include<stdio.h>
#include<stdlib.h>

void quicksort(float* a,int p, int r)
{
    if(p<r)
    {
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int partition(float* a,int p,int r)
{
    int pivot = rand()%(r-p) + p;

    float t;
    t = a[pivot];
    a[pivot] = a[r];
    a[r] = t;
    float x = a[r];
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
    scanf("%d",&test);
    int n;
    int x;
    char str[41];
    int y;
    int index;
    float max;
    float *input;
    float temp;
    float ans;
    int ans1;
    for(x=0;x<test;x++)
    {
        index = 0;
        max = 0.0;
        scanf("%d",&n);
        input = (float*)malloc(sizeof(float)*n);
        for(y=0;y<n;y++)
        {
            scanf("%s",str);
            scanf("%f",&input[y]);

        }
        quicksort(input,0,n-1);


        for(y=0;y<n-1;y++)
        {
            temp = input[y+1] - input[y];
            if(temp>max)
            {
                max = temp;
                index = y;
            }

        }

        temp = 360.0-input[n-1]+input[0];
        if(temp>max)
        {

            max = temp;

            ans = input[n-1] - input[0];
        }
        else
        {
            ans = 360.00 - input[index+1] + input[index];
        }

        ans *= 12;
        ans1 = (int)ans;
        if(ans-ans1 > 0) ans1++;
        printf("%d\n",ans1);

        free(input);
    }
    return 0;
}
