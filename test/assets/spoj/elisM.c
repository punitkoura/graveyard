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
    data *aux;
    aux = (data*)malloc(sizeof(data)*n);

    int i;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&(arr[i].x));
        scanf("%ld",&(arr[i].y));
    }
    int len = 1;
    aux[0] = arr[0];

    int l,m,r;
    int j;
    for(i=1;i<n;i++)
    {
        if(arr[i].x>aux[len-1].x && arr[i].y>aux[len-1].y)
        {
            aux[len++] = arr[i];
        }
        else if(arr[i].x<aux[0].x && arr[i].y<aux[0].y)
        {
            aux[0] = arr[i];
        }
        else
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
            aux[r] = arr[i];

        }
        for(j=0;j<len;j++)
        printf("%d %d\t",aux[j].x,aux[j].y);;

        printf("\n");
    }
    printf("%d\n",len);
    return 0;
}
