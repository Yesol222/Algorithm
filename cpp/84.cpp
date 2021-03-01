#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n, t, p, sum=0;
vector<int> ch(n+1,0);
vector<pair<int, int> > map;

int dfs(int D){
    if(D==n+1){
        printf("%d",&sum);
        return;
    }
    else{
        sum += map[D].second();
        D += map[D].first();
        if(D>n+1) return;
        for(int i=D;i<=n;i++){
            if(ch[i]==0){
                ch[i]=1;
                dfs(i);
                ch[i]=0;
            }
        }
    }
}
int main(){
    int a, b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        map.push_back(make_pair(a,b));
    }
    ch[1]=1;
    dfs(1);
    
    return 0;    
}