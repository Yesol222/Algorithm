#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int sumOfSongs(int n,int v){
    int sum,cnt;
    for(int i=1;i<=n;i++){
        if(sum+i>v){ //이렇게 해야 조건문에서 실제로 더하지 않고 확인 가능
            cnt++;
            sum = i;
        }
        else sum=sum+i;
    }
    return cnt;
}
int main(){
    int n,m,i,lt,rt,mid,tmp,res;
    vector<int> a;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    lt = 1;
    rt = accumulate(a.begin(),a.end(),rt);
    
    while(lt<rt){
        mid = (lt+rt)/2;
        if(sumOfSongs(n,mid)<=m){
            rt = mid-1;
            res = mid;
        }
        else lt = mid+1;
    }
    return 0;
}