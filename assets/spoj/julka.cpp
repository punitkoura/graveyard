#include<cstdio>
#include<cstring>
using namespace std;

int la,lb;

void add(int *a,int *b,int *k)
{
	int z,x,c;
	z=la-1;
	x=lb-1;
	c=(z>x)?z:x;
	c++;
	k[c+1] = -1;
	int carry=0;
	
	while(z>=0 && x>=0)
	{
		k[c] = a[z]+b[x]+carry;
		carry = k[c]/10;
		k[c]%=10;
		c--;
		z--;
		x--;
	}
	
	int sc=c;
	while(sc>=0)
	{
		k[sc] = 0;
		sc--;
	}
	
	k[c]+=carry;
	
	if(z<0)
	{
		while(x>=0)
		{
			k[c]+=b[x];
			x--;
			c--;
		}
	}
	else if(x<0)
	{
		while(z>=0)
		{
			k[c]+=a[z];
			z--;
			c--;
		}
	}
}


void sub(int* a,int *b, int *n)
{
	int z,x,c;
	z=la-1;
	x=lb-1;
	c=(z>x)?z:x;
	n[c+1] = -1;
	
	int temp;
	int sz;
	while(z>=0&&x>=0)
	{
		if(a[z]<b[x])
		{
			if(a[z-1]>=1)
			{
				temp = 10*a[z-1] + a[z];
				a[z-1]--;
				n[c] = temp - b[x];
			}
			else
			{
				temp = 10+a[z];
				n[c] = temp - b[x];
				sz=z;
				while(a[z-1]==0)
				{
					a[z-1]=9;
					z--;
				}
				a[z-1]--;
				z=sz;
			}
		}
		else
		{
			n[c] = a[z]-b[z];
		}
		z--;
		x--;
		c--;
	}
	
	if(z<0)
	{
		while(x>=0)
		{
			n[c]=b[x];
			x--;
			c--;
		}
	}
	else if(x<0)
	{
		while(z>=0)
		{
			n[c]=a[z];
			z--;
			c--;
		}
	}
	
}

void print(int* arr)
{
	int x=0;
	while(arr[x]!=-1)
	{
		printf("%d",arr[x]);
		x++;
	}
	printf("\n");
}

int main()
{
	int k[105];
	int n[105];
	int a[105];
	int b[105];
	
	int t=10;
	
	char c;
	int z,x;
	while(t--)
	{
		c=0;z=0;
		while(c<=32)c=getchar();
		while(c>32)
		{
			a[z] = c-'0';
			z++;
			c=getchar();
		}
		a[z] = -1;
		la = z;
		
		c=0;x=0;
		while(c<=32)c=getchar();
		while(c>32)
		{
			b[x] = c-'0';
			x++;
			c=getchar();
		}
		b[x] = -1;
		lb = x;
		
		add(a,b,k);
		sub(a,b,n);
		//print(a);
		//print(b);
		print(k);
		print(n);
	}
	
	return 0;
}