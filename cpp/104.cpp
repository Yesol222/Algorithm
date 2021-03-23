#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m ,a, b, score;
    cin>>n>>m;
    vector<vector<int> > graph(n+1, vector<int>(n+1,0));
    vecotr<int> degree(n+1);
    queue<int> Q;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a][b]=1;
        degree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0) Q.push(i);
    }

    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        cout<<now<<" ";
        for(int i=1;i<=n;i++){
            if(graph[now][i]==1){
                degree[i]--;
                if(degree[i]==0) Q.push(i);
            }
        }
    }
    return 0;
}