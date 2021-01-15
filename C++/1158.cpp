#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n,k,pos=0,i,bp=0,cnt=0;
    scanf("%d %d",&n,&k);
    vector<int> prince(n+1); //range= 1~n
    vector<int> result(n+1);
    while(1){
        pos++;
        if(pos>n) pos=1;
        if(prince[pos]==0){
            cnt++;
            if(cnt==k){
                prince[pos]=1;
                cnt=0;
                bp++;
                result.push_back(pos);
            }
        }
        if(bp==n) break;
    }
    for(i=1;i<=n;i++){
        printf("%d",result[i]);
    }
    return 0;
}