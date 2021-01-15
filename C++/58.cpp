#include <stdio.h>

using namespace std;

void D(int v){
    if(v>7) return;
    else{
        //전위순회 print 위치
        printf("%d", v);
        D(v*2);
        //중위순회 print 위치
        D(v*2+1);
        //후위순회 print 위치
    }
}

int main(){
    D(1);
    return 0;
}