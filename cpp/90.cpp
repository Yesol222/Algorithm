#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int map[30][30];
int time=0, size=2, n, cnt=0;
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};

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
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==9) {
                Q.push(Loc(i,j));
                map[i][j]=0;
            }
        }
    }

    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];
            if(xx>=1 && xx<= n && yy>=1 && yy<=n && map[xx][yy]<=size && map[xx][yy]!=0){
                Q.push(Loc(xx,yy));
                cnt++;
                if(map[xx][yy]<size){
                    if(size==cnt) size+1;
                    map[xx][yy]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]!=0) printf("%no");
        }
    }
    printf("%d",&cnt);
    
    return 0;
}