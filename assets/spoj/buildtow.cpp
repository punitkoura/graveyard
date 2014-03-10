#include <cstdio>

const int mod = 1000000007;

long long int **mat;

long long int **ident;


long long int** mul(long long int ** a,long long int** b)
{
	long long int** temp;
	temp = new long long int*[2];
	temp[0] = new long long int[2];
	temp[1] = new long long int[2];
	
	temp[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	temp[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	temp[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	temp[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
	
	int x,y;
	for(x=0;x<2;x++)
	{
		for(y=0;y<2;y++)
			if(temp[x][y]>mod)
				temp[x][y]=temp[x][y]%mod;
	}
	
	//delete temp;
	return temp;
}

long long int ** makemat(long long int n)
{

	if(n==0)
	{
		return ident;
	}
	if(n==1)
	{
		return mat;
	}
	
	long long int **ret = makemat(n/2);
	
	if(n%2==1)
	{
		return mul(mul(ret,ret),mat);
	}
	else
	{
		return mul(ret,ret);
	}
}

int main()
{
	int t;
	long long int n;
	int x,y;
	
	ident = new long long int*[2];
	ident[0] = new long long int[2];
	ident[1] = new long long int[2];
	
	mat = new long long int*[2];
	mat[0] = new long long int[2];
	mat[1] = new long long int[2];
	
	scanf("%d",&t);
	ident[0][0] = 1;
	ident[0][1] = 0;
	ident[1][0] = 0;
	ident[1][1] = 1;
	
	mat[0][0] = 0;
	mat[0][1]=mat[1][0]=mat[1][1] = 1;
	
	long long int** ans;
	
	long long int fib;

	while(t--)
	{
		scanf("%lld",&n);
		
		if(n==0)
		{
			fib = 0;
		}
		else if(n==1)
		{
			fib = 1;
		}
		else if(n==2)
		{
			fib = 2*2+1*1;
		}
		else
		{
			ans = makemat(n-1);
		
		//fib = ans[0][0]*1 + ans[0][1]*2;
			fib = ans[1][0]*1 + ans[1][1]*2;
			if(fib>mod)fib=fib%mod;
		}
	}
	
	return 0;
}
