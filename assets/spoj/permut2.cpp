#include<cstdio>

using namespace std;


int fi()
{
	char c=0;
	int n=0;
	while(c<=32)
	{
		c=getchar_unlocked();
	}
	while(c>32)
	{
		n=n*10+c-'0';
		c=getchar_unlocked();
	}
	return n;
}

int main()
{
	int n;
	
	int arr[100010];
	int brr[100010];
	int x;
	scanf("%d",&n);
	int flag;
	while(n!=0)
	{
		flag=0;
		for(x=1;x<=n;x++)
		{	
			arr[x] = fi();
			brr[arr[x]] = x;
		}
		
		for(x=1;x<=n;x++)
		{
			if(arr[x]!=brr[x])
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			printf("not ambiguous\n");
		}
		else
		{
			printf("ambiguous\n");
		}
		n=fi();
	}
	return 0;
}
