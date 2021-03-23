#include <iostream>
#include <vector>
#include <algorithm>
//coin algorithm , knapsack
using namespace std;

int main(){
    int n, m;
    cin>>n;
    vector<int> coin(n);
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    vector<int> dy(m+1,1000);
    dy[0]=0;

    for(int i=0;i<n;i++){
        for(int j=coin[i];j<=m;j++){
            dy[j] = min(dy[j],dy[j-coin[i]]+1);
        }
    }
    cout<<dy[m];
    
    return 0;
}