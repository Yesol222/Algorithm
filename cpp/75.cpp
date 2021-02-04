#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Data{
    int money;
    int when;
    Data(int a, int b){
        money=a;
        when=b;
    }
    bool operator<(Data &b){
        return when>b.when; //시간 기준으로 내림차순으로 정렬
    }
};
int main(){
    int n, i, j, a, b, res=0, max=-2147000000;
    vector<Data> T; //구조체. 벡터형으로 넣는다.
    priority_queue<int> pQ;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d", &a,&b);
        T.push_back(Data(a,b)); //생성자 호출!!
        if(b>max) max=b; //max는 마지막 강연할 날짜.
    }
    sort(T.begin(),T.end());
    j=0;
    for(i=max;i>=1;i--){
        for( ;j<n;j++){
            if(T[j].when<i) break;
            pQ.push(T[j].money);
        }
        if(!pQ.empty()){
            res+=pQ.top();
            pQ.pop();
        }
    }
    printf("%d",res);
    return 0;
}