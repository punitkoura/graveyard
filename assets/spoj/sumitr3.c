#include<stdio.h>
#define s(n) scanf("%d",&n)
int n;
int f(int a[][100],int i,int j)
{
if(i==n-1) return a[i][j];
int c,d;
c=f(a,i+1,j);
d=f(a,i+1,j+1);
return a[i][j]+(c>d?c:d);
}
main()
{
int a[100][100];
int t,x,y,t1,t2,m;
s(t);
while(t--)
{
s(n);
for(x=0;x<=n-1;x++)
for(y=0;y<=x;y++) s(a[x][y]);
m=f(a,0,0);
printf("%d\n",m);
}
}