#include<stdio.h>

int main()
{
    long double p,r,c;
    /*scanf("%llf",&p);
    scanf("%llf",&r);
    scanf("%llf",&c);
    */
    //while(!(p==0.0 && r==0.0 && c==0.0))
    //{

    //}
    p=100.0;
    r=6.0/1200;
    c=12;
    long double ans=1.0;
    int x;
    for(x=1;x<=12;x++) ans*=(1+r);
    ans*=p;
    printf("%llf",ans);
    return 0;
}
