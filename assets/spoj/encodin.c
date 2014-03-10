#include <stdio.h>
#include<string.h>

int main(void) {
	char arr[100];
	int l;
	int count;
	char c;
	int x;
	int flag=0;

	while(gets(arr))
	{
		flag=0;
		count=1;
		if(arr[0]==EOF)break;
		l = strlen(arr);
		if(l==0)
		{
			printf("\n");
			continue;
		}
		if(l==1)
		{
			if(arr[0]=='1')
			printf("1111\n");
			else
			printf("1%c1\n",arr[0]);
			continue;
		}

		for(x=1;x<l;x++)
		{
			c=arr[x];
			if(c==arr[x-1])
			{
				count++;
				if(count==9)
				{
					if(c=='1')printf("%d1",count);
					else printf("%d%c",count,c);
					count=0;
				}
			}
			else
			{
				if(count>1)
				{
					printf("%d%c",count,arr[x-1]);
					count=1;
				}
				else if(count==1)
				{
					if(arr[x-1]=='1')printf("11");
					else printf("1%c",arr[x-1]);

					x++;
					while(x<l)
					{
						if(arr[x]==arr[x-1])break;
						if(arr[x-1]=='1')printf("11");
						else printf("%c",arr[x-1]);
						x++;
					}
					if(x==l)
					{
						flag=1;
						if(arr[x-1]=='1')printf("111");
						else printf("%c1",arr[x-1]);
					}
					else
					{
						count=2;
						printf("1");
					}
				}
			}
		}
		if(flag==1)
		{

		}
		else
		{
			printf("count %d\n",count);
			if(arr[x-1]=='1')printf("%d11",count);
			else printf("%d%c",count,arr[x-1]);
		}
		printf("\n");
	}

	return 0;
}
