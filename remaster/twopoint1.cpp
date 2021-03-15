#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m, i, px=0, py=0, pz=0;
    vector<int> a(n), b(n), c(n);
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end());
    scanf("%d",&m);
    for(i=0;i<=m;i++){
        scanf("%d",&b[i]);
    }
    sort(b.begin(),b.end());

    while(p1<n && p2<m){
        if(a[p1]<b[p2]){
            p1++;
        }
        else if(a[p1]==b[p2]){
            c[p3++]=a[p1];
            p1++;
            p2++;
        }
        else if(a[p1]>b[p2]){
            p2++;
        }
    }
    return 0;
}