#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int res;
int DFS(int x){
    if(x==1) return x;
    else{
        x=x-1;
        res=res*x;
        DFS(x);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    res=x;
    printf("%d",DFS(n));
    return 0;
}