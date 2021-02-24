#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct C{
    int Day;
    int Money;
    C(int a, int b){
        Day = a;
        Money = b;
    }
    bool operator<(C &data){
        return Day > C.Day; // 내림차순 정렬 
    }
};

int main(){
    int n, m, d, max=-2147000000;
    scanf("%d",&n);
    vector<C> data;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&m,&d);
        data.push_back(C(d,m));
        if(d>max) max=d;
    }
    sort(data.begin(),data.end());
    priority_queue<int> pQ;
    
    j=0;
    for(i=max;i>=1;i--){
        for( ;j<n;j++){
            if(data[j].day<i) break;
            pQ.push(data[j].money);
        }
        if(!pQ.empty()){
            res+=pQ.top();
            pQ.pop();
        }
    }

    //priority queue에는 강연료 기준으로 최대힙이 구성된다.
    //그렇기 때문에 날짜 우선으로 데이터를 넣어준 후에 최대값을 하나씩 pop 해주면 되는 것임!!
    return 0;
}