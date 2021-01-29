#include <stdio.h>

using namespace std;

int digit_sum(int x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x = x/10;
    }
    return sum
}
int main(){

    int i,N=0;
    int numbers[100];
    scanf("%d",N);
    gets(numbers);

    int max = 0;
    for(i=0;i<N;i++){
        a = digit_sum(numbers[i]);
        if(max<a){
            max = a;
        }
    }
    

}