#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int y,x,r,c;
	char *d;
	for(x=1;x<=n;x++)
	{
		scanf("%d",&r);
		scanf("%d",&c);
		d = (char*)malloc(sizeof(char)*r*c + 1);
		scanf("%s",d);
		
