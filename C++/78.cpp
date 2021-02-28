#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
unf[10001];
struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1=a;
        v2=b;
        val=c;
    }
    bool operator<(Edge &b){
        return val<b.val;
    }
};

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}

Void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}
int main(){
    vector<Edge> Ed;
    int i,n,m,a,b,c, cnt=0, res=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        unf[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        Ed.push_back(Edge(a,b,c));
    }
    Ed.sort(Ed.begin(),Ed.end());

    for(i=0;i<m;i++){ //sort했기 때문에 가중치 내림차순으로 정렬.
        int fa=Find(Ed[i].v1);
        int fb=Find(Ed[i].v2);
        if(fa!=fb){ //이미 연결된 노드들이 아니라면 가중치 더한 후Union.
            res+=Ed[i].val;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    printf("%d",res);
    return 0;
}