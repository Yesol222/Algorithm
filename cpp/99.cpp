#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m, w, v;
    cin>>n>>m;
    vector<int> dy(m+1,0);
    for(int i=0;i<n;i++){
        cin>>w>>v;
        for(int j=w;j<=m;j++){
            dy[j]=max(dy[j],dy[j-w]+v);
        }
    }
    cout<<dy[m]<<endl;
    return 0;
}