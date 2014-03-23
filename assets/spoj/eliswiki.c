#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    long int x;
    long int y;
}data;

int main()
{
    data *arr;
    int n;
    scanf("%d",&n);
    arr = (data*)malloc(sizeof(data)*n);
    data *aux1;
    aux1 = (data*)malloc(sizeof(data)*n);
    data* aux2;
    aux2 = (data*)malloc(sizeof(data)*n);

    int i;
    int len = 0;
    int l,r,m;

    for(i=0;i<n;i++)
    {
        l=-1;r = len-1;

            while(r-l>1)
            {
                m = (l+r)/2;
                if(aux[m].x>=arr[i].x && aux[m].y>=arr[i].y)
                    r=m;
                else
                    l = m;
            }
    }

    return 0;
}

