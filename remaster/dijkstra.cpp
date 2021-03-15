#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//간선 값이 무조건 양수이기 때문에 최소값 갱신은 이루어지지 않는다.
//가중치 방향 그래프, 양수값

struct Edge{
    int vertex;
    int value;
    Edge(int a, int b){
        vertex =a;
        value = b;
    }
    bool operator<(const Edge &b){
        return value>b.value; //min-heap
    }
};

priority_queue<Edge> Q;

int main(){
    int n, m, min, a, b, c;
    scanf("%d %d", &n,&m);
    vector<int> dist(n+1);
    vector<Edge> map[30];
    
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a].push_back(Edge(b,c));
    }

    for(int i=1;i<=n;i++){
        dist[i]=2147000000;
    }
    Q.push(Edge(1,0));
    dist[1]=0;
    while(!Q.empty()){
        Edge tmp = Q.top();
        Q.pop();
        int v = tmp.vertex;
        int cost = tmp.value;
        
        if(cost>dist[v]) continue; //cost가 더 크면 넘어가기. 
        else{
            for(int i=0;i<map[v].size();i++){
                //여기서 이제 dist 계산을 해봐야 함
                int next = map[v][i].vertex;
                int nextDis = cost+map[v][i].value; //현재 정점의 비용 + 간선의 가중치
                if(dist[next]>nextDis){
                    dist[next]=nextDis;
                    Q.push(Edge(next,nextDis)); //cost가 작은 경우에만 큐에 들어감. 왜냐면 최소값이였으면 이미 지나간 정점임. 
                }
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(dist[i]==2147000000) printf("impossible");
        else printf("%d",&dist[i]);
    }
    return 0;
}