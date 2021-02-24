#include <stdio.h>
#include <queue>

using namespace std;

//Min heap
int main(){
    int a;
    priority_queue<int> pQ;
    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0){
            if(pQ.empty()) printf("-1");
            else{
                printf("%d",-pQ.top()); //pQ의 root 값을 출럭
                pQ.pop();
            }
        }
        else pQ.push(-a); //알아서 정렬을 해주는듯
    }
    return 0;
}