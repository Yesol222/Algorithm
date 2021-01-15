#include <stdio.h>
#include <algorithm>
#include <math>

using namespace std;
//이분탐색 -> 정렬된 배열 내에서 인접한 답의 범위를 좁혀 나가는 것
int Count(int len, int x[]){
    int i, cnt=1; pos=x[1];
    for(i=2;i<=2;i++){
        if(x[i]-pos>=len){
            cnt++;
            pos=x[i];
        }
    }
    return cnt;
}
int main() {
    int m,i,lt=1,rt,mid,res;
    scanf("%d %d",&n,&m);
    int *x = new int[n+1];
    for(i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    sort(x+1,x+n+1); //sort 범위 산정 해줘야함.
    rt=x[n];
    while(lt<=rt){
        mid=(lt+rt)/2;
        if(Count(mid,x)>=m){
            res=mid;
            lt=mid+1
        }
        else = rt=mid-1;
    }
    printf("%d\n",res);
    delete[] x; //메모리 해제
    return 0;
}