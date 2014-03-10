#include<stdio.h>
#include<string.h>
long long hash(char *str)
{
    long long a = 0;
    long long div = 1099511627776;
    int x;
    int l = strlen(str);
    for(x=0;x<l;x++)
    {
        switch(str[x])
        {
            case 'A': a+=((7*a)+1);
            a = a%div;
            break;
            case 'T': a+=((7*a)+2);
            a = a%div;
            break;
            case 'C': a+=((7*a)+3);
            a = a%div;
            break;
            case 'G': a+=((7*a)+4);
            a = a%div;
        }

    }
    a = a%div;
    return a;
}

int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    while(a!=0 || b!=0)
    {

    }
}
