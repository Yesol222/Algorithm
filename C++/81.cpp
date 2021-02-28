#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int dist[101];
struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s=a;
        e=b;
        val=c;
    }
};

int main(){
    vector<Edge> Ed;
    int i, n, m, a, b, c, j, s, e;
    scanf("%d %d",&n, &m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        Ed.push_back(Edge(a,b,c));
    }
    for(i=1;i<=n;i++){
        dist[i]=2147000000;
    }
    scanf("%d %d",&s,&e);
    dist[s]=0;
    for(i=1;i<n;i++){ //i : 간선의 개수, i=1이면 한번만에 가는 경로
        for(j=0;j<Ed.size();j++){
            int u=Ed[j].s;
            int v=Ed[j].e;
            int w=Ed[j].val;
            if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    for(j=0;j<Ed.size();j++){
        int u=Ed[j].s;
        int v=Ed[j].e;
        int w=Ed[j].val;
        if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
            printf("-1");
            exit(0);
        }
    }//음의 사이클이 생기는 경우!
    
    printf("%d",dist[e]);
}