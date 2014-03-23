#include<stdio.h>

int main()
{
    long long int a,b;
    long long int c;
    int arr[127];
    int arr1[10];
    arr[63] = 0;
    arr[10] = 1;
    arr[93] = 2;
    arr[79] = 3;
    arr[106] = 4;
    arr[103] = 5;
    arr[119] = 6;
    arr[11] = 7;
    arr[127] = 8;
    arr[107] = 9;

    arr1[0] = 63;
    arr1[1] = 10;
    arr1[2] = 93;
    arr1[3] = 79;
    arr1[4] = 106;
    arr1[5] = 103;
    arr1[6] = 119;
    arr1[7] = 11;
    arr1[8] = 127;
    arr1[9] = 107;
    long long int s,t;
    long long int a1,b1;
    int temp;
    int digit;
    long long int ans;
    while(scanf("%lld+%lld=",&a,&b)==2)
    {
        temp = a%1000;
        a1=a;
        b1=b;
        s=0;t=0;
        ans=0;
        //printf("%d",arr[a]);
        while(a!=0)
        {
            s = s*10 + arr[temp];
            a/=1000;
            temp = a%1000;
        }
        while(b!=0)
        {
            temp = b%1000;
            t = t*10 + arr[temp];
            b/=1000;
        }
        s+=t;
        while(s!=0)
        {
            digit = s%10;
            s/=10;
            ans = ans*1000 + arr1[digit];
        }
        printf("%lld+%lld=%lld\n",a1,b1,ans);
    }

    return 0;
}
