#include <cstdio>
using namespace std;


int fi()
{
  int n=0;char c=0;
  while(c<=32)c=getchar();
  while(c>32)
    {
      n=(n<<1)+(n<<3)+c-'0';
      c=getchar();
    }
  return n;
}

int main()
{
  int n;
  scanf("%d",&n);
  int arr[300010];

  int x;
  int ind;
  
  for(x=0;x<n;x++)
    {
      arr[x] = fi();
      if(arr[x]==n)ind = x;
    }
  int count=0;
	
	int last = n;
	ind--;
	
  while(ind>=0)
    {
      if(arr[ind]==last-1)
      {
      	last = arr[ind];
      	count++;
      }
      ind--;
    }
  printf("%d\n",n-1-count);
  return 0;
}
