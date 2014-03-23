#include<stdio.h>


char normal(char b)
{
    if(b>='a') return b;
    else return b+'a'-'A';
}

int main()
{
    char c;
    char f;
    char flag = 'Y';

    while(1)
    {
        char a[21];
        flag = 'Y';
        scanf("%s",a);
        if(a[0]=='*')break;

        f = a[0];
        f = normal(f);
        scanf("%c",&c);
        while(c!='\n')
        {
            char s[21];
            scanf("%s",s);
            if(normal(s[0])!=f)
            {
                flag = 'N';
            }
            scanf("%c",&c);
        }
        printf("%c\n\n",flag);
    }
    return 0;
}
