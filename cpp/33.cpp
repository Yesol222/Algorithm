#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int N, tmp, idx, i, j, cnt=0;
    vector<int> a[N];
    
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    //값이 같다면 cnt 값을 증가시켜서 등수를 찾기.

    for(i=0;i<N-1;i++){
        idx = i;
        for(j=i+1;j<N;j++){
            if(a[j]>a[idx]) idx = j;
        }
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }
    
    for(i=0;i<N-1;i++){
        if(a[i]!=a[i+1]) cnt++;
        if(cnt==2){
            printf("%d",a[i]);
            break;
        }
    }
    return 0;
}