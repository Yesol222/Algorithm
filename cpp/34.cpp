#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    int N,i,j,tmp;
    vector<int> a(N);
    
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(a[j]>a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    return 0;
}