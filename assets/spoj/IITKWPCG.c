#include <stdio.h>
#include<stdlib.h>

struct E
{
	int u,v,priority;
};
typedef struct E Edge;

struct n;
typedef struct n node;

struct s
{
	node* head;
	node* tail;
	int length;
};
typedef struct s set;

struct n
{
	set* s;
	struct n* next;
	int n;
};
typedef struct n node;

int partition(Edge*,int ,int);

void quicksort(Edge* a,int p, int r)
{
    if(p<r)
    {
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int partition(Edge* a,int p,int r)
{
    int pivot = rand()%(r-p) + p;

    Edge t;
    t = a[pivot];
    a[pivot] = a[r];
    a[r] = t;
    Edge x = a[r];
    int i = p-1;
    int j;
    for(j=p;j<=r-1;j++)
    {
        if(a[j].priority<=x.priority)
        {
            i = i+1;
            t = a[i];
            a[i]=a[j];
            a[j] = t;
        }
    }
    t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
    return i+1;
}



struct n;
typedef struct n node;



void makeset(node** tree,int n)
{
	int x;
	for(x=0;x<n;x++)
	{
		tree[x] = (node*)malloc(sizeof(int)*n);
		tree[x]->s = (set*)malloc(sizeof(set));
		tree[x]->s->head = tree[x]->s->tail = tree[x];
		tree[x]->s->length = 1;
		tree[x]->next=NULL;
		tree[x]->n = x;
	}
	return;
}

int findset(node**tree,int u)
{
	return tree[u]->s->head->n;
}

void un(node**tree,int u,int v)
{
	set*a,*b;
	a = tree[u]->s;
	b = tree[v]->s;
	set*temp;
	if(a->length < b->length)
	{
		temp=a;
		a=b;
		b=temp;
	}

	node* t;
	t = b->head;
	while(t!=NULL)
	{
		t->s = a;
		t=t->next;
	}
	a->tail->next = b->head;
	a->tail = b->tail;
	a->tail->next=NULL;
	a->length = a->length + b->length;
	b=a;
	return;
}



int main(void) {
	int t;
	int n,m;
	int a,b;
	unsigned long long int c;
	unsigned long long int temp;
	int x;
	int count;
	node** tree;
	Edge* e;
	int cost;
	Edge z;
	node*zy;

	scanf("%d",&t);
	while(t--)
	{
		cost=0;
		scanf("%d",&n);
		scanf("%d",&m);
		e=(Edge*)malloc(sizeof(Edge)*m);
		tree = (node**)malloc(sizeof(node*)*n);

		makeset(tree,n);

		for(x=0;x<m;x++)
		{
			scanf("%d",&a);
			scanf("%d",&b);
			scanf("%llu",&c);
			temp = c;
			count=0;
			while(temp!=0)
			{
				count++;
				temp = temp>>1;
			}
			e[x].u=a-1;
			e[x].v=b-1;
			e[x].priority=count-1;
		}
		quicksort(e,0,m-1);

		for(x=0;x<m;x++)
		{
			z = e[x];
			if(findset(tree,z.u)!=findset(tree,z.v))
			{
				un(tree,z.u,z.v);
				cost+=z.priority;
			}
		}
		/*
		for(x=0;x<n;x++)
		{
			free(tree[x]);
		}
		free(tree);
		free(e);
		*/
		printf("%d\n",(cost+1));



	}
	return 0;
}
