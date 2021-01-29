#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    //소수점 첫번째 자리에서 반올림! -> 실수형 자료에 0.5를 더하고 절삭하는것..
    int n, i, j,res, tmp;
    float avg[n+1];
    vector<vector<int>> map(n+2,vector<int>(n+2));

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        float sum=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
            sum += map[i][j];
        }
        avg[i] = round(sum/n);
    }

    for(int i=1;i<=n;i++){
        tmp = 0;
        for(int j=1;j<=n;j++){
            if(abs(avg[i]-map[i][j])<tmp){
                tmp = abs(avg[i]-map[i][j]);
                res = map[i][j];
            }
            else if(abs(avg[i]-map[i][j])==tmp){
                if(res<map[i][j]) res = map[i][j];
            }
        }
        printf("%d %d",avg[i],res);
    }
    return 0;
}