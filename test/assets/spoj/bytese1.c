#include<stdio.h>

typedef struct
{
    int x;
    int y;
    int color;
    int d;
    int q;
} point;

struct node
{
    point p;
    struct node*next;
};
typedef struct node* link;

link head,tail;

void enqueue(point p)
{
    if(tail==NULL)
    {
        head = tail = (link)malloc(sizeof(struct node));
        head->p = p;
        tail->p = p;
        return;
    }
    tail->next = (link)malloc(sizeof(struct node));
    tail = tail->next;
    tail->next = NULL;
    return;
}

point dequeue()
{
    point temp;
    link temp1;
    if(head==tail)
    {
        temp = head->p;
        free(head);
        head=tail=NULL;
        return temp;
    }
    temp = head->p;
    temp1 = head;
    head = head->next;
    free(temp1);
    return temp;
}

int main()
{
    head = tail = NULL;
    int k
    scanf("%d",&k);
    int m,n;
    point **arr;
    int x,y;
    int a,b,t;
    int q;
    point ptemp;
    while(k--)
    {
        scanf("%d",&m);
        scanf("%d",&n);
        arr = (point**)malloc(sizeof(point*)*(m+2));
        for(x=0;x<=m+1;x++)
        {
            arr[x] = (point*)malloc(sizeof(point)*(n+2));
        }
        for(x=1;x<=m;x++)
        {
            for(y=1;y<=n;y++)
            {
                scanf("%d",&q);
                arr[x][y].x = x;
                arr[x][y].y = y;
                arr[x][y].color = 0;
                arr[x][y].d = 200;
                arr[x][y].q = q;
            }
        }
        scanf("%d",&a);scanf("%d",&b);scanf("%d",&t);
        for(x=0;x<=m+1;x++)
        {
            arr[x][0].d = 200;
            arr[x][0].x = x;
            arr[x][0].y = 0;
            arr[x][0].color=0;
            arr[x][0].q=0;

            arr[x][n+1].d = 200;
            arr[x][n+1].x = x;
            arr[x][n+1].y = n+1;
            arr[x][n+1].color = 0;
            arr[x][n+1].q=0;
        }

        for(x=0;x<=n+1;x++)
        {
            arr[0][x].d = 200;
            arr[0][x].x = 0;
            arr[0][x].y = x;
            arr[0][x].color = 0;
            arr[0][x].q=0;

            arr[m+1][x].d = 200;
            arr[m+1][x].x = m+1;
            arr[m+1][x].y=x;
            arr[m+1][x].color = 0;
            arr[m+1][x].q=0;
        }
        arr[1][1].color = 1;
        arr[1][1].d = arr[1][1].q;

        enqueue(arr[1][1]);

        while(head!=NULL)
        {
            ptemp = dequeue();
            if((ptemp.x==1 || ptempx==m) && (ptemp.y==1 || ptemp.y=n))
            {

            }
        }
    }
}
