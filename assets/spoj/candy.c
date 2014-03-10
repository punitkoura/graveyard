#include<stdio.h>

int main()
{
	int n;
	int *arr;
	scanf("%d",&n);
	int x;
	int sum=0;
	int sum1=0;
	while(n!=-1)
	{
		sum=0;
		sum1=0;
		arr = (int*)malloc(sizeof(int)*n);
		for(x=0;x<n;x++)
		{
			scanf("%d",&arr[x]);
			sum+=arr[x];
		}
		if(sum%n!=0)
		{
			printf("-1\n");
			scanf("%d",&n);
			continue;
		}
		sum=sum/n;
		for(x=0;x<n;x++)
		{
			sum1+=(sum-arr[x]>0)?sum-arr[x]:arr[x]-sum;
		}
		printf("%d\n",sum1/2);
		scanf("%d",&n);
	}
	return 0;
}
