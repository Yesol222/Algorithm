#include<stdio.h>
#include<algorithm>

using namespace std;
int n, a[11], total=0;
bool flag=false;
void dfs(int L, int sum){
    if(sum>(total/2)) return;
    if(flag==true) return;
    if(L==n+1){
        if(sum==(total-sum)){
            flag=true; //여기서 리턴 안하는 이유, 나머지 가지들이 return 하지 않기 떄문에
        }
    }
    else{
        dfs(L+1, sum+a[L]);
        dfs(L+1, sum);
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
    }
    dfs(1,0);
    if(flag) printf("YES");
    return 0;
}

//내가 짠 코드 -> 모든 가지수를 다 봐야함, 돌다가 참이 나와도 나머지를 다 돌기 때문에 낭비가 큼
//조건에 맞으면 return 하게 만들어야함.
//sum 자체가 dfs에 넘겨지면 빠르다!! 가지를 도는 것과 같다!!!

// int n, ch[100];
// vector<int> sub(n+1);
// void dfs(L){
//     int sum1=0, sum2=0;
//     if(L==n+1){
//         for(int i=1;i<=n;i++){
//             if(ch[i]==1) sum1+=sub[i];
//             else sum2+=sub[i];
//         }
//         if(sum1==sum2){
//             printf("YES");
//         }
//     }
//     else{
//         ch[L]=1;
//         dfs(L+1);
//         ch[L]=0;
//         dfs(L+1);
//     }
// }
// int main(){
//     scanf("%d",&n);

//     for(int i=1;i<=n;i++){
//         scanf("%d",&sub[i]);
//     }

//     return 0;
// }