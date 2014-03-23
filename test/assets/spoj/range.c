#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);

    float angle;
    int r,u;

    int x;
    for(x=1;x<=n;x++)
    {
        scanf("%d",&r);
        scanf("%d",&u);
        angle=(r*9.806)/(u*u);
        if(angle<=1.0)
        {
            angle = asin(angle);
            angle = angle/2;
            angle = angle*(180.0/(2*acos(0.0)));
            printf("%f\n",angle);
        }
        else printf("-1\n");
    }
    return 0;
}
