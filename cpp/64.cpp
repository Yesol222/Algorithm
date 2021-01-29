#include <stdio.h>
#include <algorithm>

using namespace std;
int vertex[30];
int map[30][30];
int cnt = 0, n;
// int c = 0;
// void dfs(int L){
//     if(L==5){
//         return;
//     }
//     else{
//         vertex[++c]=L;
//         for(i=1;i<=n;i++){
//             if(map[L][i]==1){
//                 dfs(i);
//             }
//         }        
//     }
// }

void dfs(int v){
    int i;
    if(v==n){
        cnt++;
    }
    else{
        for(i=1;i<=n;i++){
            if(map[v][i]==1 && ch[i]==0){
                ch[i]=1;
                dfs(i);
                ch[i]=0;
            }
        }
    }
}
int main(){
    int m ,i, a, b;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b);
        map[a][b]=1;
    }
    ch[1]=1;
    dfs(1);
    printf("%d",&cnt;)
    return 0;
}