#include<stdio.h>

int main()
{
    char c;
    char c1,c2;
        c = getchar();
    while(c<32)
    c = getchar();

    while(c>=32)
    {
        c2 = c1;
        c1 = c;
        c = getchar();
    }
    printf("%d %c %c",t,c1,c2);
    return 0;
}
