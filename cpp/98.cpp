#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//top-down
int arr[21][21], dy[21][21];

int dfs(int x, int y){
    if(dy[x][y]>0) return dy[x][y];
    if(x==0 && y==0) return arr[0][0];
    else{
        if(y==0) return dy[x][y] = dfs(x-1,y)+arr[x][y];
        else if(x==0) return dy[x][y] = dfs(x,y-1)+arr[x][y];
        else return dy[x][y] = min(dfs(x-1,y),dfs(x,y-1)) + arr[x][y];
    }
}
int main(){
    int n, cnt =0;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<dfs(n-1,n-1);
    return 0;
}