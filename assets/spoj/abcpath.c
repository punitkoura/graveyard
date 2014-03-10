#include <stdio.h>
#include <queue>
using namespace std;

char arr[50][50];
int h,w;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

bool check(int x,int y)
{
	if(x>=0 && x<h)return true;
	if(y>=0 && y<w)return true;
	return false;
}

int dfs(int x,int y,char c)
{

}


int main(void) {

	char c;
	int x,y;

	scanf("%d",&h);
	scanf("%d",&w);
	queue<int> as;

	int max;
	int temp;

	while(!(h==0 && w==0))
	{
		max=0;
		for(x=0;x<h;x++)
		{
			for(y=0;y<w;y++)
			{
				scanf("%c",arr[x][y]);
				if(arr[x][y]=='A')
				{
					as.push(x);
					as.push(y);
				}
			}
		}
		while(!as.empty())
		{
			x=q.top();
			a.pop();
			y=q.top();
			q.pop();
			temp = dfs(x,y,'A');
			if(temp>max)max=temp;
		}

		printf("%d\n",max);
	}

	return 0;
}
