#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, ps, pt;
    cin>>n>>m;
    vector<int> dy(m+1);

    for(int i=0;i<n;i++){
        cin>>ps>>pt;
        for(int j=m;j>=pt;j--){
            dy[j-pt] = max(dy[j],ps+dy[j-pt]);
        }
    }
    cout<<dy[m];
    return 0;
}
