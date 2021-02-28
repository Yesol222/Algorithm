#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<pair<int, int> > map[30];

dfs(int s, int L, int sum){
    if(L==m){
        
    }
    else{
        for(int j=s;j<map[1].size();j++){
            sum = abs(map[1][s].first-map[2][L].first) + abs(map[1][L].second-map[2][L].second);
            dfs(j+1,L+1,sum);
        }
    }
}

int main(){
    int x;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&x);
            if(x==1){
                map[1].push_back(make_pair(i,j));
            }
            else if(x==2){
                map[2].push_back(make_pair(i,j));
            }
        }
    }

    dfs(0,0,0);
    return 0;
}
