#include <stdio.h>
#include <algorithm>

using namespace std;

int n, total=0, a[11];
bool ch = false;

dfs(int L, int sum){
    if(sum>(total/2) return;
    if(ch==true) return;
    if(L==n+1){
        if(sum==(total-sum)){
            ch=true;
        }
    }
    else{
        dfs(L+1,sum+a[L]);
        dfs(L+1,sum);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
    }
    dfs(1,0);

    if(ch==true) printf("YES");
    else printf("No");

    return 0;
}