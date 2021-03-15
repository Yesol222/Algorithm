#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Street{
    int start;
    int end;
    int time;
    Street(int a, int b, int c){
        start=a;
        end=b;
        time=c;
    }
    bool operator<(const Street &s)const{
        return time<s.time;
    }
};
int main(){
    int n, m, x, a, b, c,res=0;
    cin>>n>>m>>x;
    vector<int> route[n+1];
    priority_queue<Street> Q;

    vector<pair<int, int> > map[n+1];

    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b,c));
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n ;j++){
            route[i][j]=2147000000;
        }
    }
    //나의 코드 -> for loop 두번에 경로를 이차원 배열에 저장을 했으니 공간 낭비가 심하기도 하고 너무나 복잡하다..
    //잘 정리하면 좋을 것 같긴 한데 일단 패스 ㅜㅜ 햄수 만들어서 풀어보자.
    for(int i=1;i<=n;i++){
        for(int j=0;j<map[i].size();j++){
            Q.push(Street(i,map[i][j].first,map[i][j].second));
            while(!Q.empty()){
                Street tmp = Q.top();
                Q.pop();
                int pre = tmp.start;
                int now = tmp.end;
                int cost = tmp.time;
                if(route[pre][now]<cost) continue;
                else{
                    route[pre][now] = cost;

                    for(int i=0;i<map[now].size();i++){
                        int next = map[now][i].first;
                        int nextTime = cost + map[now][i].second;
                        if(route[i][next]>nextTime){
                            route[i][next]=nextTime;
                            Q.push(Street(now,next,nextTime));
                        }
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        if(res<route[i][x]+route[x][i]) res=route[i][x]+route[x][i];
    }
    
    cout<<res;
    return 0;
}