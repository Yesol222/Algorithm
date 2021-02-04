#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n,k,i;
    queue<int> Q;
    scanf("%d %d", &n,&k);
    for(i=1;i<=n;i++){
        Q.push(i);
    }
    while(!Q.empty()){
        for(i=1;i<k;i++){
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
        if(Q.size()==1){
            printf("%d",Q.front());
            Q.pop();
        } 
    }
}
// int main(){
//     int i, n, k, x, cnt=0;
//     scanf("%d %d",&n,&k);
//     vector<int> p(n);
//     for(i=0;i<n;i++){
//         scanf("%d",&p[i]);
//     }
//     queue<int> Q;
//     while(!Q.empty()){
//         if(Q.size()==1) printf("%d",&Q.front());
//         if(cnt==k){
//             Q.pop();
//             cnt=0;
//         }
//         else{
//             x=Q.front();
//             Q.pop();
//             Q.push(x);
//             cnt++;
//         }
//     }
    
// }