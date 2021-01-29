#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int a[51][51];
int main(){
    int h,w,n,m,i,j,k,s,sum=0,max=-2147000000;
    scanf("%d %d",&h,&w);

    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&n,&m);
    for(i=1;i<=h-n+1;i++){
        for(j=1;j<=w-m+1;j++){
            sum=0;
            for(k=i;k<i+n;k++){
                for(s=j;s<j+m;j++){
                    sum+=a[k][s];
                }
            }
        }
    }
}