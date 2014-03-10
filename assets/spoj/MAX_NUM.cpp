#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

class data
{
	public:
	char c;
	int i;
	
	bool operator<(const data& a, const data& b) const
	{
		return a.c>b.c;
	}
};
	

int main()
{
	int t;
	char str[100010];
	int k;
	scanf("%d",&t);
	int x;
	int l;
	char c;
	while(t--)
	{
		
		x=0;
		c=0;
		while(c<=32)c=getchar_unlocked();
		while(c>32)
		{
			str[x] = c;
			c=getchar_unlocked();
			x++;
		}
		str[x] = '\0';
		l=x;
		scanf("%d",&k);
		
		vector<data> v;
		
		for(x=1;x<l;x++)
		{
			
		
	return 0;
}