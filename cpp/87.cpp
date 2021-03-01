#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > map;
queue<pair<int, int> > Q;
pair<int, int> point;
int n;

int main(){
    int cnt;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,-1,0};
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }

    point = make_pair(0,0);

    while(point.first<n && point.second<n){
        if(map[point.first][point.second]==1){
            Q.push(point);
            while(!Q.empty()){
                point = Q.front();
                Q.pop();
                if(map[point.first][point.second]==1){
                    for(int i=0;i<4;i++){
                        int x = x+dx[i];
                        int y = y+dy[i];
                        if(map[x][y]==1){
                            Q.push(make_pair(x,y));
                            point=make_pair(x,y);
                            map[x][y]=0;
                        }
                    }
                }
            }
            cnt++;
        }
        else if(map[point.first][point.second]==0){
                for(int i=0;i<4;i++){
                    int x = x+dx[i];
                    int y = y+dy[i];
                    if(map[x][y]==1){
                        point=make_pair(x,y);
                        break;
                    }
                }
            }
    }
    printf("%d",&cnt);
    return 0;
}