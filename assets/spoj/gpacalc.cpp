#include<cstdio>

using namespace std;

int hash(char c)
{
	switch(c)
	{
		case 'S': return 10;
		case 'A': return 9;
		case 'B': return 8;
		case 'C': return 7;
		case 'D': return 6;
		case 'E': return 5;
	}
	return -1;
}

int main()
{
	int t;
	int n;
	char arr[10];
	float ans;
	int sum;
	int temp;
	int credits;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		credits=0;
		while(n--)
		{
			scanf("%d",&temp);
			scanf("%s",arr);
			sum+=(temp*hash(arr[0]));
			credits+=temp;
		}
		ans = (float)sum/credits;
		printf("%.2f",ans);
	}
	return 0;
}