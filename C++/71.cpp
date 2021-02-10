#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int ch[10001], d[3]={1,-1,5};

int main(){
    int s,e,x,pos,i;
    queue<int> Q;
    scanf("%d %d",&s, &e);
    ch[s]=1;
    Q.push(s);
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(i=0;i<3;i++){
            pos=x+d[i];
            if(pos<=0 || pos>=10000) continue;
            if(pos==e){
                printf("%d",&ch[x]);
                exit(0);
            }
            if(ch[pos]==0){
                ch[pos]=ch[x]+1;
                Q.push(pos);
            }
        }
}

}

// int main(){
//     int s, e, i, x, ch[100], dis[100];
//     int l[3]={1,-1,5};
//     scanf("%d %d",&s,&e);
//     queue<int> Q;
//     Q.push(s);
//     dis[s]=0;

//     while(!Q.empty()){
//         x=Q.front();
//         Q.pop();
//         if(x==e) printf("%d",&dis[x]);
//         for(i=0;i<=3;i++){
//             if(ch[x+l[i]]==0){
//                 ch[x+l[i]]=1;
//                 dis[x+l[i]]=dis[x]+1;
//                 Q.push(x+l[i]);
//             }
//         }
//     }
    
// }