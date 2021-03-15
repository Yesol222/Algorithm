#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int ch[30];
struct Edge{
    int v;
    int e;
    Edge(int a, int b){
        v=a;
        e=b;
    }
    bool operator<(const Edge &b)const{
        return e<b.e;
    }
};
priority_queue<Edge> Q;

//차이점 map에 Edge형 대신 pair로 저장함. 조건문을 깔꼼하게 정리.
int main(){
    vector<pair<int, int> > map[30];
    int i, n, m, a, b, c ,res=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }    
    Q.push(Edge(1,0));
    while(Q.empty()){
        Edge tmp = Q.top();
        Q.pop();
        int v=tmp.v;
        int cost=tmp.e;
        if(ch[v]==0){
            res+=cost;
            ch[v]=1;
            for(i=0;i<map[v].size();i++){
                Q.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    
    
    
}
int main(){
    int n, m, i, a, b, c, res;
    vector<Edge> map[30];
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a].push_back(Edge(b,c));
        map[b].push_back(Edge(a,c));
    }

    Q.push(Edge(1,0));


    //not even close!! 큐는 비우지 않고 유지되어야 한다. 언제라도 다시 꺼내 쓸 수 잇어야 하니까
    // queue에 계속 저장을 하고 pq니까 계속해서 꺼내면 됨.
    //"노드" 만 신경쓰면 된다. 방문 했는지 안했는지... 재방문만 아니라면 사이클 문제는 없을 것
    // while(!Q.empty()){
    //     Edge tmp = Q.top();
    //     Q.pop();
    //     int x = tmp.v;
    //     int y = tmp.e;

    //     if(ch[x]!=0) continue;
    //     else{
    //         ch[x]=1;
    //         while(!Q.empty()) Q.pop(); -> 이 부분이 전혀 필요가 없음.
    //     }
    //     for(i=0;i<map[x].size();i++){
    //         Q.push(Edge(map[x][i].v,map[x][i].e));
    //     }
    // }
    return 0;
}