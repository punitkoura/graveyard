#include<stdio.h>

int main()
{
    double pi = 3.1415926535897932384626433832795;
    int l;

    scanf("%d", &l);
    while(l != 0)
    {
        printf("%.2lf\n", l*l/(2*pi));
        scanf("%d", &l);
    }
}
