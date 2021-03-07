#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int map[30][30];
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

    //논리적 오류가 너무 많잔아???
    
    while(point.first<n && point.second<n){
        point = Q.front();
        Q.pop();
        while(!Q.empty()){
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
                point=make_pair(n,n);
            }
    }
    printf("%d",&cnt);
    return 0;
}


7                                                                                      
1100010                                                                                
0110110                                                                                
0100000                                                                                
0001011                                                                                
1101100                                                                                
1000100                                                                                
1010100