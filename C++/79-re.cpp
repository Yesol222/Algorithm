#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
ch[30]=0;
struct Edge{
    int v;
    int val;
    void Edge(int a, int b){
        v=a;
        val=b;
    }
    bool operator<(const Edge &e)const{
        return val>e.val; 
    }
};
int main(){
    int n,m,a,b,c,i,res=0,x;
    priority_queue<Edge> PQ;
    vector<pair<int, int> > map[30];
    for(i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a].push(make_pair(b,c));
        map[b].push(make_pair(a,c));
    }
    
    PQ.push(1,0);
    ch[1]=0;
    while(!PQ.empty()){
        Edge x=PQ.top();
        int e = x.v;
        int cost = x.val;
        PQ.pop();
        if(ch[e-1]==0){
            res+=cost;
            ch[e-1]=1;
            for(i=0;i<map[e].size();i++){
                PQ.push(map[e][i].first(),map[e][i].second);
            }
        }
    }


    return 0;
}