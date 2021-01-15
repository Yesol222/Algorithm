#include <stdio.h>

using namespace std;
int cnt[50001];
int main(){
 freopen("input.txt","rt",stdin);
 //밑의 코드는 시간 복잡도가 너무나 높음!!!! 
//  int a;
//  char b[100]; //output
 
//  scanf("%d",&a);
//  for(int i=0; i<=a; i++){
//      for(int j=1; j<i; j++){
//          if(i%j==0) b[i]++;
//      }
//  }
//  printf("%s",b);

//j가 j+1로 증가해야함. i의 배수만이 i를 약수로 가질 것이기 때문에.

int a;
scanf("%d",&a);

for(int i=1;i<=a;i++){
    for(int j=i;j<=a;j+i){
        cnt[j]++;
    }
}

for(int i=0;i<=a;i++){
    printf("%d",a[i]);
}

 return 0;
}