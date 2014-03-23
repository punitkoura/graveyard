#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int arr[10010];
int seg[32779];
int lazy[32779];



void update(int node,int a,int b,int i,int j,int val)
{
	int mid = (a+b)/2;
	if(lazy[node]!=0)
	{
		seg[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node] += ((mid-a+1)*lazy[node])/(b-a+1);
			lazy[2*node+1]+=((b-mid)*lazy[node])/(b-a+1);
		}
		lazy[node] = 0;
	}
	
	if(b<i || a>j || a>b) return;
	
	if(a>=i && b<=j)
	{
		seg[node]+= (b-a+1)*val;
		if(a!=b)
		{
			lazy[2*node]+= (mid-a+1)*val;
			lazy[2*node+1]+= (b-mid)*val;
		}
		return;
	}
	
	update(2*node,a,(a+b)/2,i,j,val);
	update(2*node+1,((a+b)/2) + 1,b,i,j,val);
	
	seg[node] = seg[node*2] + seg[node*2 + 1];
}


int query(int node,int a,int b,int i,int j)
{
	if(a>j || b<i || a>b) return 0;
	int mid = (a+b)/2;
	if(lazy[node]!=0)
	{
		seg[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node] += ((mid-a+1)*lazy[node])/(b-a+1);
			lazy[2*node+1]+=((b-mid)*lazy[node])/(b-a+1);
		}
		lazy[node] = 0;
	}
	
	if(a>=i && b<=j)
		return seg[node];
		
	int q1 = query(2*node,a,(a+b)/2,i,j);
	int q2 = query(2*node+1,((a+b)/2)+1,b,i,j);
	
	return q1+q2;
	
}


int fi()
{
	int num=0;char c=0;
	while(c<=32)c=getchar_unlocked();
	while(c>32)
	{
		num=num*10+c-'0';
		c=getchar_unlocked();
	}
	return num;
}




int main() {
	int n,u;
	
	int p,q;
	int v;
	
	int t;
	int count;
	int index;
	scanf("%d",&t);
	while(t--)
	{
		n=fi();
		u=fi();

		int size = 2*(int)(pow(2,ceil(log2(n)))) + 1;
		
		memset(arr,0,sizeof(arr));
		memset(seg,0,sizeof(seg));
		memset(lazy,0,sizeof(lazy));
		
		while(u--)
		{
			p=fi();
			q=fi();
			v=fi();
			update(1,1,n,p+1,q+1,v);
		}
		count = fi();
		
		while(count--)
		{
			index = fi();
			printf("%d\n",query(1,1,n,index+1,index+1));
		}
	}
	return 0;
}