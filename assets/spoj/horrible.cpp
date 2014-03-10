#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

long long int arr[100010];
long long int seg[262155];
long long int lazy[262155];



void update(int node,int a,int b,int i,int j,long long int val)
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


long long int query(int node,int a,int b,int i,int j)
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
		
	long long int q1 = query(2*node,a,(a+b)/2,i,j);
	long long int q2 = query(2*node+1,((a+b)/2)+1,b,i,j);
	
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


long long int fil()
{
	long long int num=0;char c=0;
	while(c<=32)c=getchar_unlocked();
	while(c>32)
	{
		num=num*10+c-'0';
		c=getchar_unlocked();
	}
	return num;
}

int main() {
	int n,c;
	
	int w,p,q;
	long long int v;
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		//arr = new long long int[n+1];
		int size = 2*(int)(pow(2,ceil(log2(n)))) + 1;
		
		//seg = new long long int[size];
		//lazy = new long long int[size];
		
		memset(arr,0,sizeof(arr));
		memset(seg,0,sizeof(seg));
		memset(lazy,0,sizeof(lazy));
		
		while(c--)
		{
			w=fi();
			p=fi();
			q=fi();
			if(w==0)
			{
				v=fil();
				update(1,1,n,p,q,v);
			}
			else
			{
				printf("%lld\n",query(1,1,n,p,q));
			}
		}
	}
	return 0;
}