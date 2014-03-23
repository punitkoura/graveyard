#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n = 1890;

int mul(char* a,int l)
{

    int i;
    int carry = 1;
    for(i=n-2;i>=(n-l);i--)
    {
        a[i] = 3*a[i]+carry;
        carry = a[i]/10;
        a[i]%=10;
    }
    a[i] = carry;

    if(carry!=0)
    {
        return l+1;

    }
    else return l;
}

int divide(char* arr,int l)
{
    int i,carry=0,temp,temp1;
    if(arr[n-l]==1) temp1=l-1;
    else temp1=l;
    for(i=n-l;i<=n-2;i++)
    {
        temp = arr[i];
        arr[i] = (carry*10 +arr[i])/2;
        carry = temp%2;
    }
    return temp1;
}

int main()
{
    char *arr;
    arr = (char*)malloc(sizeof(char)*n);
    long long int count = 1;
    while(scanf("%s",arr)!=-1){
        count = 1;
        int i,l;
        l=strlen(arr) + 1;

        for(i=0;i<l;i++)
            arr[n-l+i] = arr[i]-'0';
        for(i=0;i<n-l;i++)
            arr[i] = 0;
        while(!(l==2 && arr[n-l]==1))
        {
            if(arr[n-2]%2==0)
            {
                l = divide(arr,l);
            }
            else
            {
                l = mul(arr,l);
            }
            count++;

        }
        printf("%lld\n",count);
    }
    free(arr);
    return 0;
}



void print(char* a,int l)
{
    int i;
    for(i=n-l;i<=n-2;i++)
        printf("%d",a[i]);
    printf("\n");
}
