#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int unf[1001];

int Find1(int v){
    if(v==unf[v]) return v;
    else return Find(unf[v]); //index 와 value가 같지 않는다면 값으로 Find 함수를 호출.
}

int Find2(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]); // 메모이제이션
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}
int main(){
    int n,m,a,b;
    cint>>n>>m;
    for(int i=1;i<=n;i++){
        unf[i]=i;
    }
    for(int i=1;i<=m;i++){ //숫자 쌍의 정보를 읽어들인다.
        cin>>a>>b;
        Union(a,b);
    }
    cin>>a>>b;
    a=Find2(a);
    b=Find2(b);
    if(a==b) cout<<"YES";
    else cout<<"NO";
    return 0;
}