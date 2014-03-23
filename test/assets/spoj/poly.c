#include<stdio.h>

int main(){
    double n,i;
    double ans;
 //   scanf("%f",&n);
    ans = (3*n*n*n*n + 5*n*n*n + 25*n*n + 15*n +2);
    for (i=-0.4535686500; i< -0.4535686400; i=i+0.0000000001){
        n = i;
        ans = (3*n*n*n*n + 5*n*n*n + 25*n*n + 15*n +2);
        printf("%.10lf %.10lf\n",ans,n);
    }
  //  printf("%lf %f\n",ans,n);

}
