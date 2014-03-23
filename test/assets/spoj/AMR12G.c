#include<stdio.h>

int sum(int* arr,int n)
{
	int s=0;
	int x;
	for(x=0;x<n;x++)
	{
		s+=arr[x];
	}
	return s;
}
	

int main()
{
	int t;
	int n,m;
	int k;
	scanf("%d",&t);
	int x,y;
	char c;
	char arr[51][51];
	int brr[51];
	int count;
	int gcount;
	
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		gcount=0;
		for(x=0;x<n;x++)
		{
			count=0;
			c=0;
			while(c<=32)c=getchar();
			for(y=0;y<n;y++)
			{
				
				arr[x][y]=c;
				if(c=='*')
				{
					count++;
				}
				c=getchar();
			}
			brr[x] = count;
		}
		for(x=0;x<n;x++)
		{
			if(brr[x]<n/2)
			{
				brr[x] = n-brr[x];
				k--;
			}
			if(k==0)break;
		}
		
		if(k==0)
		{
			printf("%d\n",sum(brr,n));
			continue;
		}
		
		for(x=0;x<n;x++)
		{
			if(brr[x]==n/2)
			{
				brr[x] = n-brr[x];
				k--;
			}
			if(k==0)break;
		}
		
		if(k==0)
		{
			printf("%d\n",sum(brr,n));
			continue;
		}
			
		printf("\n");
	}
}
	