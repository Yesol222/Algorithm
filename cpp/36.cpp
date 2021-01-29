#include <stdio.h>

using namespace std;

int main(){
    int a[100],n,i,j,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
    }

    while(j>=0 && a[j]>tmp){
	    a[j+1]=a[j];
	    j--;
    }
    a[j+1]=tmp;

    for(i=1;i<n;i++){
        tmp = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j]>tmp){
                a[j+1] = a[j]; 
            }
            else break;
        }
        a[j+1] = tmp;
    }
}