#include <stdio.h>

int main(){
    int N, i;
    scanf("%d",&N);
    int a[N], b[N];

    for(i=0;i<N;i++){
        scanf("%d\n%d",&a[i],&b[i]);
        if(a[i]-b[i]==-1) printf("B");
        else if(a[i]-b[i]==-2 || a[i]-b[i]>0) printf("A");
        else printf("D");
    }
}