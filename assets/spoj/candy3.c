#include<stdio.h>

int main()
{
	long long int t,n,m,sum=0,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=0;
		if(n==0)
		{
			printf("NO\n");
			continue;
		}
		for(x=0;x<n;x++)
		{
			scanf("%lld",&m);
			sum+=m;
			if(sum>1000000000) sum%=n;
		}
		
		sum%=n;
		if(sum==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
