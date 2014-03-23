#include<stdio.h>
int main()
{
long long int t,a,b,x;
scanf("%lld",&t);
char c;
char c1,c2;
int digit;
long long temp;
long long temp1;
while(t--)
{
c =0;
while(c<=32)
c = getchar();
while(c>32)
{
c1 = c;
c = getchar();
}
a = c1-'0';
c =0;
c1 = c2 = '0';
while(c<=32)
c = getchar();
while(c>32)
{
c2 = c1;
c1 = c;
c = getchar();
}
if(c2<'0')c2 = '0';
b = 10*(c2-'0') + (c1-'0');
digit = a;
if(b==0)
{
    if(a==0) printf("0\n");
    else
    printf("1\n");
}
else
{
temp = b%4;
temp1 = 1;
if(temp==0)
{
temp1 = digit*digit*digit*digit;
}
else
for(x=1;x<=temp;x++)
{
temp1*=digit;
}
temp1 = temp1%10;
printf("%d\n",temp1);
}
}
return 0;
}
