#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int a[2001];

int main(){
    int n,i,k,p=0,cnt, tot=0;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot +=1;
    }
    scanf("%d",&k);
    if(k>=tot) {
        printf("-1");
        return 0;
    }
    while(1){
        pos++;
        if(p>n) p=1;
        if(a[p]==0) continue;
        a[p]--;
        cnt++;
        if(cnt==k) break;
    }
    while(1){
        p++;
        if(p>n) p=1;
        if(a[p]!=0) break;
    }
    printf("%d",&p);
    return 0;
}

// 정전이 난 후에 남은 작업 출력하는 것이 핵심임 ㅜㅜ
// 그 바로 다음 작업이 아니라 cnt 이후에 루프를 다시 돌면서 남은 작업을 찾아야 함.
// int main(){
//     int n,i,k,pos=0,cnt,bp=0;
//     scanf("%d",&n);
//     vector<int> process(n+1);
//     for(i=1;i<=n;i++){
//         scanf("%d",&process[i]);
//     }
//     scanf("%d",&k);
//     while(1){
//         pos++;
//         if(pos>n) pos=1;
//         if(cnt>n) cnt=1;
//         if(process[pos]>0){
//             cnt++;
//             process[pos]-=1;
//             bp++;
//         }
//         if(bp==k) break;
//     }

//     if(process[cnt]==0){
//         printf("-1");
//     }
//     else printf("%d",&cnt);
//      return 0;
// }