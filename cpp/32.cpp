#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    int N;
    vector<int> a(N);

    for(int i=0;i<N-1;i++){
        int idx = i;
        for(int j=i+1;j<N;j++){
            if(a[j]<a[idx]) idx = j; //j 중 가장 작은 값의 인덱스 저장.  
        }
        int tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp; //swap을 j 포문 안에서 하면 비효율적이기 때문에 인덱스를 찾아서 swap.
    }
    
}