#include <stdio.h>
#include <vector>
//완전탐색
using namespace std;
int map[30][30], ch[30], n, cost=2147000000;

void dfs(int v,int sum){
    int i;
    if(v==n){
        if(sum>cost) cost = sum;
        return;
    }
    else{
        for(i=1;i<=n;i++){
            if(map[v][i]>0 && ch[i]==0){
                ch[i]=1;
                dfs(i,sum+map[v][i]);
                ch[i]=0;
            }
        }
    }
}
int main(){
    int m, i, a, b, c;
    scanf("%d %d", &n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
    }
    ch[1]=1;
    dfs(1,0);
    return 0;
}