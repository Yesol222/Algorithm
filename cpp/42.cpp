#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n,m,i,lt=0,rt,mid,tmp;
    scanf("%d",&n);
    rt = n-1;
    // vector<int> a(n);
    // for(int enum : a){
    //     scanf("%d", enum);
    // }
    vector<int> a;
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    scanf("%d",&m);

    while(lt<=rt){
        mid = (lt+rt)/2;
        if(m>a[mid]){
            lt=mid+1;
        }
        else if(m<a[mid]){
            rt=mid-1;
        }
        else break;
    }
    return 0;
}