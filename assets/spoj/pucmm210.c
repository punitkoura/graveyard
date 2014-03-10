#include<stdio.h>
#include<stdlib.h>
#define thresh 1000000003

int main(){
    int t;
    scanf("%d",&t);
    int n,x;
    long long int *a;
    long long int sum;
    a = (long long int*)malloc(sizeof(long long int)*1000000);
    if(a==NULL){
        printf("LITE!");
        return 0;
    }
    for(n=0; n<1000000; n++){
        a[n] = (n+1);
        a[n] *=(n+1);
        if(a[n]>thresh)
            a[n]%=thresh;
        a[n] *=(n+1);
        if(a[n]>thresh)
            a[n]%=thresh;
    }

    while(t--){
        scanf("%d",&n);
        sum = 0;
        for(x=0;x<n;x++){
            sum+=(n-x)*a[x];
            if(sum>thresh)
                sum%=thresh;
        }

        printf("%lld\n",sum);
    }


    return 0;
}
