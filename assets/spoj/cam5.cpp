#include <cstdio>

using namespace std;

class tree
{
public:
  int v;
  int rank;
  tree* parent;
};

int fi()
{
  int n=0;char c=0;
  while(c<=32)c=gethcar_unlocked();
  while(c>32)
    {
      n=(n<<1)+(n<<3)+c-'0';
    }
  return n;
}


void makeset(tree **set,int n)
{
  int x;
  for(x=0;x<n;x++)
    {
      set[x] = new tree();
      set[x]->v = x;
      set[x]->parent = set[x];
      set[x]->rank=0;
    }
  return;
}


tree* find(tree* x)
{
  if(x->parent!=x)
    x->parent = find(x->parent);
  return x->parent;
}

int union(tree* x,tree* y)
{
  tree* xroot = find(x);
  tree* yroot = find(y);
  if(xroot==yroot)return 0;

  if(xroot->rank<yroot->rank)
    {
      xroot->parent = yroot;
    }
  else if(xroot->rank>yroot->rank)
    {
      yroot->parent = xroot;
    }
  else
    {
      yroot->parent = xroot;
      xroot->rank++;
    }
  return 1;
}

int main()
{
  int t;
  t=fi();
  tree** set;
  int n,e;
  int a,b;
  int x,last;
  while(t--)
    {
      n=fi();
      e=fi();
      set = new tree*[n];
      makeset(set,n);
      last = n;
      while(e--)
	{
	  a=fi();
	  b=fi();
	  n-=union(set[a],set[b]);
	}

      printf("%d\n",last);
    }
  return 0;
}
