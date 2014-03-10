#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **a ;
	a = (int**)malloc(sizeof(int*)*10);
	int x;
	
	for(x=0;x<10;x++)
	{
		a[x]=(int*)malloc(sizeof(int)*100000000);
	}
	
	for(x=0;x<10;x++)
	{
		a[x][x] = -1;
	}
	
	for(x=0;x<10;x++)
	{
		printf("%d\n",a[x][x]);
	}
	return 0;
}
