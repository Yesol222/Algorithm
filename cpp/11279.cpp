#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    int n, x;
    priority_queue<int> pQ;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x==0){
            if(pQ.empty()) {
                printf("0\n");
                continue;
            }
            printf("%d\n",pQ.top());
            pQ.pop();
        }
        pQ.push(x);
    }
}