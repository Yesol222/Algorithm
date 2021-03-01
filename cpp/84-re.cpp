#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, res=-2147000000;
vector<int> T, P;

void DFS(int L, int sum){
    if(L==n+1){
        if(sum>res) res=sum;
    }
    else{
        if(L+T[L]<=n+1) DFS(L+T[L], sum+P[L]);
        DFS(L+1,sum);
    }
}
int main(){
    int a, b;
    cin>>n;
    T.push_back(0);
    P.push_back(0);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        T.push_back(a);
        P.push_back(b);
    }
    DFS(1,0);
    cout<<res;
    return 0;
}