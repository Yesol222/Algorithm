#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> xi;
int i;
int Distance(int mid){
    int cnt = 1, pre = 0;
    for(i=1;i<=*xi.end();i++){
        if((xi[pre]-xi[i]) >= mid) {
            cnt++;
            pre = i;
        }
    }
    return cnt;
}
int main(){
    int n,c,tmp,lt,rt,res,mid;
    scanf("%d %d",&n,&c);
    // int *x = new int[n+1]; 포인터로 동적으로 배열잡기
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        xi.push_back(tmp);
    }
    //sort(x+1,x+n+1);
    sort(xi.begin(),xi.end());
    lt = 1;
    rt = *xi.end()-*xi.begin();
    
    while(lt<rt){
        mid=(lt+rt)/2;
        if(Distance(mid)>=c){
            res = mid;
            rt = mid-1;
        }
        else lt = mid+1;
    }
    //delete[] x; //new로 할당한 배열 메모리 해제
}