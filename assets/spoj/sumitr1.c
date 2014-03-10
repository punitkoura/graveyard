#include<stdio.h>
#define s(n) scanf("%d",&n)
#define i(x,n) if(x==n)
#define l(x,a,b) for(x=a;x<=b;x++)
main()
{
int a[100][100];
int t,n,x,y,t1,t2,m;
s(t);
while(t--)
{
s(n);
s(a[0][0]);
if(n==1)
{
printf("%d\n",a[0][0]);
continue;
}
m=0;
l(x,1,n-1)
{
l(y,0,x)
{
s(a[x][y]);
i(y,0)a[x][y]+=a[x-1][y];
else i(y,x)a[x][y]+=a[x-1][y-1];
else
{
t1=a[x-1][y-1];
t2=a[x-1][y];
t1=(t1>t2)?t1:t2;
a[x][y]+= t1;
}
i(x,n-1)
if(m<a[x][y])m=a[x][y];
}
}
printf("%d\n",m);
}
}