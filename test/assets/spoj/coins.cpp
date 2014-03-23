#include <cstdio>
using namespace std;

const int size = 100000;

long long int *arr;

long long int recurse(long long int x)
{
	if(x<=size) return arr[x];
	long long int a,b,c;
	a = x/2;
	b = x/3;
	c = x/4;
	long long int temp = recurse(a)+recurse(b)+recurse(c);
	
	return temp>x?temp:x;
}

int main() {
	
	arr = new long long  int[size+1];
	int x;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	
	long long int temp;
	
	for(x=5;x<=size;x++)
	{
		temp = arr[x/2] + arr[x/3]+arr[x/4];
		arr[x] = temp>x?temp:x;
	}
	
	long long int inp;
	
	while(scanf("%lld",&inp)!=EOF)
	{	
		printf("%lld\n",recurse(inp));
	}
	
	return 0;
}