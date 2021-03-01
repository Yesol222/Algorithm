#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int n, map[30][30], cnt=0;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,-1,1,1,0,-1};
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
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&map[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(map[i][j]==1){
                Q.push(Loc(i,j));
                map[i][j]=0;
                while(!Q.empty()){
                    Loc tmp = Q.front();
                    Q.pop();
                    for(int i=0;i<8;i++){
                        if(map[tmp.x + dx[i]][tmp.y+dy[i]] == 1){
                            Q.push(Loc(tmp.x+dx[i], tmp.y+dy[i]));
                            map[tmp.x+dx[i]][tmp.y+dy[i]]] = 0;
                        }
                    }
                }
                cnt++;
            }
        }
        pritnf("%d",cnt);
        return 0;
    }
}