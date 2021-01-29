#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int S,N,i,j,tmp,pos;
    vector<int> C(S);
    
    for(i=0;i<N;i++){
        scanf("%d",tmp);
        pos=-1;
        for(j=S-1;i>=0;j--){
            if(C[j]==tmp){
                pos=j;
            }
        }
        if(pos==-1){
            for(j=S-1;j>0;j--){
                C[j]=C[j-1];
            }
        }
        else{
            for(j=0;j<pos;j++){
                C[j+1]=C[j];
            }
        }
        C[0] = tmp;
    }
    return 0;
}