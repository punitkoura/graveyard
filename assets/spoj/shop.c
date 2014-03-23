#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    int**c;
    char**i,**v, read;
    int x,y;
    int sx,sy,dx,dy;
    int ans;

    while(a!=0)
    {
        ans = 0;
        i = (char**)malloc(sizeof(char*)*(b +2));
        c = (int**)malloc(sizeof(int*)*(b + 2));
        v = (char**)malloc(sizeof(char*)*(b + 2));

        for(x=0;x<=b+1;x++)
        {
            i[x] = (char*)malloc(sizeof(char)*(a + 2));
            c[x] = (int*)malloc(sizeof(int)*(a + 2));
            v[x] = (char*)malloc(sizeof(char)*(a + 2));

            for(y=0; y<=a+1; y++){
                if(x==0 || x==b+1 || y==0 || y==a+1){
                    i[x][y] = 'X';
                    v[x][y] = 1;
                    c[x][y] = 100000;
                }

                else{
                    read = getchar();
                    if(read == '\n')
                        read = getchar();

                    i[x][y] = read;

                    if(read=='S'){
                        sx = x;
                        sy = y;
                    }

                    else if(read == 'D'){
                        dx = x;
                        dy = y;
                    }
                    c[x][y] = 100000;
                    v[x][y] = 0;

                    if(read=='X')
                        v[x][y] = 1;
                }

            }
        }
        c[sx][sy] = 0;

    x=sx;   y=sy;
    int cost,minx,miny;

    ans = 100;
    while(v[dx][dy]==0){
        ans--;
        if(x==dx && y==dy)
            break;
        cost = 100000;
        if(v[x+1][y]==0){
            if(c[x+1][y] >= (c[x][y]+(i[x+1][y]-'0')))
                c[x+1][y] = (c[x][y]+(i[x+1][y]-'0'));
            if(cost>c[x+1][y]){
                cost = c[x+1][y];
                minx = x+1;
                miny = y;
            }
        }

        if(v[x][y+1]==0){
            if(c[x][y+1] >= (c[x][y]+(i[x][y+1]-'0')))
                c[x][y+1] = (c[x][y]+(i[x][y+1]-'0'));

            if(cost>c[x][y+1]){
                cost = c[x][y+1];
                minx = x;
                miny = y+1;
                printf("lite\n");
            }
        }

        if(v[x-1][y]==0){
            if(c[x-1][y] >= (c[x][y]+(i[x-1][y]-'0')))
                c[x-1][y] = (c[x][y]+(i[x-1][y]-'0'));

            if(cost>c[x-1][y]){
                cost = c[x-1][y];
                minx = x-1;
                miny = y;
            }
        }

        if(v[x][y-1]==0){
            if(c[x][y-1] >= (c[x][y]+(i[x][y-1]-'0')))
                c[x][y-1] = (c[x][y]+(i[x][y-1]-'0'));

            if(cost>c[x][y-1]){
                cost = c[x][y-1];
                minx = x;
                miny = y-1;
            }

        }

        v[x][y] = 1;
        x = minx;
        y = miny;

        print(a,b,c);
        //printf("%d\t%d\t%d",x,y,cost);
        printf("\n\n");

        if(ans==0)
            break;

    }

    printf("%d\n",c[dx][dy]+'0'-'D');



    scanf("%d",&a);
    scanf("%d",&b);
    }

    return 0;
}

 void print(int a, int b, int  ** c){
     int x,y;
            for(x=0; x<b+2; x++){
                for(y=0; y<a+2; y++){

                    printf("%d\t",c[x][y]);
                }
                printf("\n");
            }
    return;
 }
