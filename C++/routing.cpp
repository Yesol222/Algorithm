#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
int t, n, m;
vector<vector<pair<int, double> > > graph;

struct Edge{
    int vex;
    double dist;
    Edge(int a, double b){
        vex=a;
        dist=b;
    }
    bool operator<(const Edge &e)const{
        return dist>e.dist;
    }
};

void dijkstra(){
    vector<double> dis(n+1,2147000000.0);
    priority_queue<Edge> Q;

    int a, b;
	double c;
  
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    Q.push(Edge(0,1.0));
    dis[0]=1.0;

    while(!Q.empty()){
        int now=Q.top().vex;
        double cost=Q.top().dist;
        Q.pop();
        if(cost>dis[now]) continue;
        for(int i=0;i<graph[now].size();i++){
            int next=graph[now][i].first;
            double nextDis=cost*graph[now][i].second;
            if(dis[next]>nextDis) {
            	Q.push(Edge(next,nextDis));
				dis[next]=nextDis;
			}
        }
    }
    printf("%.10f\n",dis[n-1]);
}
int main(){
    cin >> t;

    while(t--){
	    cin >> n >> m;
        graph.clear();
        graph.resize(n+1);
        dijkstra();
    }
    return 0;
}