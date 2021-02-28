#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, i, a[100], min=2147000000, max=-2147000000;
int oper[4];


//내 코드의 문제점 -> 포루프를 돌 필요가 없음. 왜냐..? 각 dfs에서는 한번 씩만 연산하고 넘어갈 것이기 떄문

void Max(int L, int sum){
    if(L==n-1){
        if(sum>max) max=sum;
    }
    else{
        for(i=0;i<4;i++){
            if(oper[i]==0) continue;
            else{
                if(i==0){
                    oper[i]-=1;
                    Max(L+1,sum+Max(L));
                    oper[i]+=1; // dfs가 빠져나왔을 때 다시 복원 시켜주는 것 명심
                }
                else if(i==1){
                    Max(L+1,sum-Max(L));
                }
                else if(i==2){
                    Max(L+1,sum*Max(L));
                }
                else if(i==3){
                    Max(L+1,sum/Max(L));
                }
            }
        }
    }

}

void Min(int L, int sum){
    
}
int main(){
    int x, y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[i]=x;
    }
    for(i=0;i<4;i++){
        scanf("%d",&oper[i]);
    }
    //첫번째 숫자인 a[0]을 넘겨야함. 순서대로 무작정 계산하는 것임
    Max(0,0);
    Min(0,0);
    printf("%d %d",&max,&min);

 
    return 0;
}