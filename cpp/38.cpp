#include <stdio.h>
#include <vector>
#include <algorithm>

int main(){
    int n,i,j,idx,tmp,cnt;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",a[i]);
    }

    for(i=1;i<=n;i++){
        tmp=i;
        cnt=0;
        idx=a[i];
        for(j=idx;j>=0;j--){
            if(a[j]<tmp) cnt++; 
        }
        for(j=(idx+cnt);j<n;j++){
            if(a[j]<tmp) cnt++;
        }
        a[idx+cnt]=tmp;
    }

    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }

    return 0;
}