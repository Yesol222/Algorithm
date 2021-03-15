#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//(0.0)->(n,n) 최소비용
// 오른쪽 혹은 아래쪽으로 가야만 최단거리로 도착 가능
//bottom up
int arr[21][21], dy[21][21];

int main(){
    int n, cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    dy[0][0]=arr[0][0];
    //첫 루트의 다이나믹 값을 미리 구해 둔다.
    for(int i=0;i<n;i++){
        dy[0][i] = dy[0][i-1]+arr[0][i];
        dy[i][0] = dy[i-1][0]+arr[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dy[i][j] = min(dy[i-1][j],dy[i][j-1]);
        }
    }

    cout << dy[n-1][n-1];

    return 0;
}