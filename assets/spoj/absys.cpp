#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
	int t;
	char arr[40],brr[40],crr[40],drr[40],err[40];
	int a,b,c;
	
	scanf("%d",&t);
	int l;
	char ch;
	int x;
	int choice;
	
	while(t--)
	{
		scanf("%s %s %s %s %s",arr,drr,brr,err,crr);
		l = strlen(arr);
		for(x=0;x<l;x++)
		{
			if(arr[x] == 'm');
			choice = 0;
		}
		
		l = strlen(brr);
		for(x=0;x<l;x++)
		{
			if(brr[x] == 'm');
			choice = 1;
		}
		
		l = strlen(crr);
		for(x=0;x<l;x++)
		{
			if(crr[x] == 'm');
			choice = 2;
		}
		
		if(choice == 0)
		{
			b = atoi(brr);
			c = atoi(crr);
			a = c-b;
		}
		else if(choice==1)
		{
			a = atoi(arr);
			c=atoi(crr);
			b = c-a;
		}
		else if(choice==2)
		{
			a = atoi(arr);
			b = atoi(brr);
			c = a+b;
		}
		
		printf("%d + %d = %d\n",a,b,c);
		printf("%s %s %s %s %s\n",arr,drr,brr,err,crr);
		printf("choice = %d\n",choice);
	}
	return 0;
}