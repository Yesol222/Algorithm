#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, res=-2147000000;
int tom[30][30];
int dis[30][30];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};
queue<Loc> Q;

int main(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tom[i][j]);
            if(tom[i][j]==1){
                Q.push(Loc(i,j));
            }
        }
    }
    
    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i__){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];
            if(tom[xx][yy]==0){
                if(xx>=1 && xx<=n && yy >=1 && yy<=m){
                    Q.push(Loc(xx,yy));
                    tom[xx][yy]=1;
                    dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
                }
            }
        }
    }

    int f = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(tom[i][j]==0) f=0;
        }
    }
    if(f==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(res<dis[i][j]) res=dis[i][j];
            }
        }
        printf("%d",res);
    }
    else printf("-1");
    return 0;
}