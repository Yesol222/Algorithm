#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int unf[30];

struct Graph{
    int v1;
    int v2;
    int e;
    Graph(int a, int b, int c){
        v1=a;
        v2=b;
        e=c;
    }
    bool operator<(const Graph &G){
        return e<G.e;
    }
};

int Find(int v){
    if(unf[v]==v) return v;
    else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) a=unf[b];
}

priority_queue<Graph> Q;

// map 자료구조만 필요, pq를 사용하지는 않는다. 맵에 저장하고 오름차순 정렬 하면 됨.
int main(){
    int n, m, a, b, c, res;
    vector<Graph> map;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map.push_back(Graph(a,b,c));
    }
    sort(map.begin(),map.end()); // 오름차순 정렬!!
    for(int i=0;i<m;i++){
        int fa=Find(map[i].v1);
        int fb=Find(map[i].v2);
        if(fa!=fb){
            res+=map[i].e;
            Union(map[i].v1,map[i].v2);
        }
    }
    // for(int i=0;i<map.size();i++){
    //     Q.push(Graph(map[i].v1,map[i].v2,map[i].e));
    
    // }
    // for(int i=1; i<=n ;i++){
    //     unf[i]=i;
    // }

    // while(!Q.empty()){
    //     Graph tmp=Q.top();
    //     Q.pop();
        
    //     if(Find(tmp.v1)==Find(tmp.v2)) continue;
    //     else{
    //         Union(tmp.v1,tmp.v2);
    //         res += tmp.e;
    //     }
    // }

    printf("%d",&res);
    return 0;
}