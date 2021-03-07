
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[30][30], dis[30][30];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

struct LoC{
    int x;
    int y;
    LoC(int a, int b){
        x=a;
        y=b;
    }
};

queue<LoC> Q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
        }
    }

    Q.push(LoC(1,1));
    map[1][1]=1;

    while(!Q.empty()){
        LoC tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int xx=tmp.x+dx[i];
            int yy=tmp.y+dy[i];
            if(map[xx][yy] == 0 && xx>=1 && xx<=7 && yy>=1 && yy<=7){
                Q.push(LoC(xx,yy));
                map[xx][yy]=1;
                dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
            }
        }
    }


    // dis[1][1]=0;

    // while(!Q.empty()){
    //     LoC tmp=Q.front();
    //     Q.pop();
    //     for(int i=0;i<8;i++){
    //         if(tmp.x+dx[i]>0 && tmp.x+dx[i]<=n && tmp.y+dy[i]>0 && tmp.y+dy[i] <=n){
    //             Q.push(LoC(tmp.x+dx[i],tmp.y+dy[i]));
    //             dis[tmp.x+dx[i]][tmp.y+dy[i]] = dis[tmp.x][tmp.y]+map[tmp.x+dx[i]][tmp.y+dy[i]];
    //         }
    //     }

    // }

    return 0;
}