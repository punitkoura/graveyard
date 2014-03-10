#include<stdio.h>

int main()
{
    int i = rand();
    int x;
    for(x=0;x<10;x++)
    {
        printf("%d\n",(i%23));
        i = rand();
    }

}
