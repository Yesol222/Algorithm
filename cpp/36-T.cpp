#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,i,j,pos;
    scanf("%d",&n);
    vector<int> is(n+1), os(n+1);
    for(i=1;i<=n;i++){
        scanf("%d",&is[i]);
    }
    for(i=n;i>=1;i--){
        pos=i;
        for(j=1;j<=is[i];j++){ //자리수 "만큼" 자기보다 큰 숫자를 땡기는거임
            os[pos]=os[pos+1]; //만약 5이고 값이 2이면 두 번 앞으로 땡겨서 자리를 찾는 방식.
            pos++;
        }
        os[pos]=i;
    }
    for(i=1;i<=n;i++){
        printf("%d",os[i]);
    }
}
