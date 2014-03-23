#include<stdio.h>

int main()
{
	int test;
	scanf("%d", &test);
	int i, a, b, c, tmp1, tmp2, flag1 = 0, flag2 = 0;
	for(i=0 ; i<test ; i++)
	{
		flag1 = 0;
		flag2 = 0;
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		if(c>a && c>b)
		{
			printf("%d", -1);
			continue;
		}
		if(c == a || c == b)
		{
			printf("%d", 1);
			continue;
		}
		
		if(a<b)
		{
			tmp1 = a;
			a = b;
			b = tmp1;
		}
		if(c%b == 0)
		{
			tmp1 = c/b;
			flag1 = 1;
		}
		if (!((a-c)%b))
		{
			tmp2 = (a-c)/b;
			flag2 = 1;
		}
		if(flag1 && flag2)
			printf("%d", tmp1<tmp2 ? 2*tmp1:2*tmp2);
		else if(flag1)
			printf("%d", 2*tmp1);
		else if(flag2)
			printf("%d", 2*tmp2);
		else
			printf("%d", -1);
	}

	return 0;
}
