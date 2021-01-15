#include <stdio.h>
#include <stack>

using namespace std;

void Bi(int x){
    if(x==0) return;
    else{
        Bi(x/2);
        printf("%d", x%2);
    }
}
int main(){
    int n;
    scanf("%d",&n);

    Bi(n);
    return 0;
}