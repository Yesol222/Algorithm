#include <stdio.h>

int makeSum(int n){
    int sum;
    for(int i=1;i<=n;i++){
        sum += i;
    }
    return sum
}
int main(){
    int N, n, ans;
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++){
        scanf("%d %d",&n,&ans);
        if(ans==makeSum(n)){
            printf("YES\n");
        }
        else printf("NO\n");
    }

    return 0;

}