#include <stdio.h>

using namespace std;
#define MAX 2147000000
int reverse(int x){
    int num=0;    
    while(x>0){
        if(x%10!=0){ //조건 달 필요가 없는 이유 0이면 어차피 없어짐...
            num=(num*10)+(x%10);
        }
        x = x/10;
    }
}
//에라토네스의 체? cPP에선ㅇ ㅓ떻게 구현하는지 보자.
bool isPrime(int x){
    int i;
    if(x==1) return false;
    bool flag = true;
    for(i=2;i<x;i++){
        if(x%i==0){
            flag=false;
            break;
        }
    }

}

int main(){
    int N, numbers,res;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&numbers);
        res = reverse(numbers);
        if(isPrime(res)){
            printf("%d",res);
        }
    }

}