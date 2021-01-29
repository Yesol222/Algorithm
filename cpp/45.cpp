#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,k,ck=0,cnt=0,pos=0,i;
    scanf("%d %d",&n,&k);
    vector<int> a(n+1);
    
    while(1){
        pos++;
        if(pos>n) pos=1;
        if(a[pos]==0){
            cnt++;
            if(cnt==k){
                a[pos]=1;
                cnt=0;
                ck++;
            }
        }
        if(ck==n-1) break;
    }
    for(i=1;i<=n;i++){
        if(a[i]==0) printf("%d",i);
    }
}