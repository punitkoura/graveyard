#include<stdio.h>
#define z 10000007
#define thresh 2000000000

int main(){
     long long int n, k, i,m,sk,pk,sum,x;
     scanf("%lld",&n);
     scanf("%lld",&k);

     while(!(n==0 && k==0)){
        sk = 2;
        pk = 1;

        if(n<k)
            m = n;
        else
            m = k;

        for(i = 0; i<m-1; i++){
                sk*=(n-1);
                pk*=n;
                if(pk>thresh){
                    sk%=z;
                    pk%=z;
                }
        }

        if(m==k){
            sk*=(n-1);
            pk*=n;
            if(pk>thresh){
                sk%=z;
                pk%=z;
            }
        }

        else{
            pk*=(n);
            if(pk>thresh){
                pk%=z;
            }
        }
        x = m;
        m = n+k-m;
        sum = (pk+sk)%z;

        for(i=x; i<m-1; i++){
                sk*=(n-1);
                pk*=n;
                if(pk>thresh){
                    sk%=z;
                    pk%=z;
                }
        }
        if(m==k){
            sk*=(n-1);
            sk%=z;
            sk*=(n-1);
            pk*=n;
            if(pk>thresh){
                sk%=z;
                pk%=z;
            }
        }

        else{
            pk*=(n);
            if(pk>thresh){
                pk%=z;
            }
        }

        sum = (sum+pk+sk)%z;
        printf("%lld\n",sum);
        scanf("%lld",&n);
        scanf("%lld",&k);
     }

     return 0;

}
