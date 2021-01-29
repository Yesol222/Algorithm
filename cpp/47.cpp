#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int a[60][60]; //0~51까지 index가 생기기 위해서는 ..(?) 크기를 52로 잡아주어야 좋다
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(){
    int n,i,j,k,cnt=0, flag;
    scanf("%d",&n);
    vector<vector<int> > map(n+2, vector<int>(n+2));//2차원 벡터로 초기화
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            flag=0;
            for(k=0;k<4;k++){
                if(a[i][j]<=a[i+dx[k]][j+dy[k]]){
                    flag=1;
                    break;
                }
            }
            if(flag==0) cnt++;
        }
        printf("%d",cnt);
    }

}