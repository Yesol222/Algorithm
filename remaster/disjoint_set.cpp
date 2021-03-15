#include <stdio.h>
#include <algorithm>

using namespace std;
int n;
int unf[30];

int Find(int a){
    if(unf[a]==a) return a;
    else return unf[a]=Find(unf[a]);
}

void Union(int x, int y){
    int a=Find(x);
    int b=Find(y);
    if(a!=b) unf[a]=b;
}
int main(){
    int a, b, m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        unf[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        Union(a,b);
    }

    scanf("%d %d", &a,&b);
    if(Find(a)==Find(b)) printf("Yes");
    else printf("No");

}