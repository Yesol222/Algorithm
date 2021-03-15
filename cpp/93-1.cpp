 #include <stdio.h>
 #include <vector>
 #include <algorithm>

 using namespace std;

int dy[30];
int dx[30];
//top-down
int dfs(int L){
    if(L==1 || L==2) return L;
    if(dx[L]>0) return dx[L];
    else if(dx[L]==0) dx[L]=dfs(L-1)+dfs(L-2);
}
 int main(){
     int n;
     scanf("%d",&n);

    //bottom-up
     dy[1]=1;
     dy[2]=2;

     for(int i=3;i<=n;i++){
         dy[i]=dy[i-1]+dy[i-2];
     }

    //top-down
    dfs(n);
     printf("%d",&dy[n]);
 }