#include <stdio.h>

using namespace std;
#define max 200000

// 다른 방법도 있는데  #include<math.h>를 하고

// for(j=2; j<=sqrt(i); j++){

// printf("%d\n", j);

// }
    
int main(){
    int n,i,j,flag,cnt=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        flag=1;
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }
    }
    // int N, primes, i=0;
    // bool a[N];
    // a[0] = false;
    // a[1] = false;
    // a[2] = false;
    
    // for(i=2;i<max;i=i*2){
    //     if(N%i==0){
    //         a[i] = false;
    //     }
    //     else{
    //         a[i] = true;
    //     }
    // }
}