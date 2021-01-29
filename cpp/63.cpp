#include <stdio.h>
#include <algorithm>

using namespace std;
int map[51][51];
int main(){
    freopen("input.txt","rt",stdin);
    int n, m ,i, a, b, c;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        //map[a][b]=1;
        //map[b][a]=1; //가중치 없는 무방향 그래프
        map[a][b]=c; //가중치
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d", map[i][j]);
        }
        printf("%d",map[i][j]);
    }
    return 0;
}