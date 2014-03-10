#include <cstdio>
#include<string>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	char s[500];
	
	int t;
	scanf("%d",&t);
	int x;
	char c;
	int l;
	
	stack<char> st;
	
	while(t--)
	{
		x=1;
		c=0;
		while(c<=32)c=getchar();
		while(c>32)
		{
			s[x] = c;
			x++;
			c=getchar();
		}
		s[x] = '\0';
		l=x;
		
		for(x=1;x<l;x++)
		{
			if(s[x]>='a'&&s[x]<='z')
			{
				printf("%c",s[x]);
			}
			else if(s[x]=='+' || s[x] == '-' || s[x] == '*' || s[x]== '/' || s[x]=='^')
			{
				st.push(s[x]);
			}
			else if(s[x]==')')
			{
				printf("%c",st.top());
				st.pop();
			}
		}
		printf("\n");
		
	}
	
	return 0;
}