#include<bits/stdc++.h>
int dy[101];

int dfs(int n){
    if(dy[n]>0) return dy[n];
    if(n==1 || n==2) return n;
    else return dy[n]=dfs(n-2)+dfs(n-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<dfs(n);
    return 0;
}