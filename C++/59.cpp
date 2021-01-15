#include<stdio.h>
#include<algorithm>

using namespace std;
int n, ch[11];
void dfs(int L){
    int i;
    if(L==n+1){
        for(i=1;i<=n;i++){
            if(ch[i]==1) printf("%d ",&i);
        }
        puts("");
    }
    else{
        ch[L]=1;
        dfs(L+1);
        ch[L]=0;
        dfs(L+1);
    }
}
int main(){
    scanf("%d",&n);
    vector<int> ch(n+1);
    for(int i=1;i<=n;i++){
        ch[i]=1;
    }
    dfs(1);
}