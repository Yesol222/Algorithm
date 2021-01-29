#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a[101],n,i,j,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //bubble sorting 으로 음수는 왼쪽, 양수는 오른쪽으로. 양수는 순서 변화 없게
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>0 && a[j+1]<0){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    return 0;
}