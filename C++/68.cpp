#include <stdio.h>
#include <vector>

using namespace std;

int ch[30],n,cost=2147000000;
vector<pair<int,int> > map[n];

void dfs(int v, int sum){
    int i;
    if(v==n){
        if(sum<cost) cost = sum;
    }
    else{
        for(i=0;i<=map[v].size();i++){
            if(ch[map[v][i].first]==0){
                ch[]=1;
                dfs(map[v][i].first,sum+map[v][i].second);
                ch[map[v][i].first]=0;
            }
        } 
    }
}
int main(){
    //pair<int,int> p;
    //p.first p.second
    //p=make_pair(a,b)
    int m, i, a, b, c;
    scanf("%d %d",&n, &m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a] = make_pair(b,c);
    }
    ch[1]=1;
    dfs(1,0);

}

