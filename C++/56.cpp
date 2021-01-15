#include<stdio.h>
#include<stack>

using namespace std;

void recur(int x){
    if(x==0) return;
    else{
        recur(x-1);
        printf("%d ",x);
    } //조건에 따라 return 해주어야 하므로, if/else로 짜는 연습을 한다!
    // while(x>0){
    //     printf("%d ", x);
    //     recur(x-1);
    // }
}
int main(){
    int n;
    scanf("%d",&n);
    recur(n);

    return 0;
}