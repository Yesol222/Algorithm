#include <stdio.h>

int main(){

    int N, i, b, cnt=0;
    scanf("%d",&N);

    int a[N];
    for(i=1;i<=N;i++){
      scanf("%d",&b);
      a[i] = b;
    }

    for(i=1;a[i]=='\0';i++){
        for(int j=i+1;j<=N;j++){
            if(a[i]<a[j]) break;
            else(j==N){
                cnt++;
            }
        }
    }
    return 0;
}

int another(){
    int N, i, b, cnt=0;
    scanf("%d",&N);

    int a[N];
    for(i=1;i<=N;i++){
      scanf("%d",&b);
      a[i] = b;
    }

    int max = a[N];

    for(i=N-1;i>0;i--){
        if(a[i]>max){
            max = a[i];
            cnt++;
        }
    }
    
}