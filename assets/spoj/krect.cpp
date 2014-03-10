#include<cstdio>
#include<vector>

using namespace std;

char arr[110][110];
int m,n,k;

int ans;

void recurse(int x,int y,int x1,int y1,int count,vector<int> alpha)
{
	int i,j;

    if(k==count)
    {
        ans++;
    }

	if(x1!=m-1)
	{
	for(j=y;j<=y1;i++)
	{
		if(alpha[arr[x1+1][j] - 'A']==0)
		{
			count++;
			alpha[arr[x1+1][j] - 'A']=1;
		}
	}
	//if(count<=k) recurse(x,y,x1+1,y1,count,alpha);
	}
    printf("count %d\n",count);
	if(y1!=n-1)
	{
	for(i=x;i<=x1;i++)
	{
		if(alpha[arr[i][y1+1]-'A']==0)
		{
			count++;
			alpha[arr[i][y1+1]-'A']=1;
		}
	}

	//if(count<=k) recurse(x,y,x1,y1+1,count,alpha);
	}
}


int main()
{
    scanf("%d %d %d",&m,&n,&k);
	ans=0;
    int y;
    int x;int z;
    for(x=0;x<n;x++)
    {
        scanf("%s",arr[x]);
    }

    for(x=0;x<m;x++)
    {
        for(y=0;y<n;y++)
        {
            vector<int> v(26);
            for(z=0;z<26;z++)
            {
                v[z]=0;
            }
            v[arr[x][y]-'A']=1;

            recurse(x,y,x,y,1,v);
            for(z=0;z<26;z++)
            {
                printf("%d ",v[z]);
            }
            printf("\n");
        }
    }
    printf("%d\n",ans);
    return 0;
}
