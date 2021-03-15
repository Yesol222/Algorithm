#include <stdio.h>
#include <vector>
#include <queue>

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;
struct State{
    int x;
    int y;
    int dis;
    State(int a, int b, int d){
        a=x;
        y=b;
        dis=d;
    }
    bool operator<(State &dd){
        if(dis==dd.dis){
            if(x==dd.x) return y>dd.y;
            else return x>dd.x;
         }
         else return dis>dd.dis;
    }
};

struct Lion{
    int x, y;
    int ate = 0;
    int s = 0;
    void sizeUp(){
        s++;
    }
};

int main(){
    int n, res=0;
    scanf("%d",&n);
    int map[30][30], ch[30][30];
    priority_queue<State> Q;
    Lion simba;
    simba.s = 2;
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==9){
                Q.push(State(i,j,0)); //심바 위치를 처음 큐에 넣는다
                simba.x = i;
                simba.y = j;
                map[i][j]=0; //지나갔으므로 0 으로.
            }
        }
    }
    
    while(!Q.empty()){
        State tmp = Q.top();
        Q.pop();
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.dis;

        if(map[x][y]!=0 && map[x][y]< simba.s){
            simba.x=x;
            simba.y=y;
            simba.ate++;
            if(simba.ate==simba.s) simba.sizeUp();
            map[x][y]=0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    ch[i][j] = 0;
                }
            }
            while(!Q.empty()) Q.pop();
            res = tmp.dis;
        }

        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx<1 || xx>n || yy<1 || yy>n || map[xx][yy]>simba.s || ch[xx][yy]>0) continue;
            Q.push(State(xx,yy,z+1));
            ch[xx][yy]=1;
        }
    }
    
    printf("%d",&res);
    return 0;
}
