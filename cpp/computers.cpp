#include <string>
#include <vector>
#include <queue>
using namespace std;

//exactly the same as 87.cpp

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};
queue<Loc> Q;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(computers[i][j]==1){
                Q.push(Loc(i,j));
                computers[i][j]=0;
                while(!Q.empty()){
                    Loc tmp = Q.front();
                    Q.pop();
                    for(int m=0;m<8;m++){
                        int xx = tmp.x+dx[m];
                        int yy = tmp.y+dy[m];
                        if(xx>=0 && xx<n&& yy>=0 && yy<n && computers[xx][yy]==1){
                            Q.push(Loc(xx,yy));
                            computers[xx][yy]=0;
                        }
                    }
                }
                answer++;
            }
        }
    }
    return answer;
}