#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,k,pos=0,i,bp=0,cnt=0;
    scanf("%d %d",&n,&k);
    vector<int> prince(n+1); //range= 1~n
    while(1){
        pos++;
        if(pos>n) pos=1;
        if(print[pos]==0){
            cnt++;
            if(cnt==k){
                print[pos]=1;
                cnt=0;
                bp++;
            }
        }
        if(bp==n-1) break;
    }
    for(i=1;i<=n;i++){
        if(prince[i]=0){
            printf("%d\n",i);
        }
    }
    return 0;
}