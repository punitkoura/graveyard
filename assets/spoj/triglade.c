#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    int t;
    int ia,ib,ic;
    scanf("%d",&t);
    double ans;
    int x;

    while(t--)
    {
        scanf("%d",&ia);
        scanf("%d",&ib);
        scanf("%d",&ic);
        a = (double)ia;
        b = (double)ib;
        c = (double)ic;
        ans = c/a;

        for(x=0;x<=100;x++)
        {
            ans = ans - (a*ans + b*sin(ans) -c)/(a + b*cos(ans));
        }
        printf("%.6lf\n",ans);
    }



    return 0;
}
