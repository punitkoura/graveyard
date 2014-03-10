#include<stdio.h>

int main()
{
    int count,max;
    char c;
    int n;

    scanf("%d",&n);
    int x;
    c = getchar();
    int y,temp;
    for(x=1;x<=n;x++)
    {
        max = count = 0;
        c = getchar();
        if(c<=32)
        {
            printf("%d %d\n",x,1);
            continue;
        }
        while(c>32)
        {
            if(c=='[')
            {
                count ++;
                if(count>max)max = count;
            }
            if(c==']') count--;
            c = getchar();
        }
        temp = 1;
        for(y=1;y<=max;y++)
        {
            temp*=2;
        }
        printf("%d %d\n",x,temp);
    }
    return 0;
}
