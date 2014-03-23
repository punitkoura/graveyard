#include<stdio.h>
#include<stdlib.h>

int main()
{
    int test;
    scanf("%d", &test);

    int i, j, ind, p;
    float cx, cy;
    int *x, *y;

    for(i=0 ; i<test ; i++)
    {
        int points;
        scanf("%d", &points);

        x = (int*)malloc(points * sizeof(int));
        y = (int*)malloc(points * sizeof(int));
        ind = 0;

        for(j=0 ; j<points; j++)
        {
                scanf("%d", &x[ind]);
                scanf("%d", &y[ind]);
                ind++;
        }

        cx = 0;
        cy = 0;

        for(p = 0 ; p<points ; p++)
        {
            cx += x[p];
            cy += y[p];
        }

        cx = (float)cx / points;
        cy = (float)cy / points;

        printf("%.2f %.2f\n", cx, cy);

        free(x);
        free(y);
    }

    return 0;
}
