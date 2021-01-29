#include <stdio.h>

int main(){
    int N,M,i,cnt=0,a,max=-2147000000;

    scanf("%d %d",&N,&M);

    for(i=1;i<=N;i++){
        scanf("%d",&a);
        if(a>M){
            cnt++;
            if(cnt >= max) max = cnt;
        }
        else cnt =0;
    }

    if(max==-2147000000) printf("-1");

    return 0;
}