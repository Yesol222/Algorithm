#include <stdio.h>
#include <algorithm>
// #include <stack>

using namespace std;
int stack[50];
int top=-1;
void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}

int main(){
    int n,i,k;
    scanf("%d %d",&n,&k);
    char str[20]="0123456789ABCDEF";
    while(n!=0){
        push(n/k);
        n=n%k;
    }
    while(top!=-1){
        printf("%d",str[pop()]); //16진수일 경우에는 char 변환이 필요하므로..
    }
}
// stack<int> a;
// int main(){
//     int n,i,k;
//     scanf("%d %d",&n,&k);

//     while(n!=0){
//         a.push(n%k);
//         n = n/k;
//     }

//     while(!a.empty()){
//         printf("%d",a.top());
//         a.pop();
//     }
// }