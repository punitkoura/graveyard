#include<stdio.h>

int main()
{
	long long int a,b,n;
	char c,c1;
	scanf("%lld",&n);
	
	
	long long int ans;
	while(n--)
	{
	ans = 0;
	//scanf("%lld %c",&a,&c);
	scanf("%lld",&a);
	scanf("%c",&c);
	ans+=a;
	printf("%lld %c ",a,c);
	while(c!='=')
	{
		//scanf(" %lld %c",&b,&c1);
		scanf("%lld",&b);
		scanf("%c",&c1);
		switch(c)
		{
			case '+':ans +=b;
			break;
			case '-':ans-=b;
			break;
			case '*':ans*=b;
			break;
			case '/':ans/=b;
			break;
		}
		c = c1;
		printf("lol %lld %c",b,c1);
	}
	printf("%lld\n",ans);
	}
	return 0;
}
