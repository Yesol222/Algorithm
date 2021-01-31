#include <stdio.h>

int digit_sum(int x){
    int tmp, sum=0;
    while(x>0){
        tmp=x%10;
        sum+=tmp;
        x=x/10;
    }
}
int main(){
    freopen("input.txt","rt",stdin);
    int n, num, i ,sum, max =-2147000000, res;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        sum = digit_sum(num);
        if(sum>max){
            max=sum;
            res=num; // res 가 최대 자리수를 갖는 그 숫자!!!!
        }
        else if(sum==max){
            if(num>res) res=num;
        }
    }
    printf("%d\n",res);
    return 0;
}