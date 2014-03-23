#include<stdio.h>

int s1[8] = {89, 145, 42, 20, 4, 16, 37, 58};
int arr[1000];

int find(int n)
{
	int x;
	for(x=0;x<=7;x++)
	{
		if(s1[x]==n)
		return x;
	}
	return -1;
}

int reduce(int n)
{
	int temp;
	temp=n;
	if(n==1) return -2;
	int f = find(temp);
	int d;
	int t;
	int s;
	while(f==-1)
	{
		s=0;
		t=temp;
		while(t!=0)
		{
			d=t%10;
			t=t/10;
			s+=d*d;
		}
		temp = s;
		f = find(temp);
		if(temp==1) return -2;
	}
	return f;
}

int main()
{
	int x=19;
	printf("%d",reduce(x));
	return 0;
}