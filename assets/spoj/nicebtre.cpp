#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
char arr[10010];

int main()
{
  int t;
  scanf("%d",&t);
  int l;
  stack<int> s;
  int x;
  int max;
  while(t--)
    {
      scanf("%s",arr);
      max=0;
      l = strlen(arr);
      if(arr[0]=='l')
	{
	  printf("0\n");
	  continue;
	}
      else s.push(0);
      for(x=1;x<l;x++)
	{
	  if(arr[x]=='l')
	    {
	      s.top()++;
	      
	      //if(s.top()==2)s.pop();
	      while(!s.empty()&&s.top()==2)s.pop();
	    }
	  else
	    {
	      s.top()++;
	      s.push(0);
	    }
	  if(max<s.size())max=s.size();
	  
	}
      printf("%d\n",max);
    }
}
