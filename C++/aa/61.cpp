#include <stdio.h>

using namespace std;

int n, m, a[11], path[11];
bool flag = false;
void dfs(int L,int result){
    if(flag==true) return;
    if(L==n+1){
        if(result==m) flag=true;
        for(int i=1;i<L;i++){
            printf("%d",path[i])
        }
        puts("")
    }
    else{
        path[L]+=a[L];
        dfs(L+1,result+a[L]);
        path[L]-=a[L];
        dfs(L+1,result-a[L]);
        path[L]=a[L];
        dfs(L+1,result);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,0);

    if(flag==true) printf("YES");
    else printf("NO");
}