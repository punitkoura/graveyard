#include<stdio.h>
int main()
{
    int h1,m1,h2,m2;
    scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
    while(!(h1==0 &&m1==0&&h2==0&&m2==0))
    {
        printf("%d\n",(m2>=m1?((h2-h1)*4 + (m2-m1)/15) + (m1%15==0 && m2%15!=0):((h2-h1)*4 -1 + (m1-m2)/15)));
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
    }
    return 0;
}
