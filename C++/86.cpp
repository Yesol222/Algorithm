#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, res;
vector<pair<int, int> > map[30];
pair<int, int> pizza[30];
dfs(int s, int L){
    if(L==m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += abs(map[1][i].first-map[2][j].first) + abs(map[1][i].second-map[2][j].second);
            }
        }
        if(res>sum) res=sum;
    }
    else{
        for(int j=s;j<map[2].size();j++){
            pizza[j] = map[2][j];
            dfs(j+1,L+1);
            pizza[j] = {0,0};
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

    dfs(0,0);
    return 0;
}
